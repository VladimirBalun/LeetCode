#include "../Helpers.hpp"

// You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
// Given the string command, return the Goal Parser's interpretation of command.

// Example 1:
// Input: command = "G()(al)"
// Output: "Goal"
// Explanation: The Goal Parser interprets the command as follows:
// G -> G
// () -> o
// (al) -> al
// The final concatenated result is "Goal".

// Example 2:
// Input: command = "G()()()()(al)"
// Output: "Gooooal"

// Example 3:
// Input: command = "(al)G(al)()()G"
// Output: "alGalooG"

class Solution
{
public:
    std::string interpret(const std::string& command)
    {
        std::string result;
        for (size_t i = 0u; i < command.size();) {
            if (command[i] == 'G') {
                result += 'G';
                ++i;
            } else if ((i < command.size() - 1u) && (command[i] == '(' && command[i + 1] == ')')) {
                result += 'o';
                i += 2;
            } else {
                result += "al";
                i += 4;
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
