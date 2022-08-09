#include <functional>
#include <thread>
#include <mutex>

// Suppose you are given the following code:

// class FooBar {
//  public void foo() {
//    for (int i = 0; i < n; i++) {
//      print("foo");
//    }
//  }
//
//  public void bar() {
//    for (int i = 0; i < n; i++) {
//      print("bar");
//    }
//  }
// }

// The same instance of FooBar will be passed to two different threads:
// thread A will call foo(), while
// thread B will call bar().
// Modify the given program to output "foobar" n times.

// Example 1:
// Input: n = 1
// Output: "foobar"
// Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
// "foobar" is being output 1 time.

// Example 2:
// Input: n = 2
// Output: "foobarfoobar"
// Explanation: "foobar" is being output 2 times.

class FooBar
{
private:
    int n;
    std::mutex foo_mutex;
    std::mutex bar_mutex;

public:
    FooBar(int n)
    {
        this->n = n;
        bar_mutex.lock();
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++) {
            foo_mutex.lock();
            printFoo();
            bar_mutex.unlock();
        }
    }

    void bar(function<void()> printBar)
    {    
        for (int i = 0; i < n; i++) {
            bar_mutex.lock();
            printBar();
            foo_mutex.unlock();
        }
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}