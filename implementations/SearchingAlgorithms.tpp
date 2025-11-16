#include "../headers/SearchingAlgorithms.hpp"


template <typename T>
int linearSearch(const Vector<T>& vec, const T& target)
{
    for (int index {}; index < vec.length(); ++index)
    {
        if (vec[index] == target)
            return index;
    }
    return -1;
}

template <typename T>
int binarySearchImpl(int lowIn, int highIn, const Vector<T>& vec, const T& target)
{
    while (lowIn <= highIn)
    {
        int midIn {(highIn - lowIn) / 2 + lowIn};
    
        if (vec[midIn] == target) 
            return midIn;
        else
        if (vec[midIn] < target)
            lowIn = midIn + 1;
        else
        if (vec[midIn] > target)
            highIn = midIn - 1;
    }
    return -1;
}

template <typename T>
int binarySearch(const Vector<T>& vec, T target)
{
    return binarySearchImpl(0, vec.length() - 1, vec, target);
}
