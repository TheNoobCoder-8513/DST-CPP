#include "../headers/Map.hpp"


int main()
{
    Map<std::string, int> mp {};
    std::cout << "addPair Tests:\n";
    mp.addPair("Anshuman", 21);
    mp.addPair("Laddooo", 57);
    mp.update("Bisleri", 77);
    mp.addPair("Navratan", 2);
    mp.update("Laddooo", 99);
    std::cout << "State: " << mp << '\n';

    std::cout << std::endl;

    // Commented to test further testcases
    // std::cout << "removePair Tests:\n";
    // std::cout << "Case I: removePair(\"Anshuman\")" << mp.removePair("Anshuman") << '\n';
    // std::cout << "Case I: removePair(\"Bisleri\")" << mp.removePair("Bisleri") << '\n';
    // std::cout << "State: " << mp << '\n';
    // std::cout << std::endl;

    std::cout << "isEmpty() Tests:\n";
    std::cout << "Is map empty now ? " << std::boolalpha << mp.isEmpty() << '\n';
    std::cout << std::endl;

    std::cout << "hasKey() Tests:\n";
    std::cout << "Do Anshuman exist ? " << mp.hasKey("Anshuman") << '\n';
    std::cout << "Do Gurleen exist ? " << mp.hasKey("Gurleen") << '\n';
    std::cout << std::endl;

    std::cout << "valOf() Tests: \n";
    std::cout << "valOf(Anshuman): " << mp.valOf("Anshuman") << '\n';
    std::cout << "valOf(Navratan): " << mp.valOf("Navratan") << '\n';
    // std::cout << "valOf(India): " << mp.valOf("India") << '\n'; /* -- > throws error */
    std::cout << std::endl;
}