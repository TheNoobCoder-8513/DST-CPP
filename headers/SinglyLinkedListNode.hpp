#ifndef SINGLY_LINKED_LIST_NODE_HPP
#define SINGLY_LINKED_LIST_NODE_HPP

template <typename T>
class SinglyNode
{
private:
    T m_elem {};
    SinglyNode* m_next {};

public:
    SinglyNode(T elem, SinglyNode* node = nullptr);

public:
    const T& getElem() const;
    T& getElem();

    const SinglyNode* getNextNode() const;
    SinglyNode* getNextNode();

    void setElem(T elem);
    void setNextNode(SinglyNode* node);
};

#include "SinglyLinkedListNode.inl"

#endif