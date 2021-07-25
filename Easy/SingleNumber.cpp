#include <iostream>
#include <vector>

int find_single_number(const std::vector<int>& data)
{
    int single_number = 0;
    for (const auto number : data) {
        single_number ^= number;
    }
    return single_number;
}

int main(int argc, char** argv)
{
    {
        const int single_number = find_single_number({ 2, 2, 1, 4, 4 });
        std::cout << "Single number: " << single_number << std::endl;
    }
    {
        const int single_number = find_single_number({ 4, 1, 2, 1, 2 });
        std::cout << "Single number: " << single_number << std::endl;
    }
    {
        const int single_number = find_single_number({ 1 });
        std::cout << "Single number: " << single_number << std::endl;
    }
    return EXIT_SUCCESS;
}
