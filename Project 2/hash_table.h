#pragma once

#include "hash.h"

#include <list>
#include <vector>

template <typename KeyT, typename ValT, typename HashF = HashFunction<KeyT>>
class HashTable
{
    struct Entry
    {
        KeyT key;
        ValT val;
    };

public:
    HashTable();

    void add(KeyT const& key, ValT const& val) noexcept;
    void emplace(KeyT const& key, ValT&& val) noexcept;

    ValT get(KeyT const& key) const;
    ValT& get(KeyT const& key);

    void remove(KeyT const &key) noexcept;

    std::size_t size() const noexcept;

    // TODO: move back into private.
    double load_factor() const noexcept;
    std::size_t bucket_size() const noexcept;
    std::size_t bucks_occupied() const noexcept;
    typename HashF::value_type hash(KeyT const &key) const noexcept;

private:
    static constexpr double ALPHA_MIN = 0.6;
    static constexpr double ALPHA_FACTOR = 1.5;
    static constexpr double ALPHA_MAX = 0.75;
    static constexpr std::size_t MIN_BUCKET_SIZE = 8;

    std::size_t bucks_occupied_ = 0;
    std::size_t buck_sz = MIN_BUCKET_SIZE;

    std::size_t size_ = 0;
    std::vector <std::list <Entry>> storage_;

    void add(Entry&& entry) noexcept;

    auto find(typename HashF::value_type& hash, KeyT const &key);

    template <bool shrink = false>
    void rehash() noexcept;
};

#include "private/hash_table_impl.h"
