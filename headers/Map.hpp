#ifndef MAP_HPP
#define MAP_HPP

#include "Vector.hpp"
#include "MapElement.hpp"

#include <string>
#include <sstream>
#include <exception>
#include <initializer_list>

template <typename K, typename V>
class Map
{
private:
    Vector<MapElem<K, V>> m_map {};

public:
    Map();
    
    Map(const std::initializer_list<MapElem<K, V>>& ls);

public:
    bool isEmpty() const;

    int length() const;

    bool hasKey(const K& key) const;

    const K& addPair(const K& key, const V& val);

    MapElem<K, V> removePair(const K& key);

    const V& update(const K& key, const V& val);

    const V& valOf(const K& key) const;

    Vector<K> getKeys() const;

    Vector<V> getVals() const;

    std::string toStr() const;

    friend std::ostream& operator<<(std::ostream& stream, const Map& m_map)
    {
        stream << m_map.toStr();
        return stream;
    }
};

#include "../implementations/Map.tpp"

#endif