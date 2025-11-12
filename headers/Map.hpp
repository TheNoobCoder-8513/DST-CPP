#ifndef MAP_HPP
#define MAP_HPP

#include "Vector.hpp"
#include "MapElement.hpp"

#include <string>
#include <sstream>
#include <exception>

template <typename K, typename V>
class Map
{
private:
    Vector<MapElem<K, V>> map {};

public:
    bool isEmpty() const;

    bool hasKey(const K& key) const;

    const V& addPair(const K& key, const V& val);

    V removePair(const K& key);

    const V& update(const K& key, const V& val);

    const V& valOf(const K& key) const;

    Vector<K> getKeys() const;

    Vector<K> getVals() const;

    std::string toStr() const;

    friend std::ostream& operator<<(std::ostream& stream, const Map& map)
    {
        stream << map.toStr();
        return stream;
    }
};

#endif