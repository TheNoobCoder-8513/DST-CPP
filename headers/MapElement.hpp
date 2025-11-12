#ifndef MAP_ELEMENT_HPP
#define MAP_ELEMENT_HPP

template <typename K, typename V>
struct MapElem
{
public:
    K m_key {};
    V m_val {};

public:
    MapElem() = default;

    MapElem(const K& key, const V& val)
        : m_key {key}, m_val {val}
    {}

public:
    friend std::ostream& operator<<(std::ostream& stream, const MapElem& elem)
    {
        stream << '{' << elem.m_key << ": " << elem.m_val << '}';
        return stream;
    }
};

#endif