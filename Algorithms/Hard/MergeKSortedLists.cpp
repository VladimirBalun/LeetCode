#include <queue>
#include <list>
#include <vector>
#include <utility>
#include <iostream>

std::list<int> merge_lists(const std::vector<std::list<int>>& lists)
{
    using iterator_t = std::list<int>::const_iterator;
    using iterator_with_index_t = std::pair<iterator_t, size_t>;
    static const auto comparator = [](const iterator_with_index_t& lhs, const iterator_with_index_t& rhs) {
        return *lhs.first > *rhs.first;
    };

    std::priority_queue<iterator_with_index_t, std::vector<iterator_with_index_t>, decltype(comparator)> iterators(comparator);
    for (size_t list_index = 0u; list_index < lists.size(); ++list_index) {
        if (!lists.at(list_index).empty()) {
            iterators.emplace(lists.at(list_index).cbegin(), list_index);
        }
    }

    std::list<int> sorted_list;
    while (!iterators.empty()) {
        auto current_iterator = iterators.top();
        sorted_list.push_back(*current_iterator.first);

        iterators.pop();
        if (++current_iterator.first != lists.at(current_iterator.second).cend()) {
            iterators.push(current_iterator);
        }
    }

    return sorted_list;
}

int main(int argc, char** argv)
{
    {
        std::vector<std::list<int>> lists{ { 1, 4, 5 }, { 1, 3, 4 }, { 2, 6 } };
        std::list<int> sorted_list = merge_lists(lists);
        for (const auto item : sorted_list) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    {
        std::vector<std::list<int>> lists{};
        std::list<int> sorted_list = merge_lists(lists);
        for (const auto item : sorted_list) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    {
        std::vector<std::list<int>> lists{ {} };
        std::list<int> sorted_list = merge_lists(lists);
        for (const auto item : sorted_list) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
