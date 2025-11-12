#include "../headers/SinglyLinkedList.hpp"



template <typename T>
SinglyList<T>::SinglyList() = default;

template <typename T>
SinglyList<T>::SinglyList(const SinglyList& ls)
    : m_head {nullptr}, m_tail {nullptr}, m_length {0}
{
    for (SinglyNode<T>* temp = ls.m_head; temp; temp = temp->getNextNode())
        addLast(temp->getElem());
}

template <typename T>
SinglyList<T>::SinglyList(SinglyList&& ls)
    : m_head {ls.m_head}, m_tail {ls.m_tail}, m_length {ls.m_length}
{
    ls.m_head = nullptr;
    ls.m_tail = nullptr;
    ls.m_length = 0;
}

template <typename T>
SinglyList<T>::SinglyList(const std::initializer_list<T>& ls)
{
    for (const T& elem: ls)
        addLast(elem);
}

template <typename T>
SinglyList<T>& SinglyList<T>::operator=(const SinglyList<T>& ls)
{
    if (this == &ls) return *this;

    SinglyList<T> temp(ls);
    std::swap(m_head, temp.m_head);
    std::swap(m_tail, temp.m_tail);
    std::swap(m_length, temp.m_length);

    return *this;
}

template <typename T>
SinglyList<T>& SinglyList<T>::operator=(SinglyList<T>&& ls)
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
SinglyList<T>::~SinglyList()
{
    clear();
}

template <typename T>
bool SinglyList<T>::isEmpty() const
{
    return m_length == 0;
}

template <typename T>
int SinglyList<T>::length() const
{
    return m_length;
}

template <typename T>
const T& SinglyList<T>::front() const 
{
    if (m_head == nullptr)
        throw std::out_of_range {"Invalid access error: List is empty"};

    return m_head->getElem();
}

template <typename T>
const T& SinglyList<T>::back() const 
{
    if (m_tail == nullptr)
        throw std::out_of_range {"Invalid access error: List is empty"};

    return m_tail->getElem();
}

template <typename T>
const T& SinglyList<T>::addFirst(const T& elem)
{
    SinglyNode<T>* newNode {new SinglyNode<T> {elem, m_head}};
    if (m_length == 0)
        m_head = m_tail = newNode;
    else
        m_head = newNode;
    ++m_length;
    return newNode->getElem();
}

template <typename T>
const T& SinglyList<T>::addLast(const T& elem)
{
    SinglyNode<T>* newNode {new SinglyNode<T> {elem}};
    if (m_length == 0)
        m_head = m_tail = newNode;
    else
    {
        m_tail->setNextNode(newNode);
        m_tail = newNode;
    }
    
    ++m_length;
    return newNode->getElem();
}

template <typename T>
const T& SinglyList<T>::insertAtIndex(const T& elem, int pos)
{
    if (pos > m_length || pos < 0) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};

    if (pos == 0)
        return addFirst(elem);
    else
    if (pos == m_length)
        return addLast(elem);
    else
    {
        SinglyNode<T>* temp {m_head};
        for (int index {}; index < pos - 1; ++index)
        {
            temp = temp->getNextNode();
        }

        SinglyNode<T>* newNode {new SinglyNode<T> {elem, temp->getNextNode()}};
        
        temp->setNextNode(newNode);
        ++m_length;
        return newNode->getElem();
    }
}


template <typename T>
T SinglyList<T>::removeFirst()
{
    if (m_length == 0) 
        throw std::out_of_range {"Invalid access error: List is empty"};

    SinglyNode<T>* nodeToDelete {m_head};
    m_head = nodeToDelete->getNextNode();
    if (m_length == 1) m_tail = nullptr;
    T obj {nodeToDelete->getElem()};
    delete nodeToDelete;
    --m_length;
    return obj;
}

template <typename T>
T SinglyList<T>::removeLast()
{
    if (m_length == 0) 
        throw std::out_of_range {"Invalid access error: List is empty"};

    SinglyNode<T>* nodeToDelete {m_tail};

    SinglyNode<T>* temp {m_head};
    while (temp->getNextNode() != nodeToDelete) temp = temp->getNextNode();
    T obj {nodeToDelete->getElem()};
    if (m_length == 1) {m_head = m_tail = nullptr;}
    else m_tail = temp;
    delete nodeToDelete;
    --m_length;
    return obj;
}


template <typename T>
T SinglyList<T>::removeFromIndex(int pos)
{
    if (pos >= m_length || pos < 0) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};

    SinglyNode<T>* temp {m_head};

    if (pos == 0)
        return removeFirst();
    else
    if (pos == m_length - 1)
        return removeLast();
    else
    {
        for (int index {}; index < pos - 1; ++index)
            temp = temp->getNextNode();

        T obj {temp->getNextNode()->getElem()};
        SinglyNode<T>* nodeToDelete {temp->getNextNode()};
        temp->setNextNode(nodeToDelete->getNextNode());
        delete nodeToDelete;
        if (pos == m_length - 1) m_tail = temp;
        --m_length;
        return obj;
    }
}


template <typename T>
const T& SinglyList<T>::atIndex(int pos) const
{
    if (pos >= m_length || pos < 0) 
        throw std::out_of_range {"Invalid access error: Index is out of bounds"};

    SinglyNode<T>* temp {m_head};
    for (int index {}; index < pos; ++index)
    {
        temp = temp->getNextNode();
    }
    return temp->getElem();
}

template <typename T>
std::string SinglyList<T>::toStr() const
{
    if (m_length == 0) return "[]";
    SinglyNode<T>* temp {m_head};
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
SinglyList<T>& SinglyList<T>::concat(const SinglyList<T>& ls)
{
    if (this == &ls) return *this;
    
    SinglyNode<T>* temp {ls.m_head};
    while (temp != nullptr)
    {
        addLast(temp->getElem());
        temp = temp->getNextNode();
    }
    return *this;
}

template <typename T>
SinglyList<T>& SinglyList<T>::concat(SinglyList<T>&& ls)
{
    if (this == &ls) return *this;
    if (ls.m_head == nullptr) return *this;

    if (m_head == nullptr)
    {
        m_head = ls.m_head;
        m_tail = ls.m_tail;
    }
    else
    {
        m_tail->setNextNode(m_head);
        m_tail = ls.m_tail;
    }

    m_length += ls.m_length;
    ls.m_head = ls.m_tail = nullptr;
    ls.m_length = 0;

    return *this;
}


template <typename T>
void SinglyList<T>::clear()
{
    while (!isEmpty()) removeFirst();
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const SinglyList<T>& list)
{
    stream << list.toStr();
    return stream;
}
