#include "../Helpers.hpp"

// Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.
// For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
// If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.
// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
// If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.
// For example, "m.y+name@email.com" will be forwarded to "my@email.com".
// It is possible to use both of these rules at the same time.
// Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.

// Example 1:
// Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
// Output: 2
// Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

// Example 2:
// Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
// Output: 3

class Solution
{
public:
    void replaceAll(std::string& str, const std::string& from, const std::string& to)
    {
        if(from.empty())
            return;

        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    }

    int numUniqueEmails(const std::vector<std::string>& emails)
    {
        if (emails.size() <= 1u) {
            return emails.size();
        }

        constexpr char separator = '@';
        constexpr char skip_letter = '.';
        constexpr char ignore_letter = '+';

        std::unordered_set<std::string> unique_emails;
        for (std::string email : emails) {
            const ssize_t separator_index = email.find(separator);
            std::string local = email.substr(0, separator_index);
            std::string rest = email.substr(separator_index, email.size() - 1u);
            if (const auto ignore_index = local.find(ignore_letter); ignore_index != std::string::npos) {
                local = local.substr(0, ignore_index);
            }
            replaceAll(local, ".", "");
            unique_emails.emplace(local + rest);
        }

        return unique_emails.size();
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
