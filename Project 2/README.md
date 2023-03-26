# Hash table

Implement a [hash table](https://en.wikipedia.org/wiki/Hash_table) as a template class:

```cpp
template <typename KeyT, typename ValT, typename HashF>
class HashTable
{
public:
    void add(KeyT const &key, ValT const &val);
    void emplace(KeyT const &key, ValT const &val);

    ValT get(KeyT const &key) const;
    ValT& get(KeyT const &key);

    void remove(KeyT const &key);
};
```