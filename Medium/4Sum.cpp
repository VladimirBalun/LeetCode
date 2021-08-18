#include <vector>
#include <iostream>
#include <unordered_set>

std::vector<std::vector<int>> find_four_sums_for_number(std::vector<int> numbers, int target_number)
{
    std::vector<std::vector<int>> result{};
    if (numbers.size() < 4u) {
        return result;
    }

    std::sort(numbers.begin(), numbers.end());
    for (size_t i = 0u; i < numbers.size() - 3u; ++i) {
        if ((i > 0u) && (numbers[i] == numbers[i - 1u])) {
            continue;
        }
        for (size_t j = i + 1u; j < numbers.size() - 2u; ++j) {
            if ((j > i + 1u) && (numbers[j] == numbers[j - 1u])) {
                continue;
            }
            size_t left = j + 1u;
            size_t right = numbers.size() - 1u;
            const int temp_sum = numbers[i] + numbers[j];
            while (left < right) {
                const int target_sum = temp_sum + numbers[left] + numbers[right];
                if (target_sum < target_number) {
                    ++left;
                } else if (target_sum > target_number) {
                    --right;
                } else {
                    result.push_back({ numbers[i], numbers[j], numbers[left], numbers[right] });
                    do {
                        ++left;
                    } while ((left < right) && (numbers[left] == numbers[j - 1u]));
                }
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    {
        std::vector<int> data{ 1, 0, -1, 0, -2, 2 };
        std::vector<std::vector<int>> result = find_four_sums_for_number(data, 0);
        for (const auto& row : result) {
            std::cout << "[ ";
            for (const int number : row) {
                std::cout << number << " ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> data{ 2, 2, 2, 2, 2 };
        std::vector<std::vector<int>> result = find_four_sums_for_number(data, 8);
        for (const auto& row : result) {
            std::cout << "[ ";
            for (const int number : row) {
                std::cout << number << " ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}