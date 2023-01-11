#include "ENUM/ENUM.hpp"
#include <cstring>
#include <iostream>

// ENUM(Enum1, char, idleDown, idleUp, idleRight, idleLeft)

// struct Example {
//     ENUM(Enum2, char, enum3, enum4);
// };

// class ExampleClass {
//     ENUM(Enum3, char, enum5, enum6);
// };

// ENUM_TEST(Enum4, char, (ABC), (CBA, 2));


int example()
{
    // ENUM4 e4 = ENUM4::NN;
    using namespace std;
    // constexpr int PARAM_ENUM_2((X, 1));
    // cout << X << endl;
    // Enum1 x = Enum1::idleRight; // idleRight = 2
    // char str1[] = "str";
    // cout << std::boolalpha << str2Enum(str1, strlen(str1), x) << endl; // cout: false
    // cout << x << endl; // cout: 2
    // cout << enum2Str(x) << endl; // cout: idleRight
    // cout << "------------------------" << endl;
    // string str2 = "idleDown"; // 0
    // cout << std::boolalpha << str2Enum(str2, x) << endl; // cout: true
    // cout << x << endl; // cout: 0
    // cout << enum2Str(x) << endl; // cout: idleDown
    // cout << "name: " << getEnumName(x) << endl; // cout: name: Enum1
    // cout << "------------------------" << endl;

    // Example::Enum2 xx = Example::Enum2::enum3;
    // char str3[] = "str";
    // cout << std::boolalpha << Example::str2Enum(str3, strlen(str3), xx) << endl; // cout: false
    // cout << xx << endl; // cout: 0
    // cout << Example::enum2Str(xx) << endl; // cout: enum3
    // cout << "------------------------" << endl;

    // string str4 = "enum4"; // 1
    // cout << std::boolalpha << Example::str2Enum(str4, xx) << endl; // cout: true
    // cout << xx << endl; // cout: 1
    // cout << Example::enum2Str(xx) << endl; // cout: enum4
    // cout << "name: " << Example::getEnumName(xx) << endl; // cout: name: Enum2
    // cout << "------------------------" << endl;
    return 0;
}