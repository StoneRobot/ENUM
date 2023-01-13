#pragma once
#include "ENUM/ENUM.hpp"
#include <cstring>
#include <iostream>

// VC++需要选择“配置属性”>“C/C++”>“命令行”属性页。
// 修改“附加选项”属性以包含 /experimental:preprocessor，然后选择“确定”

ENUM(Enum1, char, (idleDown), idle, (idleUp, 2), (idleRight, -3), (idleLeft, 10), IDLE);

struct Example {
    ENUM(Enum2, char, (enum3), (enum4));
};

class ExampleClass {
    ENUM(Enum3, char, (enum5), (enum6));
};

int example()
{
    using namespace std;

    Enum1 x = Enum1::idleRight; // idleRight = -3
    char str1[] = "str";
    cout << std::boolalpha << str2Enum(str1, strlen(str1), x) << endl; // cout: false
    cout << x << endl; // cout: -3
    cout << enum2Str(x) << endl; // cout: idleRight
    cout << "------------------------" << endl;
    string str2 = "idleDown"; // 0
    cout << std::boolalpha << str2Enum(str2, x) << endl; // cout: true
    cout << x << endl; // cout: 0
    cout << enum2Str(x) << endl; // cout: idleDown
    cout << "name: " << getEnumName(x) << endl; // cout: name: Enum1
    cout << "------------------------" << endl;

    Example::Enum2 xx = Example::Enum2::enum3;
    char str3[] = "str";
    cout << std::boolalpha << Example::str2Enum(str3, strlen(str3), xx) << endl; // cout: false
    cout << xx << endl; // cout: 0
    cout << Example::enum2Str(xx) << endl; // cout: enum3
    cout << "------------------------" << endl;

    string str4 = "enum4"; // 1
    cout << std::boolalpha << Example::str2Enum(str4, xx) << endl; // cout: true
    cout << xx << endl; // cout: 1
    cout << Example::enum2Str(xx) << endl; // cout: enum4
    cout << "name: " << Example::getEnumName(xx) << endl; // cout: name: Enum2
    cout << "------------------------" << endl;
    return 0;
}