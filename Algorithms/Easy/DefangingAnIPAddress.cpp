#include "../Helpers.hpp"

// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".

// Example 1:
// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"

// Example 2:
// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"

class Solution {
public:
	std::string defangIPaddr(std::string address)
	{
		std::string defangedAddress;
		defangedAddress.reserve(address.length() + 2u * 3u);

		for (size_t i = 0u; i < address.length(); ++i) {
			if (address[i] == '.') {
				defangedAddress += '[';
				defangedAddress += address[i];
				defangedAddress += ']';
			} else {
				defangedAddress += address[i];
			}
		}

		return defangedAddress;
	}
};