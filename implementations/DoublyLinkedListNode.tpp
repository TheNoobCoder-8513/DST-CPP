#include "../headers/DoublyLinkedListNode.hpp"

template <typename T>
DoublyNode<T>::DoublyNode(T elem, DoublyNode* prev, DoublyNode* next)
    : m_elem {elem}, m_prev {prev}, m_next {next}
{}

template <typename T>
const T& DoublyNode<T>::getElem() const 
{
    return m_elem;
}

template <typename T>
T& DoublyNode<T>::getElem() 
{
    return m_elem;
}

template <typename T>
const DoublyNode<T>* DoublyNode<T>::getNextNode() const 
{
    return m_next;
}

template <typename T>
DoublyNode<T>* DoublyNode<T>::getNextNode() 
{
    return m_next;
}

template <typename T>
const DoublyNode<T>* DoublyNode<T>::getPrevNode() const 
{
    return m_prev;
}

template <typename T>
DoublyNode<T>* DoublyNode<T>::getPrevNode() 
{
    return m_prev;
}

template <typename T>
void DoublyNode<T>::setElem(T elem) 
{
    m_elem = elem;
}

template <typename T>
void DoublyNode<T>::setNextNode(DoublyNode* node) 
{
    m_next = node;
}

template <typename T>
void DoublyNode<T>::setPrevNode(DoublyNode* node) 
{
    m_prev = node;
}