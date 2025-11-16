#ifndef SEARCHING_ALGORITHMS_HPP
#define SEARCHING_ALGORITHMS_HPP

#include "Vector.hpp"

// Linear search 
template <typename T>
int linearSearch(const Vector<T>& vec, const T& target);

// Binary search
template <typename T>
int binarySearchImpl(int lowIn, int highIn, const Vector<T>& vec, const T& target);

template <typename T>
int binarySearch(const Vector<T>& vec, T target);

#include "../implementations/SearchingAlgorithms.tpp"

#endif