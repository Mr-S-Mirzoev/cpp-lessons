#pragma once

// (c) Copyright 2023. Author: Sergey Mirzoev
// GH: @Mr-S-Mirzoev.
// STF stands for small test framework
//
// Free distribution and use with the preservation of author rights (this
// header)

#include <exception>
#include <iostream>

using TestException = std::runtime_error;

#define STRINGIZE(x) STRINGIZE2(x)
#define STRINGIZE2(x) #x
#define LINE_STRING STRINGIZE(__LINE__)

#define RAISE(err_str) throw TestException(std::string(err_str))

#define ASSERT_EQ(arg1, arg2)                                                  \
    ++count;                                                                   \
    if (arg1 != arg2)                                                          \
        RAISE(("Test error occured at " __FILE__ ":" LINE_STRING " (" #arg1    \
               " is not equal to " #arg2 ")"));

#define ASSERT_TRUE(arg) ASSERT_EQ(arg, true);

#define ASSERT_FALSE(arg) ASSERT_EQ(arg, false);

#define ASSERT_THROW_TYPE(arg, exception_type)                                 \
    ++count;                                                                   \
    try                                                                        \
    {                                                                          \
        arg;                                                                   \
        RAISE(("Test error occured at " __FILE__ ":" LINE_STRING " (" #arg     \
               ") should throw an exception."));                               \
    }                                                                          \
    catch (exception_type e)                                                   \
    {                                                                          \
    }                                                                          \
    catch (...)                                                                \
    {                                                                          \
        RAISE(("Test error occured at " __FILE__ ":" LINE_STRING " (" #arg     \
               ") should throw an exception of different type"));              \
    };

#define ASSERT_THROW_ANY(arg) ASSERT_THROW_TYPE(arg, std::exception);

#define ASSERT_NO_THROW(arg)                                                   \
    ++count;                                                                   \
    try                                                                        \
    {                                                                          \
        arg;                                                                   \
    }                                                                          \
    catch (...)                                                                \
    {                                                                          \
        RAISE(("Test error occured at " __FILE__ ":" LINE_STRING " (" #arg     \
               ") shouldn't throw an exception"));                             \
    };

#define EXPECT_EQ(arg1, arg2)                                                  \
    ++count;                                                                   \
    if (arg1 != arg2)                                                          \
    {                                                                          \
        std::cerr << "Test error occured at " __FILE__ ":" LINE_STRING         \
                     " (" #arg1 " is not equal to " #arg2 "):"                 \
                  << std::endl;                                                \
        std::cerr << "\"" << (arg1) << "\""                                    \
                  << " != "                                                    \
                  << "\"" << (arg2) << "\"" << std::endl;                      \
        passed = false;                                                        \
        ++asserted;                                                            \
    }

#define EXPECT_TRUE(arg) EXPECT_EQ(arg, true);

#define EXPECT_FALSE(arg) EXPECT_EQ(arg, false);

#define EXPECT_THROW_TYPE(arg, exception_type)                                 \
    ++count;                                                                   \
    try                                                                        \
    {                                                                          \
        arg;                                                                   \
        passed = false;                                                        \
        ++asserted;                                                            \
        std::cerr << "Test error occured at " __FILE__ ":" LINE_STRING         \
                     " (" #arg ") should throw an exception."                  \
                  << std::endl;                                                \
    }                                                                          \
    catch (exception_type e)                                                   \
    {                                                                          \
    }                                                                          \
    catch (...)                                                                \
    {                                                                          \
        passed = false;                                                        \
        ++asserted;                                                            \
        std::cerr << "Test error occured at " __FILE__ ":" LINE_STRING         \
                     " (" #arg ") should throw an exception of different type" \
                  << std::endl;                                                \
    };

#define EXPECT_THROW_ANY(arg) EXPECT_THROW_TYPE(arg, std::exception);

#define EXPECT_NO_THROW(arg)                                                   \
    ++count;                                                                   \
    try                                                                        \
    {                                                                          \
        arg;                                                                   \
    }                                                                          \
    catch (...)                                                                \
    {                                                                          \
        passed = false;                                                        \
        ++asserted;                                                            \
        std::cerr << "Test error occured at " __FILE__ ":" LINE_STRING         \
                     " (" #arg ") shouldn't throw an exception."               \
                  << std::endl;                                                \
    };

#define UNIT_TEST_BEGIN(test_suite, test_name)                                 \
    std::cout << "[ RUN      ] " #test_suite "." #test_name << std::endl;      \
    try                                                                        \
    {                                                                          \
        bool passed = true;

#define UNIT_TEST_END(test_suite, test_name)                                   \
    if (passed)                                                                \
        std::cout << "[       OK ] " #test_suite "." #test_name << std::endl;  \
    else                                                                       \
        std::cout << "[   FAILED ] " #test_suite "." #test_name << std::endl;  \
    }                                                                          \
    catch (TestException e)                                                    \
    {                                                                          \
        ++asserted;                                                            \
        std::cout << "[ ASSERTED ] " #test_suite "." #test_name ": "           \
                  << e.what() << std::endl;                                    \
    }

#define TEST_MAIN_BEGIN()                                                      \
    int main(int argc, char const* argv[])                                     \
    {                                                                          \
        int count = 0;                                                         \
        int asserted = 0;                                                      \
        try                                                                    \
        {

#define TEST_MAIN_END()                                                        \
    std::cout << count - asserted << " checks SUCCEED out of " << count        \
              << std::endl;                                                    \
    }                                                                          \
    catch (std::exception e)                                                   \
    {                                                                          \
        std::cerr << e.what() << std::endl;                                    \
        return 1;                                                              \
    }                                                                          \
    return asserted == 0 ? 0 : 1;                                              \
    }
