#include "../Helpers.hpp"

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strings)
    {
        std::vector<std::vector<std::string>> result{};
        std::unordered_map<std::string, std::vector<std::string>> lookup_table{};
        for (const auto& string : strings) {
            std::string sorted_string = string;
            std::sort(sorted_string.begin(), sorted_string.end());
            lookup_table[sorted_string].push_back(string);
        }

        result.reserve(lookup_table.size());
        for (auto&& anagrams : lookup_table) {
            result.push_back(std::move(anagrams.second));
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
