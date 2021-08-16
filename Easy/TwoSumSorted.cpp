#include <vector>
#include <iostream>

std::vector<size_t> find_sorted_number_sum(const std::vector<int>& numbers, int target_number)
{
    std::vector<size_t> result{};
    if (numbers.size() < 2u) {
        return result;
    }

    size_t left = 0u;
    size_t right = numbers.size() - 1u;
    while (left <= right) {
        const int sum = numbers[left] + numbers[right];
        if (sum > target_number) {
            --right;
        } else if (sum < target_number) {
            ++left;
        } else {
            result.push_back(left + 1u);
            result.push_back(right + 1u);
            return result;
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        const std::vector<size_t> result = find_sorted_number_sum(data, 9);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    {
        const std::vector<int> data{ 2, 3, 4 };
        const std::vector<size_t> result = find_sorted_number_sum(data, 6);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    {
        const std::vector<int> data{ -1, 0 };
        const std::vector<size_t> result = find_sorted_number_sum(data, -1);
        if (result.empty()) {
            std::cout << "[ ]" << std::endl;
        } else {
            std::cout << "[ " << result.at(0u) << ", " << result.at(1u) << " ]" << std::endl;
        }
    }
    return EXIT_SUCCESS;
}