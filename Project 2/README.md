# Hash table

Implement a [hash table](https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm) as a template class:

```cpp
template <typename KeyT, typename ValT, typename HashF>
class HashTable
{
public:
    void add(KeyT const &key, ValT const &val);
    void emplace(KeyT const &key, ValT const &val);

    ValT get(KeyT const &key) const;
    ValT& get(KeyT const &key);

    void delete(KeyT const &key);
};
```