#include "../Helpers.hpp"

// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

// Example 1:
// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

// Example 2:
// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

class Solution
{
public:
    double average(const std::vector<int>& salary)
    {
        int min = salary[0];
        int max = salary[0];
        int sum = salary[0];

        const size_t size = salary.size();
        for (size_t i = 1u; i < size; ++i) {
            min = std::min(min, salary[i]);
            max = std::max(max, salary[i]);
            sum += salary[i];
        }

        return double(sum - max - min) / (size - 2u);
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
