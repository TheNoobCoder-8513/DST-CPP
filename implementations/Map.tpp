#include "../headers/Map.hpp"

#include <string>
#include <sstream>
#include <exception>

template <typename K, typename V>
Map<K, V>::Map() = default;

template <typename K, typename V>
Map<K, V>::Map(const std::initializer_list<MapElem<K, V>>& ls)
{
    m_map.reserve(static_cast<int>(ls.size()));
    for (const auto& elem: ls)
        addPair(elem.m_key, elem.m_val);
}

template <typename K, typename V>
bool Map<K, V>::isEmpty() const
{
    return m_map.isEmpty();
}

template <typename K, typename V>
int Map<K, V>::length() const
{
    return m_map.length();
}

template <typename K, typename V>
bool Map<K, V>::hasKey(const K& key) const
{
    for (int index {}; index < m_map.length(); ++index)
    {
        if (m_map.at(index).m_key == key) return true;
    }
    return false;
}

template <typename K, typename V>
const K& Map<K, V>::addPair(const K& key, const V& val)
{
    if (hasKey(key))
        throw std::logic_error {"Logic Error: Key already present"};
    m_map.addLast(MapElem<K, V> {key, val});
    return m_map.at(m_map.length() - 1).m_key;
}

template <typename K, typename V>
MapElem<K, V> Map<K, V>::removePair(const K& key)
{
    for (int index {}; index < m_map.length(); ++index)
    {
        if (m_map.at(index).m_key == key)
        {
            return m_map.removeFrom(index);
        }
    }
    throw std::logic_error {"Logic Error: Key not present"};
}

template <typename K, typename V>
const V& Map<K, V>::update(const K& key, const V& val)
{
    for (int index {}; index < m_map.length(); ++index)
    {
        if (m_map.at(index).m_key == key)
        {
            m_map[index].m_val = val;
            return m_map.at(index).m_val;
        }
    }
    addPair(key, val);
    return m_map.at(m_map.length() - 1).m_val;
}

template <typename K, typename V>
const V& Map<K, V>::valOf(const K& key) const
{
    for (int index {}; index < m_map.length(); ++index)
    {
        if (m_map.at(index).m_key == key)
        {
            return m_map.at(index).m_val;
        }
    }
    throw std::logic_error {"Logic Error: Key not present"};
}

template <typename K, typename V>
Vector<K> Map<K, V>::getKeys() const
{
    Vector<K> keys(m_map.length());
    for (int index {}; index < m_map.length(); ++index)
    {
        keys.set(index, m_map.at(index).m_key);
    }
    return keys;
}

template <typename K, typename V>
Vector<V> Map<K, V>::getVals() const
{
    Vector<V> vals(m_map.length());
    for (int index {}; index < m_map.length(); ++index)
    {
        vals.set(index, m_map.at(index).m_val);
    }
    return vals;
}

template <typename K, typename V>
std::string Map<K, V>::toStr() const
{
    if (!m_map.length()) return "[]";
    std::ostringstream stream {};
    stream << '[';
    for (int index {}; index < m_map.length(); ++index)
    {
        if (index) stream << ", ";
        stream << m_map.at(index);
    }
    stream << ']';
    return stream.str();
}

template <typename K, typename V>
const V& Map<K, V>::operator[](const K& key) const
{
    for (int index {}; index < length(); ++index)
    {
        if (m_map[index].m_key == key) return m_map[index].m_val;
    }
    throw std::logic_error {"Logic Error: Key not present"};
}

template <typename K, typename V>
V& Map<K, V>::operator[](const K& key)
{
    for (int index {}; index < length(); ++index)
    {
        if (m_map[index].m_key == key) return m_map[index].m_val;
    }
    addPair(key, V {});
    return m_map[length() - 1].m_val;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& stream, const Map<K, V>& map)
{
    stream << map.toStr();
    return stream;
}