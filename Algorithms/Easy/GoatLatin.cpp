#include "../Helpers.hpp"

// You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
// We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

// If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
// For example, the word "apple" becomes "applema".
// If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
// For example, the word "goat" becomes "oatgma".
// Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
// For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
// Return the final sentence representing the conversion from sentence to Goat Latin.

// Example 1:
// Input: sentence = "I speak Goat Latin"
// Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

// Example 2:
// Input: sentence = "The quick brown fox jumped over the lazy dog"
// Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

class Solution
{
public:
    std::string extractWord(int& words_count, const std::string& sentence, int left, int right)
    {
        std::string word;
        word.reserve(right - left);
        char first_symbol = std::tolower(sentence[left]);
        if (first_symbol != 'a' && first_symbol != 'e' && first_symbol != 'i' && 
            first_symbol != 'o' && first_symbol != 'u') {
            word = std::string(begin(sentence) + left + 1, begin(sentence) + right);
            word += sentence[left];
        } else {
            word = std::string(begin(sentence) + left, begin(sentence) + right);
        }

        word += "ma";
        ++words_count;
        for (int i = 0; i < words_count; ++i)
            word += 'a';

        return word;
    }

    std::string toGoatLatin(std::string sentence)
    {
        std::string result;
        result.reserve(sentence.size());

        int startWordIdx = 0;
        int endWordIdx = startWordIdx;
        int words_count = 0;
        while (endWordIdx < sentence.size()) {
            const char symbol = sentence[endWordIdx];
            if (std::isspace(symbol)) {
                std::string word = extractWord(words_count, sentence, startWordIdx, endWordIdx);
                result += word;
                result += ' ';

                startWordIdx = ++endWordIdx;
            } else {
                ++endWordIdx;
            }
        }

        std::string word = extractWord(words_count, sentence, startWordIdx, endWordIdx);
        result += word;
        return result;
    }
};