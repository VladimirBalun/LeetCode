#pragma once

#include <cassert>
#include <iostream>

#define __CHECK_NUMBER_EQUALS(result, expected)                                              \
    do {                                                                                     \
        if ((expected) != (result)) {                                                        \
            std::cerr << "Assertion failed: " << __FILE__ << ":" << __LINE__                 \
                      << " - Expected: " << expected << " Result: " << result << std::endl;  \
        }                                                                                    \
    } while (false)                                                                          \

#define ASSERT_EQUALS(result, expected) \
    __CHECK_NUMBER_EQUALS((result), (expected))