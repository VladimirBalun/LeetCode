#include <stack>
#include <iostream>

bool is_valid_parentheses(const std::string& text)
{
    std::stack<char> opened_parentheses;
    for (const auto& symbol : text) {
        if ((symbol == '(') || (symbol == '[') || (symbol == '{')) {
            opened_parentheses.push(symbol);
        } else {
            const char last_symbol = opened_parentheses.top();
            opened_parentheses.pop();
            if ((symbol == ')') && (last_symbol == '(')) {
                continue;
            }
            if ((symbol == ']') && (last_symbol == '[')) {
                continue;
            }
            if ((symbol == '}') && (last_symbol == '{')) {
                continue;
            }
            return false;
        }
    }
    return opened_parentheses.empty();
}

int main(int argc, char** argv)
{
    std::cout << "Result: " << is_valid_parentheses("()") << std::endl;
    std::cout << "Result: " << is_valid_parentheses("()[]{}") << std::endl;
    std::cout << "Result: " << is_valid_parentheses("(]") << std::endl;
    std::cout << "Result: " << is_valid_parentheses("([)]") << std::endl;
    std::cout << "Result: " << is_valid_parentheses("{[]}") << std::endl;

    return EXIT_SUCCESS;
}