#include <string>
#include <memory>
#include <exception>

#include "../headers/List.hpp"

#include "../headers/SinglyLinkedList.hpp"
#include "../headers/DoublyLinkedList.hpp"


template <typename T, template <typename> class Impl>
List<T, Impl>::List() = default;

template <typename T, template <typename> class Impl>
List<T, Impl>::List(std::initializer_list<T> elems)
    : list {} 
{
    for (const auto& e : elems)
        list.addLast(e);
}


template <typename T, template <typename> class Impl>
int List<T, Impl>::length() const 
{
    return list.length();
}

template <typename T, template <typename> class Impl>
bool List<T, Impl>::isEmpty() const 
{
    return list.isEmpty();
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::front() const 
{
    return list.front();
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::back() const 
{
    return list.back();
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::atIndex(int pos) const
{
    return list.atIndex(pos);
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::addFirst(const T& elem) 
{
    return list.addFirst(elem);
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::addLast(const T& elem) 
{
    return list.addLast(elem);
}

template <typename T, template <typename> class Impl>
T List<T, Impl>::removeFirst() 
{
    return list.removeFirst();
}

template <typename T, template <typename> class Impl>
T List<T, Impl>::removeLast() 
{
    return list.removeLast();
}

template <typename T, template <typename> class Impl>
const T& List<T, Impl>::insertAtIndex(const T& elem, int pos)
{
    return list.insertAtIndex(elem, pos);
}

template <typename T, template <typename> class Impl>
T List<T, Impl>::removeFromIndex(int pos)
{
    return removeFromIndex(pos);
}

template <typename T, template <typename> class Impl>
std::string List<T, Impl>::toStr() const 
{
    return list.toStr();
}

template <typename T, template <typename> class Impl>
std::ostream& operator<<(std::ostream& os, const List<T, Impl>& l)

{
    return os << l.toStr();
}
