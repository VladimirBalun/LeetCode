#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

class Foo
{
public:
    void first(std::function<void()> printFirst)
    {
        printFirst();
        ++m_print_state;
        m_notifier.notify_all();
    }

    void second(std::function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_notifier.wait(lock, [this]{ return m_print_state > 0; });
        printSecond();
        ++m_print_state;
        m_notifier.notify_one();
    }

    void third(std::function<void()> printThird)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_notifier.wait(lock, [this]{ return m_print_state > 1; });
        printThird();
    }
private:
    std::mutex m_mutex;
    std::atomic_int m_print_state = 0;
    std::condition_variable m_notifier;
};

int main(int argc, char** argv)
{
    const auto print_first = [] { std::cout << "first" << std::endl; };
    const auto print_second = [] { std::cout << "second" << std::endl; };
    const auto print_third = [] { std::cout << "third" << std::endl; };

    Foo foo;
    std::thread thread3(&Foo::third, &foo, print_third);
    std::thread thread2(&Foo::second, &foo, print_second);
    std::thread thread1(&Foo::first, &foo, print_first);
    thread1.join();
    thread2.join();
    thread3.join();

    return EXIT_SUCCESS;
}