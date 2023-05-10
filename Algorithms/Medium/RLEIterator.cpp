#include "../Helpers.hpp"

// We can use run-length encoding (i.e., RLE) to encode a sequence of integers. In a run-length encoded array of even length encoding (0-indexed), for all even i, encoding[i] tells us the number of times that the non-negative integer value encoding[i + 1] is repeated in the sequence.

// For example, the sequence arr = [8,8,8,5,5] can be encoded to be encoding = [3,8,2,5]. encoding = [3,8,0,9,2,5] and encoding = [2,8,1,8,2,5] are also valid RLE of arr.
// Given a run-length encoded array, design an iterator that iterates through it.

// Implement the RLEIterator class:
// RLEIterator(int[] encoded) Initializes the object with the encoded array encoded.
// int next(int n) Exhausts the next n elements and returns the last element exhausted in this way. If there is no element left to exhaust, return -1 instead.

// Example 1:
// Input
// ["RLEIterator", "next", "next", "next", "next"]
// [[[3, 8, 0, 9, 2, 5]], [2], [1], [1], [2]]
// Output
// [null, 8, 8, 5, -1]

// Explanation
// RLEIterator rLEIterator = new RLEIterator([3, 8, 0, 9, 2, 5]); // This maps to the sequence [8,8,8,5,5].
// rLEIterator.next(2); // exhausts 2 terms of the sequence, returning 8. The remaining sequence is now [8, 5, 5].
// rLEIterator.next(1); // exhausts 1 term of the sequence, returning 8. The remaining sequence is now [5, 5].
// rLEIterator.next(1); // exhausts 1 term of the sequence, returning 5. The remaining sequence is now [5].
// rLEIterator.next(2); // exhausts 2 terms, returning -1. This is because the first term exhausted was 5,
// but the second term did not exist. Since the last term exhausted does not exist, we return -1.

class RLEIterator
{
public:
    RLEIterator(const std::vector<int>& encoding)
    {
        m_encodings.reserve(encoding.size() / 2);
        for (int i = 0; i < encoding.size(); i += 2) {
            const int count = encoding[i];
            const int number = encoding[i + 1];
            m_encodings.emplace_back(count, number);
        }
    }
    
    int next(int n)
    {
        while (m_current_idx < m_encodings.size() && m_encodings[m_current_idx].first < n) {
            n -= m_encodings[m_current_idx].first;
            m_encodings[m_current_idx].first = 0;
            ++m_current_idx;
        }

        if (m_current_idx >= m_encodings.size())
            return -1;
        
        m_encodings[m_current_idx].first -= n;
        return m_encodings[m_current_idx].second;
    }

private:
    int m_current_idx = 0;
    std::vector<std::pair<int, int>> m_encodings;
};