#include <vector>
#include <iostream>

int binary_search(const std::vector<int>& data, int value)
{
    if (data.empty()) {
        return -1;
    }

    size_t begin = 0u;
    size_t end = data.size() - 1;
    while (begin <= end) {
        size_t middle = (begin + end) / 2;
        if (value == data.at(middle)) {
            return middle;
        } else if (value < data.at(middle)) {
            end = middle - 1;
        } else if (value > data.at(middle)) {
            begin = middle + 1;
        }
    }

    return -1;
}

int main(int argc, char** argv)
{
    std::cout << binary_search({ -1, 0, 3, 5, 9, 12 }, 9) << std::endl;
    std::cout << binary_search({ -1, 0, 3, 5, 9, 12 }, 2) << std::endl;

    return EXIT_SUCCESS;
}
