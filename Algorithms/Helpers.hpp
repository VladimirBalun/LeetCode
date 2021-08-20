#pragma once

#include <list>
#include <vector>
#include <cassert>
#include <iostream>
#include <type_traits>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode* next;
    friend std::ostream& operator << (std::ostream& os, const ListNode* root);
};

inline std::ostream& operator << (std::ostream& os, const ListNode* root)
{
    std::cerr << "( ";
    while (root) {
        std::cerr << root->val << " -> ";
        root = root->next;
    }
    std::cerr << "null )";
    return os;
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T> vector)
{
    std::cerr << "[ ";
    for (const auto& element : vector) {
        std::cerr << element << ", ";
    }
    std::cerr << "]";
    return os;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const std::list<T> list)
{
    std::cerr << "( ";
    for (const auto& element : list) {
        std::cerr << element << " -> ";
    }
    std::cerr << "null )";
    return os;
}

namespace details {

    inline bool lists_are_equal(ListNode* lhs, ListNode* rhs)
    {
        while ((lhs) && (rhs)) {
            if (lhs->val != rhs->val) {
                return false;
            }
            lhs = lhs->next;
            rhs = rhs->next;
        }

        if ((!lhs) && (!rhs)) {
            return true;
        } else {
            return false;
        }
    }

    inline ListNode* make_list(std::initializer_list<int>&& values)
    {
        ListNode* root = nullptr;
        ListNode* node = nullptr;
        for (const auto& value : values) {
            if (!node) {
                root = node = new ListNode{ value, nullptr };
            } else {
                node->next = new ListNode{ value, nullptr };
                node = node->next;
            }
        }
        return root;
    }

    inline ListNode* make_linked_list_with_cycle(std::initializer_list<int>&& values, int value_for_loop)
    {
        ListNode* root = nullptr;
        ListNode* node = nullptr;
        ListNode* node_for_loop = nullptr;
        for (const auto& value : values) {
            ListNode* temp = new ListNode{ value, nullptr };
            if (value == value_for_loop) {
                node_for_loop = temp;
            }
            if (!node) {
                root = node = temp;
            } else {
                node->next = temp;
                node = node->next;
            }
        }
        if (root && node_for_loop) {
            node->next = node_for_loop;
        }
        return root;
    }

    inline void delete_list(ListNode* root)
    {
        while (root) {
            const ListNode* temp = root;
            root = root->next;
            delete temp;
        }
    }

    inline void delete_list_with_cycle(ListNode* root) {
        std::unordered_set<ListNode*> lookup;
        while (root && !lookup.count(root)) {
            const ListNode* temp = root;
            lookup.insert(root);
            root = root->next;
            delete temp;
        }
    }

}

namespace assert_details {

    template<typename Container, typename = std::enable_if_t<!std::is_arithmetic_v<Container>>>
    struct is_supported_container
    {
        static inline constexpr bool value =
            std::is_same_v<std::decay_t<Container>, std::vector<typename Container::value_type>> ||
            std::is_same_v<std::decay_t<Container>, std::list<typename Container::value_type>>;
    };

    template<typename T>
    std::enable_if_t<is_supported_container<T>::value>
    assert_equals_impl(T&& result, T&& expected, const std::string& file_line)
    {
        if (expected != result) {
            std::cerr << "Assertion failed: " << file_line << " - Expected: "
                      << expected << " Result: " << result << std::endl;
        }
    }

    template<typename T, typename U>
    std::enable_if_t<std::is_arithmetic_v<T>>
    assert_equals_impl(T result, U expected, const std::string& file_line)
    {
        if (expected != result) {
            std::cerr << "Assertion failed: " << file_line << " - Expected: "
                      << expected << " Result: " << result << std::endl;
        }
    }

    template<typename T>
    std::enable_if_t<std::is_same_v<std::decay_t<T>, ListNode*>>
    assert_equals_impl(T&& result, T&& expected, const std::string& file_line)
    {
        if (!details::lists_are_equal(expected, result)) {
            std::cerr << "Assertion failed: " << file_line << " - Expected: "
                      << expected << " Result: " << result << std::endl;
        }
    }

    template<typename T, typename U>
    void assert_equals(T&& result, U&& expected, const std::string& file_line)
    {
        static_assert(std::is_convertible_v<T, U>,
            "Types of the result and expected are not convertible.");
        assert_equals_impl(std::forward<T>(result), std::forward<U>(expected), file_line);
    }

}

#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ ":" S2(__LINE__)

#define ASSERT_EQUALS(result, expected) \
    assert_details::assert_equals((result), (expected), LOCATION)
