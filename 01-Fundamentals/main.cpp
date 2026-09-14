#include <iostream>
using namespace std;

int main() {

    // ============================================================
    //                    C++ FUNDAMENTALS
    // ============================================================
    //
    // This file contains the basic things I learned while
    // starting with C++.
    //
    // I'm keeping everything in one file for now because it
    // makes it easier to come back and revise the basics.
    //
    // ============================================================


    // ------------------------------------------------------------
    // 1. VARIABLES
    // ------------------------------------------------------------
    //
    // A variable is simply a name given to some data.
    //
    // Here, age stores an integer value.
    //
    int age = 20;

    // I can change the value later because age is not constant.
    age = 21;

    cout << "Age: " << age << endl;


    // ------------------------------------------------------------
    // 2. BASIC DATA TYPES
    // ------------------------------------------------------------
    //
    // C++ has different data types depending on what kind of
    // value I want to store.
    //

    int number = 10;             // whole number
    double price = 99.99;        // decimal number
    char grade = 'A';             // single character
    bool isLearning = true;      // true or false

    cout << number << endl;
    cout << price << endl;
    cout << grade << endl;
    cout << isLearning << endl;


    // ------------------------------------------------------------
    // 3. CONSTANT
    // ------------------------------------------------------------
    //
    // If I don't want a value to change, I can use const.
    //
    // Trying to change PI after this would give an error.
    //

    const double PI = 3.14159;

    cout << "PI = " << PI << endl;


    // ------------------------------------------------------------
    // 4. sizeof()
    // ------------------------------------------------------------
    //
    // sizeof() tells me how much memory a data type or variable
    // takes, in bytes.
    //
    // The exact size of some types can depend on the system/compiler,
    // so I shouldn't blindly assume every machine will give the
    // same result.
    //

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " byte" << endl;


    // ------------------------------------------------------------
    // 5. TYPE CONVERSION
    // ------------------------------------------------------------
    //
    // Sometimes I need to convert one data type into another.
    //
    // Here an int is automatically converted to double.
    //

    int marks = 95;
    double convertedMarks = marks;

    cout << convertedMarks << endl;


    // ------------------------------------------------------------
    // 6. EXPLICIT TYPE CASTING
    // ------------------------------------------------------------
    //
    // I can also tell C++ to convert a value myself.
    //
    // static_cast is the C++ way of doing a normal explicit
    // conversion.
    //

    double value = 10.75;

    int convertedValue = static_cast<int>(value);

    // The .75 is removed.
    // This is not rounding. The result is simply 10.
    cout << convertedValue << endl;


    // ------------------------------------------------------------
    // 7. ARITHMETIC OPERATORS
    // ------------------------------------------------------------
    //
    // These are the operators I use for normal calculations.
    //
    // +   addition
    // -   subtraction
    // *   multiplication
    // /   division
    // %   remainder
    //

    int a = 10;
    int b = 3;

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Remainder: " << a % b << endl;


    // IMPORTANT:
    //
    // Since both a and b are integers, a / b performs integer
    // division.
    //
    // 10 / 3 = 3
    //
    // It does NOT give 3.333...


    // ------------------------------------------------------------
    // 8. RELATIONAL OPERATORS
    // ------------------------------------------------------------
    //
    // These operators compare two values.
    //
    // ==   equal to
    // !=   not equal to
    // >    greater than
    // <    less than
    // >=   greater than or equal to
    // <=   less than or equal to
    //

    cout << (a > b) << endl;
    cout << (a == b) << endl;


    // ------------------------------------------------------------
    // 9. LOGICAL OPERATORS
    // ------------------------------------------------------------
    //
    // Logical operators are mostly used when I have more than
    // one condition.
    //
    // &&   AND
    // ||   OR
    // !    NOT
    //

    int ageCheck = 20;

    cout << (ageCheck >= 18 && ageCheck <= 60) << endl;


    // ------------------------------------------------------------
    // 10. ASSIGNMENT OPERATORS
    // ------------------------------------------------------------
    //
    // The normal assignment operator is =
    //
    // There are also shortcuts like +=, -=, *= and /=.
    //

    int score = 10;

    score += 5;      // same as: score = score + 5
    score -= 2;      // same as: score = score - 2

    cout << "Score: " << score << endl;


    // ------------------------------------------------------------
    // 11. TAKING INPUT
    // ------------------------------------------------------------
    //
    // cin is used to take input from the user.
    //
    // The >> operator takes the value and puts it into the
    // variable.
    //

    int userNumber;

    cout << "Enter a number: ";
    cin >> userNumber;

    cout << "You entered: " << userNumber << endl;


    // ------------------------------------------------------------
    // 12. cout
    // ------------------------------------------------------------
    //
    // cout is used to print something on the screen.
    //
    // I can print text and variables together.
    //

    string name = "Lamon";

    cout << "Hello " << name << endl;


    // ------------------------------------------------------------
    // 13. getline()
    // ------------------------------------------------------------
    //
    // cin >> stops reading when it finds a space.
    //
    // So if I enter:
    //
    //     John Smith
    //
    // cin >> name would only take "John".
    //
    // getline() can read the complete line.
    //
    // Example:
    //
    // string fullName;
    // getline(cin, fullName);


    // ------------------------------------------------------------
    // 14. cin.ignore()
    // ------------------------------------------------------------
    //
    // One small problem I noticed while learning input:
    //
    // If I use cin >> something and then immediately use
    // getline(), the leftover newline can cause problems.
    //
    // In that situation, cin.ignore() can be used before getline().
    //
    // Example:
    //
    // int age;
    // string fullName;
    //
    // cin >> age;
    // cin.ignore();
    // getline(cin, fullName);
    //
    // This is something worth remembering because it can be
    // confusing when first learning C++ input.


    // ------------------------------------------------------------
    // 15. ESCAPE SEQUENCES
    // ------------------------------------------------------------
    //
    // Escape sequences are special characters written using
    // a backslash.
    //
    // \n  -> new line
    // \t  -> tab
    // \"  -> double quote
    // \\  -> backslash
    //

    cout << "Hello\nWorld" << endl;
    cout << "Name:\tLamon" << endl;


    // ============================================================
    // FINAL NOTE
    // ============================================================
    //
    // These topics look very basic, but I don't want to skip them.
    //
    // Variables, data types, operators and input/output are used
    // everywhere later in C++.
    //
    // The goal here is not just remembering the syntax.
    // I want to understand what the code is actually doing.
    //
    // Once these basics become comfortable, the next step is
    // control flow: if/else, loops, switch, and so on.
    //
    // ============================================================

    return 0;
}
```
