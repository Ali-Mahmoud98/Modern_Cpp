#include <iostream>
//////////////////////////////////////////////////////////////////////////////////
// Start Traditional enum
//////////////////////////////////////////////////////////////////////////////////
enum Color {
    Red,
    Green,
    Blue,
    White = 10,
    Black,
    Yellow,
    Orange = 0,
    Purple
};

/**
 * uncomment the enum below and run and see the result
 * the errror will be like this: 
0x00-enum_enumClass.cpp:16:5: error: ‘Red’ conflicts with a previous declaration
   16 |     Red,
      |     ^~~
0x00-enum_enumClass.cpp:5:5: note: previous declaration ‘Color Red’
    5 |     Red,
 */
// enum Color2 {
//     Red, // this will cause error because Red is already defined
//     Green2,
//     Blue2
// };

namespace Color3 {
    enum Color {
        Red,
        Green,
        Blue
    };
}

/**
 * uncomment the namespace below and run and see the result
 * the errror will be like this:
0x00-enum_enumClass.cpp:38:11: error: ‘namespace Red { }’ redeclared as different kind of entity
   38 | namespace Red {
      |           ^~~
0x00-enum_enumClass.cpp:5:5: note: previous declaration ‘Color Red’
    5 |     Red,
      |     ^~~
 */
// namespace Red {
//     int x = 0;
// }

/**
 * uncomment the int Red = 5 below and run and see the result
the errror will be like this:
0x00-enum_enumClass.cpp:38:5: error: ‘int Red’ redeclared as different kind of entity
   38 | int Red = 5;
      |     ^~~
0x00-enum_enumClass.cpp:5:5: note: previous declaration ‘Color Red’
    5 |     Red,
      |  
 */
// int Red = 5; // will cause error because Red is already defined
//////////////////////////////////////////////////////////////////////////////////
// End Traditional enum
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// Start enum class
//////////////////////////////////////////////////////////////////////////////////
enum class Color2 {
    Red,
    Green,
    Blue
};

enum class Number {
    One,
    Two,
    Three
};

enum class Number2 {
    One,
    Two,
    Three
};

int One = 1;
int Two = 2;
int Three = 3;

enum class Animal : char {
    Dog,
    Cat
};

// overload output stream operator
std::ostream& operator<<(std::ostream& os, const Number& number) {
    switch (number) {
        case Number::One:
            os << "One";
            break;
        case Number::Two:
            os << "Two";
            break;
        case Number::Three:
            os << "Three";
            break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Number2& number) {
    switch (number) {
        case Number2::One:
            os << "One";
            break;
        case Number2::Two:
            os << "Two";
            break;
        case Number2::Three:
            os << "Three";
            break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Color2& color) {
    switch (color) {
        case Color2::Red:
            os << "Red";
            break;
        case Color2::Green:
            os << "Green";
            break;
        case Color2::Blue:
            os << "Blue";
            break;
    }
    return os;
}

int main() {
    //////////////////////////////////////////////////////////////////////////////////
    // Start Traditional enum
    //////////////////////////////////////////////////////////////////////////////////
    std::cout << "*********************************************************" << std::endl;
    std::cout << "***************** Start Traditional enum ****************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    Color favoriteColor = Green;
    // int Red = 5; // // Potential naming conflict. with Red in the following switch statement
    switch (favoriteColor) {
        case Red:
            std::cout << "Red" << std::endl;
            break;
        case Green:
            std::cout << "Green" << std::endl;
            break;
        case Blue:
            std::cout << "Blue" << std::endl;
            break;
    }
    std::cout << "Favorite color: " << favoriteColor << std::endl;
    std::cout << "Blue Color(Blue): " << Color(Blue) << std::endl;
    std::cout << "Red Color(Red): " << Color(Red) << std::endl;
    std::cout << "Green Color(Green): " << Color(Green) << std::endl;
    std::cout << "Green color: " << Green << std::endl;
    std::cout << "Red color: " << Red << std::endl;
    std::cout << "Blue color: " << Blue << std::endl;
    std::cout << "White color: " << White << std::endl;
    std::cout << "Black color: " << Black << std::endl;
    std::cout << "Yellow color: " << Yellow << std::endl;
    std::string state = (Orange == Red)? "true":"false";
    std::cout << "color: " << state << std::endl;
    state = (Purple == Green)? "true":"false";
    std::cout << "color: " << state << std::endl;
    std::cout << "Color3::Blue: " << Color3::Blue << std::endl;
    std::cout << "sizeof(Color): " << sizeof(Color) << " bytes" << std::endl;
    std::cout << "sizeof(Color3::Color): " << sizeof(Color3::Color) << " bytes" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << "****************** End Traditional enum ******************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    //////////////////////////////////////////////////////////////////////////////////
    // End Traditional enum
    //////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////
    // Start enum class
    //////////////////////////////////////////////////////////////////////////////////
    std::cout << "*********************************************************" << std::endl;
    std::cout << "****************** Start enum class *******************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    // the to print the enum class using cout we need to overload the output stream operator<<
    Color2 favoriteColor2 = Color2::Green;
    std::cout << "Favorite color: " << favoriteColor2 << std::endl;
    std::cout << "Blue Color2(Blue): " << Color2(Blue) << std::endl;
    std::cout << "Red Color2(Red): " << Color2(Red) << std::endl;
    std::cout << "Green Color2(Green): " << Color2(Green) << std::endl;
    Number number = Number::Two;
    std::cout << "Number: " << number << std::endl;
    Number2 number2 = Number2::Two;
    std::cout << "Number2: " << number2 << std::endl;
    std::cout << "Number::One -> " << Number::One << std::endl;
    // the enum class is type safe
    // if (Number2::One == Number::One) { // will cause error -> type safety
    //     std::cout << "Number is One" << std::endl;
    // }
    if (Number2::One == Number2::One)
    {
        std::cout << "Number2 is One" << std::endl;
    }

    // if (Number::One == 1)// error beacuse Number is enum class
    // {
    //     std::cout << "Number is One" << std::endl;
    // }
    if (int(Number2::One) == 1)
    {
        std::cout << "int(Number2::One) == 1" << std::endl;
    } else
    {
        std::cout << "int(Number2::One) = " << int(Number2::One) << std::endl;
    }
    
    if (static_cast<int>(Number2::One) == 1)
    {
        std::cout << "static_cast<int>(Number2::One) == 1" << std::endl;
    } else {
        std::cout << "static_cast<int>(Number2::One) = " << static_cast<int>(Number2::One) << std::endl;
    }

    if (static_cast<int>(Number::One) == static_cast<int>(Number2::One))
    {
        std::cout << "static_cast<int>(Number::One) == static_cast<int>(Number2::One" << std::endl;
    }

    std::cout << "sizeof(Color2): " << sizeof(Color2) << " bytes" << std::endl;
    std::cout << "sizeof(Number): " << sizeof(Number) << " bytes" << std::endl;
    std::cout << "sizeof(Number2): " << sizeof(Number2) << " bytes" << std::endl;
    std::cout << "sizeof(Animal): " << sizeof(Animal) << " bytes" << std::endl;

    return 0;
}
