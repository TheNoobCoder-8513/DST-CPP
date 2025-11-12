#include "../headers/Map.hpp"

#include <string>
#include <sstream>
#include <exception>

template <typename K, typename V>
bool Map<K, V>::isEmpty() const
{
    return map.isEmpty();
}

template <typename K, typename V>
bool Map<K, V>::hasKey(const K& key) const
{
    for (int index {}; index < map.length(); ++index)
    {
        if (map.at(index).key == key) return true;
    }
    return false;
}

template <typename K, typename V>
const V& Map<K, V>::addPair(const K& key, const V& val)
{
    if (hasKey(key))
        throw std::logic_error {"Logic Error: Key already present"};
    map.addLast(MapElem {key, val});
    return map.at(map.length() - 1).val;
}

template <typename K, typename V>
V Map<K, V>::removePair(const K& key)
{
    for (int index {}; index < map.length(); ++index)
    {
        if (map.at(index).key == key)
        {
            return map.removeFrom(index).val;
        }
    }
    throw std::logic_error {"Logic Error: Key not present"};
}

template <typename K, typename V>
const V& Map<K, V>::update(const K& key, const V& val)
{
    for (int index {}; index < map.length(); ++index)
    {
        if (map.at(index).key == key)
        {
            map[index].val = val;
            return map.at(index).val;
        }
    }
    addPair(key, val);
    return map.at(map.length() - 1).val;
}

template <typename K, typename V>
V Map<K, V>::valOf(const K& key) const
{
    for (int index {}; index < map.length(); ++index)
    {
        if (map.at(index).key == key)
        {
            return map.at(index).val;
        }
    }
    throw std::logic_error {"Logic Error: Key not present"};
}

template <typename K, typename V>
Vector<K> Map<K, V>::getKeys() const
{
    Vector<K> keys(map.length() - 1);
    for (int index {}; index < map.length(); ++index)
    {
        keys.set(index, map.at(index).key);
    }
    return keys;
}

template <typename K, typename V>
Vector<K> Map<K, V>::getVals() const
{
    Vector<K> keys(map.length() - 1);
    for (int index {}; index < map.length(); ++index)
    {
        keys.set(index, map.at(index).val);
    }
    return keys;
}

template <typename K, typename V>
std::string Map<K, V>::toStr() const
{
    if (!map.length()) return "[]";
    std::ostringstream stream {};
    stream << '[';
    for (int index {}; index < map.length(); ++index)
    {
        if (index) stream << ", ";
        stream << '{';
        stream << map.at(index).key << ": " << map.at(index).val;
        stream << '}';
    }
    stream << ']';
    return stream.str();
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& stream, const Map<K, V>& map)
{
    stream << map.toStr();
    return stream;
}