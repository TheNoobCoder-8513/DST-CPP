#ifndef DOUBLY_LINKED_LIST_NODE_HPP
#define DOUBLY_LINKED_LIST_NODE_HPP

template <typename T>
class DoublyNode
{
private:
    T m_elem {};
    DoublyNode* m_prev {};
    DoublyNode* m_next {};

public:
    DoublyNode(T elem, DoublyNode* prev = nullptr, DoublyNode* next = nullptr);

public:
    const T& getElem() const;
    T& getElem();

    const DoublyNode* getNextNode() const;
    DoublyNode* getNextNode();

    const DoublyNode* getPrevNode() const;
    DoublyNode* getPrevNode();

    void setElem(T elem);
    void setNextNode(DoublyNode* node);
    void setPrevNode(DoublyNode* node);
};

#include "DoublyLinkedListNode.inl"

#endif