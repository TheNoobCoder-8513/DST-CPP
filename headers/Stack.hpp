#include <iostream>
#include <string>

#include "Vector.hpp"
#include "List.hpp"

enum StackType
{
    Static,
    Dynamic
};

template <typename T, template <typename> class Impl>
class StackInterface
{
protected:
    Impl<T> stack {};

public:
    StackInterface(const std::initializer_list<T>& ls)
    {
        for (const auto& elem : ls) 
            stack.addLast(elem);
    }

public:
    const T& push(const T& elem)
    {
        return stack.addLast(elem);
    }

    T pop(const T& elem)
    {
        return stack.removeLast();
    }

    const T& peek() const
    {
        return stack.at(stack.length() - 1);
    }

    bool isEmpty() const
    {
        return stack.isEmpty();
    }

    int length() const
    {
        return stack.length();
    }
};

template <typename T>
class DynamicStack : public StackInterface<T, List>
{
public:
    using StackInterface<T, List>::StackInterface;
};

template <typename T>
class StaticStack : public StackInterface<T, Vector>
{
public:
    using StackInterface<T, Vector>::StackInterface;

public:
    bool isFull()
    {
        return stack.isFull();
    }
};


template <typename T, StackType Type = StackType::Dynamic>
class Stack;


template <typename T>
class Stack<T, StackType::Static> : public StaticStack<T>
{
public:
    using StaticStack<T>::StaticStack;

public:
    friend std::ostream& operator<<(std::ostream& out, Stack& stack)
    {
        out << stack.toStr();
        return out;
    }
};

template <typename T>
class Stack<T, StackType::Dynamic> : public DynamicStack<T>
{
public:
    using DynamicStack<T>::DynamicStack;

public:
    friend std::ostream& operator<<(std::ostream& out, Stack& st)
    {
        out << st.stack.toStr();
        return out;
    }
};
