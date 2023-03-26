#include "hash_table.h"

#include <algorithm>
#include <utility>

template <typename KeyT, typename ValT, typename HashF>
inline typename HashF::value_type
HashTable<KeyT, ValT, HashF>::hash(KeyT const& key) const noexcept
{
    return HashF()(key) % buck_sz;
}

template <typename KeyT, typename ValT, typename HashF>
inline auto HashTable<KeyT, ValT, HashF>::find(typename HashF::value_type& hash,
                                               KeyT const& key)
{
    auto& bucket = storage_[hash];
    auto it = std::find_if(bucket.begin(), bucket.end(),
                           [&key](Entry& entry) { return entry.key == key; });
    return it;
}

template <typename KeyT, typename ValT, typename HashF>
inline double HashTable<KeyT, ValT, HashF>::load_factor() const noexcept
{
    return static_cast<double>(bucks_occupied_) / buck_sz;
}

template <typename KeyT, typename ValT, typename HashF>
inline std::size_t HashTable<KeyT, ValT, HashF>::bucket_size() const noexcept
{
    return buck_sz;
}

template <typename KeyT, typename ValT, typename HashF>
inline std::size_t HashTable<KeyT, ValT, HashF>::bucks_occupied() const noexcept
{
    return bucks_occupied_;
}

template <typename KeyT, typename ValT, typename HashF>
template <bool shrink>
inline void HashTable<KeyT, ValT, HashF>::rehash() noexcept
{
    std::vector<std::list<Entry>> new_storage;
    if constexpr (shrink)
        buck_sz /= ALPHA_FACTOR;
    else
        buck_sz *= ALPHA_FACTOR;
    new_storage.resize(buck_sz, {});
    bucks_occupied_ = 0;

    for (auto& src_bucket : storage_)
    {
        auto it = src_bucket.begin();
        while (it != src_bucket.end())
        {
            auto next_it{std::next(it)};
            auto el_hash{HashF{}(it->key) % buck_sz};
            auto& dest_bucket{new_storage[el_hash]};

            if (dest_bucket.empty())
                ++bucks_occupied_;
            dest_bucket.emplace_back(std::move(*it));

            it = next_it;
        }
    }

    storage_ = std::move(new_storage);
}

template <typename KeyT, typename ValT, typename HashF>
inline HashTable<KeyT, ValT, HashF>::HashTable() : size_(0), storage_(buck_sz)
{
}

template <typename KeyT, typename ValT, typename HashF>
inline void HashTable<KeyT, ValT, HashF>::add(Entry&& entry) noexcept
{
    ++size_;
    auto buck_id = hash(entry.key);
    auto& bucket = storage_[buck_id];
    if (bucket.empty())
    {
        ++bucks_occupied_;
        bucket.emplace_back(std::move(entry));
    }
    else
    {
        auto it = find(buck_id, entry.key);
        if (it == bucket.end())
            bucket.emplace_back(std::move(entry));
        else
            it->val = std::move(entry.val);
    }

    auto alpha = load_factor();
    if (alpha > ALPHA_MAX)
        rehash<false>();
    else if (alpha < ALPHA_MIN && buck_sz > MIN_BUCKET_SIZE)
        rehash<true>();
}

template <typename KeyT, typename ValT, typename HashF>
inline void HashTable<KeyT, ValT, HashF>::add(KeyT const& key,
                                              ValT const& val) noexcept
{
    add(Entry{key, val});
}

template <typename KeyT, typename ValT, typename HashF>
inline void HashTable<KeyT, ValT, HashF>::emplace(KeyT const& key,
                                                  ValT&& val) noexcept
{
    add(Entry{key, std::move(val)});
}

template <typename KeyT, typename ValT, typename HashF>
inline ValT HashTable<KeyT, ValT, HashF>::get(KeyT const& key) const
{
    auto buck_id{hash(key)};
    auto& bucket{storage_[buck_id]};

    auto it = find(buck_id, key);
    if (it == bucket.end())
        throw std::runtime_error("Key not found");
    return it->val;
}

template <typename KeyT, typename ValT, typename HashF>
inline ValT& HashTable<KeyT, ValT, HashF>::get(KeyT const& key)
{
    auto buck_id{hash(key)};
    auto& bucket{storage_[buck_id]};

    auto it = find(buck_id, key);
    if (it == bucket.end())
        throw std::runtime_error("Key not found");
    return it->val;
}

template <typename KeyT, typename ValT, typename HashF>
inline void HashTable<KeyT, ValT, HashF>::remove(KeyT const& key) noexcept
{
    auto bucket_id{hash(key)};
    auto& bucket = storage_[bucket_id];
    if (bucket.empty())
        return;

    bucket.erase(
        std::remove_if(bucket.begin(), bucket.end(),
                       [&key](Entry& entry) { return entry.key == key; }),
        bucket.end());

    if (bucket.empty())
        --bucks_occupied_;
}

template <typename KeyT, typename ValT, typename HashF>
inline std::size_t HashTable<KeyT, ValT, HashF>::size() const noexcept
{
    return size_;
}
