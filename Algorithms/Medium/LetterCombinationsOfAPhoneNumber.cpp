#include "../Helpers.hpp"

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]

class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        if (digits.empty())
            return {};
        
        std::unordered_map<char, std::string> letters{
            { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, 
            { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" },
        };

        std::string combination;
        std::vector<std::string> result;
        std::function<void(size_t)> backtracking;
        backtracking = [&backtracking, &letters, &digits, &result, &combination] (size_t index)
        {
            if (index == digits.length())
                return result.push_back(combination);
            
            for (const char symbol : letters[digits[index]]) {
                combination += symbol;
                backtracking(index + 1);
                combination.pop_back();
            }
        };
        
        backtracking(0u);
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}