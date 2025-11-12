#include "../headers/Vector.hpp"

#include <iostream>
#include <sstream>
#include <exception>


template <typename T>    
Vector<T>::Vector()        
    : m_capacity {0}, m_arr {nullptr}, m_length {0}    
{}

template <typename T>
Vector<T>::Vector(int len)
    : m_capacity {len}, m_arr {new T[m_capacity]}, m_length {len}
{}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& ls)
    : m_capacity {static_cast<int>(ls.size())}, m_arr {new T[m_capacity]}
{
    for (auto& elem: ls)
        addLast(elem);
}

template <typename T>
Vector<T>::Vector(const Vector& vec)
    : m_capacity {vec.m_capacity}, m_arr {new T[m_capacity]}
{
    for (int index {}; index < vec.m_length; ++index)
    {
        m_arr[index] = vec.m_arr[index];
    }
    m_length = vec.m_length;
}

template <typename T>
Vector<T>::Vector(Vector&& vec)
    : m_capacity {vec.m_capacity}, m_length {vec.m_length}
{
    m_arr = vec.m_arr;
    vec.m_arr = nullptr;
    vec.m_capacity = 0;
    vec.m_length = 0;
}

template <typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
    if (this == &vec) return *this;
    if (m_capacity != vec.m_capacity)
    {
        if (m_arr) delete[] m_arr;
        m_capacity = vec.m_capacity;
        m_arr = new T[m_capacity];
    }
    
    for (int index {}; index < vec.m_length; ++index)
    {
        m_arr[index] = vec.m_arr[index];
    }
    m_length = vec.m_length;
    return *this;
}

template <typename T>
const Vector<T>& Vector<T>::operator=(Vector<T>&& vec)
{
    if (this == &vec) return *this;
    if (m_arr) delete[] m_arr;
        m_arr = vec.m_arr;
        m_capacity = vec.m_capacity;
        m_length = vec.m_length;
        vec.m_arr = nullptr;
        vec.m_capacity = 0;
        vec.m_length = 0;

        return *this;
    }

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_arr;
}

template <typename T>    
const T& Vector<T>::addFirst(const T& val)    
{        
    if (!capacity())       
    {   
        if (!reserve(1))
            throw std::length_error {"Length Error: Unable to add element at end due to no more free memory"};
    }

    if (isFull())
    {
        if (!reserve(capacity() * 2))
            throw std::length_error {"Length Error: Unable to add element at end due to no more free memory"};
    }

    for (int index {length()}; index > 0; --index)
        m_arr[index] = m_arr[index - 1];
    m_arr[0] = val;
    return m_arr[0];
}


template <typename T>
const T& Vector<T>::addLast(const T& val)
{   
    // Capacity is 0
    if (!capacity())
    {
        if (!reserve(1))
            throw std::length_error {"Length Error: Unable to add element at end due to no more free memory"};
    }

    if (isFull())
    {
        if (!reserve(capacity() * 2))
            throw std::length_error {"Length Error: Unable to add element at end due to no more free memory"};
    }

    return m_arr[m_length++] = val;
}

template <typename T>
T Vector<T>::removeFirst()
{
    if (m_length == 0)
        throw std::out_of_range{"Remove Error: Vector is empty"};

    T obj {m_arr[0]};
    
    for (int index {}; index < length() - 1; ++index)
    {
        m_arr[index] = m_arr[index + 1];
    }
    --m_length;
    return obj;
}
    

template <typename T>
T Vector<T>::removeLast()
{
    if (m_length == 0)
        throw std::out_of_range{"Remove Error: Vector is empty"};
    return m_arr[--m_length];
}

template <typename T>
const T& Vector<T>::insertAt(const T& elem, int pos)
{
    if (pos < 0 || pos > length())
        throw std::out_of_range {"Index Error: Index Out of range"};
    if (pos == 0)
        return addFirst(elem);
    else
    if (pos == length())
        return addLast(elem);
    else
    {
        if (isFull())
        {
            if (!reserve(capacity() * 2))
            throw std::length_error {"Length Error: Unable to reserve space for more "
                "elements due to no more available free memory"};
        }
        for (int index {length()}; index > pos; --index)
        {
            m_arr[index] = m_arr[index - 1];
        }
        m_arr[pos] = elem;
        ++m_length;
        return m_arr[pos];
    }
}

template <typename T>
T Vector<T>::removeFrom(int pos)
{
    if (pos < 0 || pos >= length())
        throw std::out_of_range {"Index Error: Index Out of range"};
    
    if (pos == 0)
        return removeFirst();
    else
    if (pos == length() - 1)
        return removeLast();
    else
    {
        T obj {m_arr[pos]};
        for (int index {pos}; index < length() - 1; ++index)
        {
            m_arr[index] = m_arr[index + 1];
        }
        --m_length;
        return obj;
    }
}


template <typename T>
bool Vector<T>::isEmpty() const 
{
    return !length();
}

template <typename T>
bool Vector<T>::isFull() const 
{
    return (length() == capacity()) && capacity();
}

template <typename T>
int Vector<T>::length() const 
{
    return m_length;
}

template <typename T>
int Vector<T>::capacity() const 
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::reserve(int len)
{
    if (len < length()) 
        throw std::invalid_argument {"Length Error: Passed capacity for vector is less than current size of vector"};
    if (len == length()) return true;

    T* nVec {new T[len]};
    if (nVec)
    {
        for (int index {}; index < length(); ++index)
        {
            nVec[index] = m_arr[index];
        }
        if (m_arr) delete[] m_arr;
        m_arr = nVec;
        m_capacity = len;
        return true;
    }
    else
        return false;
}


template <typename T>
const T& Vector<T>::set(int index, const T& val)
{
    if (index >= capacity()) throw std::out_of_range {"Index Error: Index Out of range"};
    return m_arr[index] = val;
}

template <typename T>
const T& Vector<T>::at(int index) const
{
    if (index >= capacity()) throw std::out_of_range {"Index Error: Index Out of range"};
    return m_arr[index];
}

template <typename T>
std::string Vector<T>::toStr() const
{
    if (length() == 0) return "[]";
    std::ostringstream stream;
    stream << '[';
    for (int index {}; index < length(); ++index)
    {
        if (index) stream << ", ";
        stream << m_arr[index];
    }
    stream << ']';
    return stream.str();
}

template <typename T>
const T& Vector<T>::operator[](int index) const
{
    if (index >= length()) 
        throw std::out_of_range {"Index Error: Index Out of range"};
    return m_arr[index];
}

template <typename T>
T& Vector<T>::operator[](int index)
{
    if (index >= length()) 
        throw std::out_of_range {"Index Error: Index Out of range"};
    return m_arr[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& vec)
{
    stream << vec.toStr();
    return stream;
}
