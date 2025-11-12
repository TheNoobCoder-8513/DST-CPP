#include "../headers/Vector.hpp"



int main()
{
    Vector<int> vec {2, 4, 4, 1, 10, 5, 7, 9, 120};
    std::cout << "RemoveFrom Tests:\n";
    std::cout << "Case I: removeFrom(0): " << vec.removeFrom(0) << '\n';
    // std::cout << "Case II: removeFrom(length()): " << vec.removeFrom(vec.length()) << '\n'; 
    std::cout << "Case III: removeFrom(length()-1): " << vec.removeFrom(vec.length() - 1) << '\n';
    std::cout << "Case IV: removeFrom(4): " << vec.removeFrom(4) << '\n';
    std::cout << "State: " << vec << '\n';
    std::cout << '\n';
    std::cout << "insertAt() Tests:\n";
    std::cout << "Case I: insertAt(5): " << vec.insertAt(10, 5) << '\n';
    std::cout << "State: " << vec << '\n';
}