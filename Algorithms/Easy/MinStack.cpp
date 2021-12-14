#include "../Helpers.hpp"

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

class MinStack
{
public:
    MinStack() {}
    
    void push(int val)
    {
        if (!m_stack.empty()) {
            const int min = std::min(m_stack.top().second, val);
            m_stack.push({ val, min });
        } else {
            m_stack.push({ val, val });
        }
    }
    
    void pop()
    {
        m_stack.pop();
    }
    
    int top()
    {
        return m_stack.top().first;
    }
    
    int getMin()
    {
        return m_stack.top().second;
    }
private:
    std::stack<std::pair<int, int>> m_stack;      
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
