#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <forward_list>
#include <set>
#include <deque>
#include <array>
#include <iterator>  // for std::iterator_traits

/**
 * C++ has a way to get information about the iterator types used in different algorithms and containers.
 * This is useful when writing templates or generic algorithms. Here’s how to work with iterator traits
 */
template <typename Iterator>
void printIteratorTraits() {
    typedef typename std::iterator_traits<Iterator>::iterator_category Category;
    if (std::is_same<Category, std::random_access_iterator_tag>::value) {
        std::cout << "Random Access Iterator\n";
    } else if (std::is_same<Category, std::bidirectional_iterator_tag>::value) {
        std::cout << "Bidirectional Iterator\n";
    } else if (std::is_same<Category, std::forward_iterator_tag>::value) {
        std::cout << "Forward Iterator\n";
    } else if (std::is_same<Category, std::input_iterator_tag>::value) {
        std::cout << "Input Iterator\n";
    } else if (std::is_same<Category, std::output_iterator_tag>::value) {
        std::cout << "Output Iterator\n";
    } else {
        std::cout << "Unknown Iterator Category\n";
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Testing the iterator traits
    std::cout << "************* Vector iterator traits *************" << std::endl;
    printIteratorTraits<std::vector<int>::const_iterator>();
    printIteratorTraits<std::vector<int>::iterator>();
    printIteratorTraits<std::vector<int>::reverse_iterator>();

    std::cout << "************* Map iterator traits *************" << std::endl;
    std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    printIteratorTraits<std::map<int, std::string>::iterator>();
    printIteratorTraits<std::map<int, std::string>::const_iterator>();
    printIteratorTraits<std::map<int, std::string>::reverse_iterator>();

    std::cout << "************* Forward list iterator traits *************" << std::endl;
    std::forward_list<int> list = {1, 2, 3, 4, 5};
    printIteratorTraits<std::forward_list<int>::iterator>();
    printIteratorTraits<std::forward_list<int>::const_iterator>();

    std::cout << "************* Set iterator traits *************" << std::endl;
    std::set<int> set = {1, 2, 3, 4, 5};
    printIteratorTraits<std::set<int>::iterator>();
    printIteratorTraits<std::set<int>::const_iterator>();

    std::cout << "************* Array iterator traits *************" << std::endl;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    printIteratorTraits<std::array<int, 5>::iterator>();
    printIteratorTraits<std::array<int, 5>::const_iterator>();

    std::cout << "************* Deque iterator traits *************" << std::endl;
    std::deque<int> deque = {1, 2, 3, 4, 5};
    printIteratorTraits<std::deque<int>::iterator>();
    printIteratorTraits<std::deque<int>::const_iterator>();

    std::cout << "************* List iterator traits *************" << std::endl;
    std::list<int> list2 = {1, 2, 3, 4, 5};
    printIteratorTraits<std::list<int>::iterator>();
    printIteratorTraits<std::list<int>::const_iterator>();

    return 0;
}
