#include "../Helpers.hpp"

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// Example 1:
// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

class MedianFinder
{
public:
    MedianFinder() = default;
    
    void addNum(int num)
    {
        small_heap.push(num);
        if (!small_heap.empty() && !large_heap.empty() && small_heap.top() > large_heap.top()) {
            large_heap.push(small_heap.top());
            small_heap.pop();            
        }

        if (small_heap.size() > large_heap.size() + 1) {
            large_heap.push(small_heap.top());
            small_heap.pop();
        } else if (large_heap.size() > small_heap.size() + 1) {
            small_heap.push(large_heap.top());
            large_heap.pop();            
        }
    }
    
    double findMedian()
    {
        if (small_heap.size() > large_heap.size())
            return small_heap.top();
        else if (small_heap.size() < large_heap.size())
            return large_heap.top();
        else
            return static_cast<double>(small_heap.top() + large_heap.top()) / 2;
    }

private:
    std::priority_queue<int> small_heap;
    std::priority_queue<int, std::vector<int>, std::greater<>> large_heap;
};