#include "../Helpers.hpp"

// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 
// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

class Trie
{
    struct TrieNode
    {
        bool leaf = false;
        std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    };

public:
    Trie() : root(std::make_unique<TrieNode>()) {}
    
    void insert(const std::string& word)
    {
        TrieNode* iterator = root.get();
        for (size_t i = 0u; i < key.length(); ++i) {
            const auto it = iterator->children.find(word[i]);
            if (it == end(iterator->children)) {
                TrieNode* node = new Node;
                iterator->children.emplace(word[i], node);
                iterator = node;
            } else {
                iterator = it->second.get();
            }
        }

        iterator->leaf = true;
    }
    
    bool search(const std::string& word) const
    {
        TrieNode* key_node = find_key_node(prefix);
        return key_node && key_node->leaf;
    }
    
    bool startsWith(const std::string& prefix) const
    {
        return find_key_node(prefix);
    }

private:
    TrieNode* find_key_node(const std::string& key) const
    {
        TrieNode* iterator = root.get();
        for (size_t i = 0u; i < key.length(); ++i) {
            const auto it = iterator->children.find(key[i]);
            if (it == end(iterator->children))
                return nullptr;

            iterator = it->second.get();
        }

        return iterator;
    }

private:
    std::unique_ptr<TrieNode> root;
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
