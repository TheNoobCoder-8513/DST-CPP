#ifndef TEST_HPP
#define TEST_HPP

#include <string_view>

namespace N_DST_TEST
{

    inline constexpr const char* GREEN = "\033[32m";
    inline constexpr const char* RED   = "\033[31m";
    inline constexpr const char* RESET = "\033[0m";


    template <typename TR, typename E>
    void runTest
    (
        const TR& result, const E& expec, 
        std::string_view resStr, std::string_view expecStr,
        std::string_view fileName, int lineNo
    )
    {
        std::ostringstream exprStream {};
        std::ostringstream expectedStream {};

        exprStream << result;
        expectedStream << expec;

        if (exprStream.str() == expectedStream.str())
        {
            std::cout << GREEN << "[PASS] "
                      << RESET << resStr
                      << " == " << expecStr
                      << "  →  " << exprStream.str() << '\n';
        }
        else
        {
            std::cerr << RED << "[FAIL] "
                      << RESET << resStr
                      << " == " << expecStr
                      << "\n       got: " << exprStream.str()
                      << "\n  expected: " << expectedStream.str()
                      << "\n  at " << fileName << ":" << lineNo << "\n";
        }
        
    }
}

#define TEST(expr, expected) \
    N_DST_TEST::runTest((expr), (expected), #expr, #expected, __FILE__, __LINE__)

#endif