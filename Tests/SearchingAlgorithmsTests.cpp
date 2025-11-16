#include "Test.hpp"
#include "../headers/SearchingAlgorithms.hpp"

int main()
{
    Vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TEST(binarySearch(vec, 10), 9);
    TEST(binarySearch(vec, 2), 1);
    TEST(binarySearch(vec, 8), 2);
    TEST(binarySearch(vec, 1), 0);
}