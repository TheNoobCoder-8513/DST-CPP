#include "../headers/SinglyLinkedListNode.hpp"

template <typename T>
SinglyNode<T>::SinglyNode(T elem, SinglyNode* next)
    : m_elem {elem}, m_next {next}
{}

template <typename T>
const T& SinglyNode<T>::getElem() const 
{
    return m_elem;
}

template <typename T>
T& SinglyNode<T>::getElem() 
{
    return m_elem;
}

template <typename T>
const SinglyNode<T>* SinglyNode<T>::getNextNode() const 
{
    return m_next;
}

template <typename T>
SinglyNode<T>* SinglyNode<T>::getNextNode() 
{
    return m_next;
}

template <typename T>
void SinglyNode<T>::setElem(T elem) 
{
    m_elem = elem;
}

template <typename T>
void SinglyNode<T>::setNextNode(SinglyNode* node) 
{
    m_next = node;
}
