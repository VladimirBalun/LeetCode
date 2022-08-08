#include "../Helpers.hpp"

// A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
// For example, the below binary watch reads "4:51".

// Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
// The hour must not contain a leading zero.

// For example, "01:00" is not valid. It should be "1:00".
// The minute must be consist of two digits and may contain a leading zero.
// For example, "10:2" is not valid. It should be "10:02".
 
// Example 1:
// Input: turnedOn = 1
// Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

// Example 2:
// Input: turnedOn = 9
// Output: []

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        constexpr size_t NUM_BITS = 10u;
        if (turnedOn > NUM_BITS)
            return {};
        
        std::vector<int> bits(NUM_BITS, 0);
        for (int i = (int)bits.size() - 1; i >= (int)bits.size() - turnedOn; --i)
            bits[i] = 1;
        
        std::vector<std::string> result;
        
        do {
            const int hour = bits[0] * 8 + bits[1] * 4 + bits[2] * 2 + bits[3];
            const int minute = bits[4] * 32 + bits[5] * 16 + bits[6] * 8 + 
                               bits[7] * 4 + bits[8] * 2 + bits[9];
            
            if (hour >= 0 && hour < 12 && minute >= 0 && minute < 60) {
                char buffer[5 + 1];
                sprintf(buffer, "%d:%02d", hour, minute);
                result.push_back(buffer);                
            }
        } while (std::next_permutation(begin(bits), end(bits)));
    
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}