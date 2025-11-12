#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <initializer_list>

template <typename T>
class Vector;

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Vector<T>& vec);


template <typename T>
class Vector
{
private:
    int m_capacity {};
    T* m_arr {};
    int m_length {};

public:
    Vector();

    Vector(int len);

    Vector(const std::initializer_list<T>& ls);

    Vector(const Vector& vec);

    Vector(Vector&& vec);

    const Vector& operator=(const Vector& vec);

    const Vector& operator=(Vector&& vec);
    
    ~Vector();

public:
    const T& addFirst(const T& val);

    const T& addLast(const T& val);

    T removeFirst();

    T removeLast();

    bool isEmpty() const;

    bool isFull() const;

    int length() const;

    int capacity() const;

    bool reserve(int len);

    const T& set(int index, const T& val);

    const T& at(int index) const;

    std::string toStr() const;

    const T& operator[](int index);

public:
    friend std::ostream& operator<<<>(std::ostream& stream, const Vector& vec);
};

#include "../implementations/Vector.tpp"

#endif