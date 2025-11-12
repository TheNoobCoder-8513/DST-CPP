#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include <exception>

#include "DoublyLinkedListNode.hpp"

template <typename T>
class DoublyList;

template <typename T>
std::ostream& operator<<(std::ostream&, const DoublyList<T>&);

template <typename T>
class DoublyList
{
private:
    DoublyNode<T>* m_head {};
    DoublyNode<T>* m_tail {};
    int m_length {};

public:
    DoublyList();

    DoublyList(const std::initializer_list<T>& ls);

    DoublyList(const DoublyList& ls);

    DoublyList(DoublyList&& ls);

    DoublyList<T>& operator=(const DoublyList<T>& ls);

    DoublyList<T>& operator=(DoublyList<T>&& ls);

    ~DoublyList();

public:
    
    int length() const;

    bool isEmpty() const;

    const T& front() const;

    const T& back() const;

    const T& atIndex(int pos) const;
    
    const T& addFirst(const T& elem);

    const T& addLast(const T& elem);

    const T& insertAt(const T& elem, int pos);

    T removeFrom(int pos);
    
    T removeFirst();

    T removeLast();

    void clear();

    DoublyList& concat(const DoublyList& ls);

    DoublyList& concat(DoublyList&& ls);
    
    std::string toStr() const;

public:
    friend std::ostream& operator<<<T>(std::ostream& stream, const DoublyList<T>& list);
};

#include "../implementations/DoublyLinkedList.tpp"

#endif
