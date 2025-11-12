#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <initializer_list>

#include "SinglyLinkedListNode.hpp"

template <typename T> 
class SinglyList;


template <typename T>
std::ostream& operator<<(std::ostream& stream, const SinglyList<T>& list);


template <typename T>
class SinglyList
{
private:
    SinglyNode<T>* m_head {};
    SinglyNode<T>* m_tail {};
    int m_length {};

public:
    SinglyList();

    SinglyList(const std::initializer_list<T>& ls);

    SinglyList(const SinglyList& ls);

    SinglyList(SinglyList&& ls);

    SinglyList<T>& operator=(const SinglyList<T>& ls);

    SinglyList<T>& operator=(SinglyList<T>&& ls);

    ~SinglyList();

public:
    
    int length() const;

    bool isEmpty() const;

    const T& front() const;

    const T& back() const;

    const T& atIndex(int pos) const;

    const T& insertAtIndex(const T& elem, int pos);

    T removeFromIndex(int pos);

    const T& addFirst(const T& elem);

    const T& addLast(const T& elem);
    
    T removeFirst();

    T removeLast();

    void clear();

    SinglyList& concat(const SinglyList& ls);

    SinglyList& concat(SinglyList&& ls);
    
    std::string toStr() const;

public:
    friend std::ostream& operator<<<T>(std::ostream& stream, const SinglyList<T>& list);
};


#include "../implementations/SinglyLinkedList.tpp"

#endif
