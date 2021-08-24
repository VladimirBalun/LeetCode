#include <unordered_map>

#include "../Helpers.hpp"

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
            std::sort(anagrams.second.begin(), anagrams.second.end());
            result.push_back(std::move(anagrams.second));
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<std::string> strings{ "eat", "tea", "tan", "ate", "nat", "bat" };
        ASSERT_EQUALS(solution.groupAnagrams(strings), (std::vector<std::vector<std::string>>{
            { "bat" }, { "nat", "tan" }, { "ate", "eat", "tea" }
        }));
    }
    {
        const std::vector<std::string> strings{ "" };
        ASSERT_EQUALS(solution.groupAnagrams(strings), (std::vector<std::vector<std::string>>{{ "" }}));
    }
    {
        const std::vector<std::string> strings{ "a" };
        ASSERT_EQUALS(solution.groupAnagrams(strings), (std::vector<std::vector<std::string>>{{ "a" }}));
    }
    return EXIT_SUCCESS;
}
