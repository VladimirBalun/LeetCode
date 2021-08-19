#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<size_t> find_number_sum(const std::vector<int>& numbers, int target_number)
{
    std::vector<size_t> result{};
    std::unordered_map<int, size_t> table{};
    for (size_t i = 0u; i < numbers.size(); ++i) {
        const auto it = table.find(target_number - numbers[i]);
        if (it != end(table)) {
            result.push_back(i);
            result.push_back(it->second);
            return result;
        } else {
            table.emplace(numbers[i], i);
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        const std::vector<size_t> result = find_number_sum(data, 9);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    {
        const std::vector<int> data{ 3, 2, 4 };
        const std::vector<size_t> result = find_number_sum(data, 6);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    {
        const std::vector<int> data{ 3, 3 };
        const std::vector<size_t> result = find_number_sum(data, 6);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    return EXIT_SUCCESS;
}