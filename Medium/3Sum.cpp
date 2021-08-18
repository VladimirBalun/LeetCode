#include <vector>
#include <iostream>

std::vector<std::vector<int>> find_3sum_for_number(std::vector<int> numbers)
{
    std::vector<std::vector<int>> result{};
    if (numbers.size() < 3u) {
        return result;
    }

    std::sort(numbers.begin(), numbers.end());
    for (size_t i = 0u; i < numbers.size() - 2u; ++i) {
        if ((i > 0u) && (numbers[i] == numbers[i - 1u])) {
            continue;
        }
        size_t left = i + 1u;
        size_t right = numbers.size() - 1u;
        while (left < right) {
            const int sum = numbers[i] + numbers[left] + numbers[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                result.push_back({ numbers[i], numbers[left], numbers[right] });
                do {
                    ++left;
                } while ((left < right) && (numbers[left] == numbers[left - 1u]));
            }
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    {
        const std::vector<int> data{ -1, 0, 1, 2, -1, -4 };
        const std::vector<std::vector<int>> result = find_3sum_for_number(data);
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
        const std::vector<int> data{};
        const std::vector<std::vector<int>> result = find_3sum_for_number(data);
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
        const std::vector<int> data{ 0 };
        const std::vector<std::vector<int>> result = find_3sum_for_number(data);
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