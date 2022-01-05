#include "../Helpers.hpp"

// Given an integer n, return a string array answer (1-indexed) where:
// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.

// Example 1:
// Input: n = 3
// Output: ["1","2","Fizz"]

// Example 2:
// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]

// Example 3:
// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

class Solution 
{
public:
    std::vector<std::string> fizzBuzz(int number) 
    {
        std::vector<std::string> result;
        for (size_t i = 1u; i <= number; ++i) {
            const bool divisible_by_3 = i % 3 == 0;
            const bool divisible_by_5 = i % 5 == 0;
            if (divisible_by_3 && divisible_by_5) {
                result.push_back("FizzBuzz");
            } else if (divisible_by_5) {
                result.push_back("Buzz");
            } else if (divisible_by_3) {
                result.push_back("Fizz");
            } else {
                result.push_back(to_string(i));
            }
        }

        return result;
    }
};


int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}