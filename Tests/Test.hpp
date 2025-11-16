#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <sstream>
#include <string_view>

namespace N_DST_TEST
{
    inline constexpr const char* GREEN  = "\033[32m";
    inline constexpr const char* RED    = "\033[31m";
    inline constexpr const char* YELLOW = "\033[33m";
    inline constexpr const char* BLUE   = "\033[34m";
    inline constexpr const char* RESET  = "\033[0m";
    inline constexpr const char* CYAN   = "\033[36m";

    template <typename TR, typename E>
    void runTest(
        const TR& result, const E& expected,
        std::string_view exprStr,
        std::string_view expectedStr,
        std::string_view fileName,
        int lineNo
    )
    {
        std::ostringstream resultStream;
        std::ostringstream expectedStream;

        resultStream << result;
        expectedStream << expected;

        if (resultStream.str() == expectedStream.str())
        {
            std::cout << GREEN << "[[ PASS ]] " << RESET
                      << exprStr << " : " 
                      << GREEN << expectedStr << RESET << "\n";
        }
        else
        {
            std::cout << BLUE << fileName << RESET << ":" << YELLOW << lineNo << RESET 
                      << "::" << exprStr << "\n";
            std::cout << RED << "[[ FAIL ]] " << RESET
                      << YELLOW << exprStr << RESET << " : " 
                      << RED << resultStream.str() << RESET << "\n";
            std::cout << CYAN << "           expected : " << expectedStream.str() << RESET << "\n";
            std::cout << RED <<    "                got : " << resultStream.str() << RESET << "\n";
        }
    }
}

// Macro to capture file and line
#define TEST(expr, expected) \
    N_DST_TEST::runTest((expr), (expected), #expr, #expected, __FILE__, __LINE__)

#endif
