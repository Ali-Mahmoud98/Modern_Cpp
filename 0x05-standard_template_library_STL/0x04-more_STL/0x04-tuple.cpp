#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

// Function to return a tuple containing student information
std::tuple<int, std::string, double> createStudent(int id, const std::string& name, double grade) {
    return std::make_tuple(id, name, grade);
}

// Function to display student information
void displayStudent(const std::tuple<int, std::string, double>& student) {
    std::cout << "ID: " << std::get<0>(student) 
              << ", Name: " << std::get<1>(student) 
              << ", Grade: " << std::get<2>(student) << std::endl;
}

// Function to compare two students by their grades
bool compareStudents(const std::tuple<int, std::string, double>& s1, 
                     const std::tuple<int, std::string, double>& s2) {
    return std::get<2>(s1) < std::get<2>(s2); // Compare by grade
}

int main() {
    // Basic usage: Creating tuples
    std::tuple<int, std::string, double> student1 = createStudent(101, "Alice", 88.5);
    std::tuple<int, std::string, double> student2 = createStudent(102, "Bob", 92.0);
    std::tuple<int, std::string, double> student3 = createStudent(103, "Charlie", 85.0);

    // Displaying student information
    std::cout << "Student Information:\n";
    displayStudent(student1);
    displayStudent(student2);
    displayStudent(student3);
    
    // Storing tuples in a vector for advanced operations
    std::vector<std::tuple<int, std::string, double>> students = { student1, student2, student3 };

    // Sorting students by grade using std::sort and a custom comparator
    std::sort(students.begin(), students.end(), compareStudents);
    
    std::cout << "\nStudents sorted by grade:\n";
    for (const auto& student : students) {
        displayStudent(student);
    }

    // Advanced feature: Structured bindings (C++17)
    std::cout << "\nUsing structured bindings:\n";
    for (const auto& student : students) {
        auto [id, name, grade] = student; // Unpacking tuple - available with ‘-std=c++17’
        std::cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << std::endl;
    }

    // Modifying a tuple element (creating a new tuple)
    std::tuple<int, std::string, double> updatedStudent1 = std::make_tuple(
        std::get<0>(student1), // ID remains the same
        std::get<1>(student1) + " Smith", // Updated name
        std::get<2>(student1) + 5.0 // Updated grade
    );

    std::cout << "\nUpdated Student Information:\n";
    displayStudent(updatedStudent1);

    return 0;
}
