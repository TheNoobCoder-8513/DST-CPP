#include "DoublyLinkedList.hpp"

#include <iostream>
#include <sstream>


template <typename T>
DoublyList<T>::DoublyList() = default;

template <typename T>
DoublyList<T>::DoublyList(const DoublyList& ls)
    : m_head {nullptr}, m_tail {nullptr}, m_length {0}
{
    for (DoublyNode<T>* temp = ls.m_head; temp; temp = temp->getNextNode())
        addLast(temp->getElem());
}

template <typename T>
DoublyList<T>::DoublyList(DoublyList&& ls)
    : m_head {ls.m_head}, m_tail {ls.m_tail}, m_length {ls.m_length}
{
    ls.m_head = nullptr;
    ls.m_tail = nullptr;
    ls.m_length = 0;
}

template <typename T>
DoublyList<T>::DoublyList(const std::initializer_list<T>& ls)
{
    for (const T& elem: ls)
        addLast(elem);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& ls)
{
    if (this == &ls) return *this;

    DoublyList<T> temp(ls);
    std::swap(m_head, temp.m_head);
    std::swap(m_tail, temp.m_tail);
    std::swap(m_length, temp.m_length);

    return *this;
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(DoublyList<T>&& ls)
{
    if (this == &ls) return *this;

    clear();

    m_head = ls.m_head;
    m_tail = ls.m_tail;
    m_length = ls.m_length;

    ls.m_head = nullptr;
    ls.m_tail = nullptr;
    ls.m_length = 0;
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList()
{
    clear();
}

template <typename T>
bool DoublyList<T>::isEmpty() const
{
    return m_length == 0;
}

template <typename T>
int DoublyList<T>::length() const
{
    return m_length;
}

template <typename T>
const T& DoublyList<T>::front() const 
{   
    if (m_head == nullptr)
        throw std::out_of_range {"Invalid access error: List is empty"};

    return m_head->getElem();
}

template <typename T>
const T& DoublyList<T>::back() const 
{
    if (m_tail == nullptr)
        throw std::out_of_range {"Invalid access error: List is empty"};

    return m_tail->getElem();
}

template <typename T>
const T& DoublyList<T>::addFirst(const T& elem)
{
    if (m_length == 0)
    {
        DoublyNode<T>* newNode {new DoublyNode<T> {elem}};
        m_head = m_tail = newNode;
    }
    else
    {
        DoublyNode<T>* newNode {new DoublyNode<T> {elem, nullptr, m_head}};
        m_head->setPrevNode(newNode);
        m_head = newNode;
    }
    ++m_length;
    return m_head->getElem();
}

template <typename T>
const T& DoublyList<T>::addLast(const T& elem)
{
    if (m_length == 0)
    {
        DoublyNode<T>* newNode {new DoublyNode<T> {elem}};
        m_head = m_tail = newNode;
    }
    else
    {
        DoublyNode<T>* newNode {new DoublyNode<T> {elem, m_tail}};
        m_tail->setNextNode(newNode);
        m_tail= newNode;
    }
    ++m_length;
    return m_tail->getElem();
}


template <typename T>
const T& DoublyList<T>::insertAtIndex(const T& elem, int pos)
{
    if (pos < 0 || pos > m_length) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};
    
    if (pos == 0)
        return addFirst(elem);
    else
    if (pos == m_length)
        return addLast(elem);
    else
    {
        if (pos <= (m_length - 1) / 2)
        {
            DoublyNode<T>* temp {m_head};
            for (int index {}; index < pos - 1; ++index)
                temp = temp->getNextNode();
            
            DoublyNode<T>* newNode {new DoublyNode<T> {elem, temp, temp->getNextNode()}};
            temp->setNextNode(newNode);
            newNode->getNextNode()->setPrevNode(newNode);
            ++m_length;
            return newNode->getElem();
        }
        else
        {
            DoublyNode<T>* temp {m_tail};
            for (int index {m_length - 1}; index > pos ; --index)
                temp = temp->getPrevNode();
            
            DoublyNode<T>* newNode {new DoublyNode<T> {elem, temp->getPrevNode(), temp}};
            temp->setPrevNode(newNode);
            newNode->getPrevNode()->setNextNode(newNode);
            ++m_length;
            return newNode->getElem();
        }
    }
}

template <typename T>
T DoublyList<T>::removeFirst()
{
    if (m_length == 0) 
        throw std::out_of_range {"Invalid access error: List is empty"};

    DoublyNode<T>* nodeToDelete {m_head};
    T obj {nodeToDelete->getElem()};

    if (m_head == m_tail)
        m_head = m_tail = nullptr;
    else
    {
        m_head = nodeToDelete->getNextNode();
        m_head->setPrevNode(nullptr);
    }
    delete nodeToDelete;
    --m_length;
    return obj;
}

template <typename T>
T DoublyList<T>::removeLast()
{
    if (m_length == 0) 
        throw std::out_of_range {"Invalid access error: List is empty"};
    
    DoublyNode<T>* nodeToDelete {m_tail};
    T obj {nodeToDelete->getElem()};

    if (m_head == m_tail)
        m_head = m_tail = nullptr;
    else
    {
        nodeToDelete->getPrevNode()->setNextNode(nullptr);
        m_tail = nodeToDelete->getPrevNode();
    }
    delete nodeToDelete;
    --m_length;
    return obj;
}

template <typename T>
T DoublyList<T>::removeFromIndex(int pos)
{
    if (pos < 0 || pos >= m_length) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};

    if (pos == 0) 
        return removeFirst();
    else
    if (pos == m_length - 1)
        return removeLast();
    else
    {   
        if (pos <= (m_length - 1) / 2)
        {
            DoublyNode<T>* temp {m_head};
            for (int index {}; index < pos - 1; ++index)
                temp = temp->getNextNode();
            
            DoublyNode<T>* nodeToDelete {temp->getNextNode()};
            temp->setNextNode(nodeToDelete->getNextNode());
            nodeToDelete->getNextNode()->setPrevNode(temp);
            T obj {nodeToDelete->getElem()};
            --m_length;
            delete nodeToDelete;
            return obj;
        }
        else
        {
            DoublyNode<T>* temp {m_tail};
            for (int index {m_length - 1}; index > pos + 1; --index)
                temp = temp->getPrevNode();
            
            DoublyNode<T>* nodeToDelete {temp->getPrevNode()};
            temp->setPrevNode(nodeToDelete->getPrevNode());
            nodeToDelete->getPrevNode()->setNextNode(temp);
            T obj {nodeToDelete->getElem()};
            --m_length;
            delete nodeToDelete;
            return obj;
        }
    }
}

template <typename T>
std::string DoublyList<T>::toStr() const
{
    if (m_length == 0) return "[]";
    DoublyNode<T>* temp {m_head};
    std::ostringstream stream {};
    stream << '[';
    for (int index {}; index < m_length; ++index)
    {
        if (index) stream << ", ";
        stream << temp->getElem();
        temp = temp->getNextNode();
    }
    stream << ']';
    return stream.str();
}




template <typename T>
const T& DoublyList<T>::atIndex(int pos) const
{
    if (pos >= m_length || pos < 0) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};

    if (pos <= (m_length - 1) / 2)
    {
        DoublyNode<T>* temp {m_head};
        for (int index {}; index < pos; ++index)
            temp = temp->getNextNode();
        
        return temp->getElem();
    }
    else
    {
        DoublyNode<T>* temp {m_tail};
        for (int index {m_length - 1}; index > pos; --index)
            temp = temp->getPrevNode();

        return temp->getElem();
    }
}

template <typename T>
void DoublyList<T>::clear()
{
    while (!isEmpty()) removeFirst();
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const DoublyList<T>& list)
{
    stream << list.toStr();
    return stream;
}
