#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <memory>
#include <exception>

#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

template <typename T, template <typename> class Impl>
class List;

template <typename T, template <typename> class Impl>
std::ostream& operator<<(std::ostream& os, const List<T, Impl>& l);


template <typename T, template <typename> class Impl = DoublyList>
class List
{
private:
    Impl<T> list {};

public:
    List();

    List(std::initializer_list<T> elems);

public:
    int length() const;

    bool isEmpty() const;

    const T& front() const;

    const T& back() const;

    const T& atIndex(int pos) const;

    const T& addFirst(const T& elem);

    const T& addLast(const T& elem);

    T removeFirst();

    T removeLast();

    const T& insertAt(const T& elem, int pos);

    T removeFrom(int pos);

    void clear();

    List<T, Impl>& concat(const List<T, Impl>& ls);

    List<T, Impl>& concat(List<T, Impl>&& ls);
    
    std::string toStr() const;

public:
    friend std::ostream& operator<<<>(std::ostream& os, const List& l);
};

#include "../implementations/List.tpp"

#endif