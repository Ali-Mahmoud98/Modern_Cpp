#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    std::string name;
    int age;
};

// Predicate: Partition people into groups of adults and minors
bool isAdult(const Person& p) {
    return p.age >= 18;
}

int main() {
    std::vector<Person> people = {
        {"Alice", 17}, {"Bob", 22}, {"Charlie", 15}, {"David", 19}, {"Eve", 12}
    };

    // Partition people into adults and minors
    auto it = std::partition(people.begin(), people.end(), isAdult);

    // Output the partitioned people
    std::cout << "Adults:\n";
    for (auto i = people.begin(); i != it; ++i) {
        std::cout << i->name << " (" << i->age << ")\n";
    }

    std::cout << "\nMinors:\n";
    for (auto i = it; i != people.end(); ++i) {
        std::cout << i->name << " (" << i->age << ")\n";
    }

    return 0;
}
