说明：http://t.csdn.cn/CG5Rb

## 作用

1. 使用提供的ENUM宏定义enum后，提供函数，可以将enum转换为string，也可以通过string获取对应enum的值，定义和使用过程和直接使用enum关键字差不多。
2. 提供3个函数，如果不是使用ENUM宏定义的enum无法调用。

   *enum2Str（）*// enum转字符串

   *str2Enum（）* // 字符串转enum，没有返回false

   *getEnumName（）*// 获取enum类的名字

## ENUM接口解释

ENUM(Arg1, Arg2, Arg3...)

***Arg1***: 定义的enum的名称。

***Arg2***：enum类的类型。

***Arg3***...：enum类的成员，个数最多为63个。

## 演示

```cpp

#include"ENUM/ENUM.hpp"

#include<cstring>

#include<iostream>


// VC++需要选择“配置属性”>“C/C++”>“命令行”属性页。

// 修改“附加选项”属性以包含 /experimental:preprocessor，然后选择“确定”


ENUM(Enum1, char, (idleDown), idle, (idleUp, 2), (idleRight, -3), (idleLeft, 10), IDLE);


structExample {

    ENUM(Enum2, char, (enum3), (enum4));

};


classExampleClass {

    ENUM(Enum3, char, (enum5), (enum6));

};


intexample()

{

    usingnamespace std;


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

    return0;

}

```

## 原理

使用宏和和编译期计算功能，在编译期的时候对参数进行展开和计算，自动生成对应的函数，尽量减少运行时的时间和空间复杂度。

## CPP版本

运行测试版本 >= C++11。

## 使用成本分析

| 代价                                                                                                                                                                    | 运行和使用                                                                                                                                                                                                                                               | 待改进                                                                       |

| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------------------------------------------------------- |

| 1.增加编译时间，生成的目标文件会增大（可忽略不计）。`<br/>`2.宏可能会给调试增加难度。`<br/>`3. 如果两个不同的枚举量的hash相同，编译会报错（简单测试过63个参数，没遇到）。 | 1.运行时，字符串转enum时间复杂度和空间复杂度为n，和字符串的长度有关。enum转字符时间和空间复杂度为常数。`<br/>`2.线程安全。`<br/>`3.用ENUM定义枚举类型和直接使用enum差不多,用ENUM定义能得到普通的枚举类型同时，也会得到相应的函数。`<br/>`4.支持自定义顺序。 | 1.因为是使用宏来展开的，需要自己编写展开的宏，现在支持的最大枚举参数为63个。 |

# 代码分析

## 宏展开

1. 首先需要需要获取传进宏的枚举的参数的个数的数量。

   ```cpp

   /************************** 获取宏的参数个数 ********************/

   #defineARG_N(...) \

       ARG_N_(0, ##__VA_ARGS__, ARG_N_RESQ)


   #defineARG_N_(...) \

       ARG_N_M(__VA_ARGS__)


   #defineARG_N_M(                                      \

       _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,      \

       _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \

       _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \

       _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \

       _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \

       _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \

       _61, _62, _63, N, ...) N


   #define ARG_N_RESQ                              \

       63, 62, 61, 60,                             \

           59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \

           49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \

           39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \

           29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \

           19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \

           9, 8, 7, 6, 5, 4, 3, 2, 1, 0


   ```
2. 展开枚举的参数的宏，宏不支持递归，没想到优雅展开宏参数的写法，直接手动编写。

   ```cpp

   #defineEXPAND_ARG0()

   #defineEXPAND_ARG1(MACRO, x) MACRO(x, 0)

   #defineEXPAND_ARG2(MACRO, x, ...) MACRO(x, 1) EXPAND_ARG1(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG3(MACRO, x, ...) MACRO(x, 2) EXPAND_ARG2(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG4(MACRO, x, ...) MACRO(x, 3) EXPAND_ARG3(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG5(MACRO, x, ...) MACRO(x, 4) EXPAND_ARG4(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG6(MACRO, x, ...) MACRO(x, 5) EXPAND_ARG5(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG7(MACRO, x, ...) MACRO(x, 6) EXPAND_ARG6(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG8(MACRO, x, ...) MACRO(x, 7) EXPAND_ARG7(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG9(MACRO, x, ...) MACRO(x, 8) EXPAND_ARG8(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG10(MACRO, x, ...) MACRO(x, 9) EXPAND_ARG9(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG11(MACRO, x, ...) MACRO(x, 10) EXPAND_ARG10(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG12(MACRO, x, ...) MACRO(x, 11) EXPAND_ARG11(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG13(MACRO, x, ...) MACRO(x, 12) EXPAND_ARG12(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG14(MACRO, x, ...) MACRO(x, 13) EXPAND_ARG13(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG15(MACRO, x, ...) MACRO(x, 14) EXPAND_ARG14(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG16(MACRO, x, ...) MACRO(x, 15) EXPAND_ARG15(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG17(MACRO, x, ...) MACRO(x, 16) EXPAND_ARG16(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG18(MACRO, x, ...) MACRO(x, 17) EXPAND_ARG17(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG19(MACRO, x, ...) MACRO(x, 18) EXPAND_ARG18(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG20(MACRO, x, ...) MACRO(x, 19) EXPAND_ARG19(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG21(MACRO, x, ...) MACRO(x, 20) EXPAND_ARG20(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG22(MACRO, x, ...) MACRO(x, 21) EXPAND_ARG21(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG23(MACRO, x, ...) MACRO(x, 22) EXPAND_ARG22(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG24(MACRO, x, ...) MACRO(x, 23) EXPAND_ARG23(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG25(MACRO, x, ...) MACRO(x, 24) EXPAND_ARG24(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG26(MACRO, x, ...) MACRO(x, 25) EXPAND_ARG25(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG27(MACRO, x, ...) MACRO(x, 26) EXPAND_ARG26(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG28(MACRO, x, ...) MACRO(x, 27) EXPAND_ARG27(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG29(MACRO, x, ...) MACRO(x, 28) EXPAND_ARG28(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG30(MACRO, x, ...) MACRO(x, 29) EXPAND_ARG29(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG31(MACRO, x, ...) MACRO(x, 30) EXPAND_ARG30(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG32(MACRO, x, ...) MACRO(x, 31) EXPAND_ARG31(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG33(MACRO, x, ...) MACRO(x, 32) EXPAND_ARG32(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG34(MACRO, x, ...) MACRO(x, 33) EXPAND_ARG33(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG35(MACRO, x, ...) MACRO(x, 34) EXPAND_ARG34(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG36(MACRO, x, ...) MACRO(x, 35) EXPAND_ARG35(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG37(MACRO, x, ...) MACRO(x, 36) EXPAND_ARG36(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG38(MACRO, x, ...) MACRO(x, 37) EXPAND_ARG37(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG39(MACRO, x, ...) MACRO(x, 38) EXPAND_ARG38(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG40(MACRO, x, ...) MACRO(x, 39) EXPAND_ARG39(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG41(MACRO, x, ...) MACRO(x, 40) EXPAND_ARG40(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG42(MACRO, x, ...) MACRO(x, 41) EXPAND_ARG41(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG43(MACRO, x, ...) MACRO(x, 42) EXPAND_ARG42(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG44(MACRO, x, ...) MACRO(x, 43) EXPAND_ARG43(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG45(MACRO, x, ...) MACRO(x, 44) EXPAND_ARG44(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG46(MACRO, x, ...) MACRO(x, 45) EXPAND_ARG45(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG47(MACRO, x, ...) MACRO(x, 46) EXPAND_ARG46(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG48(MACRO, x, ...) MACRO(x, 47) EXPAND_ARG47(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG49(MACRO, x, ...) MACRO(x, 48) EXPAND_ARG48(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG50(MACRO, x, ...) MACRO(x, 49) EXPAND_ARG49(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG51(MACRO, x, ...) MACRO(x, 50) EXPAND_ARG50(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG52(MACRO, x, ...) MACRO(x, 51) EXPAND_ARG51(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG53(MACRO, x, ...) MACRO(x, 52) EXPAND_ARG52(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG54(MACRO, x, ...) MACRO(x, 53) EXPAND_ARG53(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG55(MACRO, x, ...) MACRO(x, 54) EXPAND_ARG54(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG56(MACRO, x, ...) MACRO(x, 55) EXPAND_ARG55(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG57(MACRO, x, ...) MACRO(x, 56) EXPAND_ARG56(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG58(MACRO, x, ...) MACRO(x, 57) EXPAND_ARG57(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG59(MACRO, x, ...) MACRO(x, 58) EXPAND_ARG58(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG60(MACRO, x, ...) MACRO(x, 59) EXPAND_ARG59(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG61(MACRO, x, ...) MACRO(x, 60) EXPAND_ARG60(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG62(MACRO, x, ...) MACRO(x, 61) EXPAND_ARG61(MACRO, __VA_ARGS__)

   #defineEXPAND_ARG63(MACRO, x, ...) MACRO(x, 62) EXPAND_ARG62(MACRO, __VA_ARGS__)



   ```
3. 使用上边写的宏，根据宏传入的参数个数获取对应的展开参数的宏

   ```cpp

   #defineARG_CONCAT_(l, r) l##r

   #defineARG_CONCAT(l, r) ARG_CONCAT_(l, r)


   #defineEXPAND(MACRO, ...) ARG_CONCAT(EXPAND_ARG, ARG_N(__VA_ARGS__))(MACRO, __VA_ARGS__)


   ```

## 计算字符串的hash值

在编译期将字符串转换为hash值，并且在运行将字符串转变为hash值去匹配。

```cpp

/************************************计算HASH值********************************************/

/************************************计算HASH值********************************************/

#pragmaonce


// 返回字符串长度

#define STR_SIZE(STR)(sizeof(STR)-1)

// Hash计算公式

#define COMPUTE(SEED,STR,N)((unsigned int)(SEED ^STR[N]+0x9e3779b9+(SEED <<6)+(SEED >>2)))

// 字符串计算hash值

constexprunsignedintcompute(unsignedint&&seed, constchar*val, intNUM)

{

    return NUM > 0 ? compute(COMPUTE(seed, val, NUM - 1), val, NUM - 1) : seed;

}

```

## ENUM宏

自动生成转换代码的ENUM宏。enum转字符串，展开时用E2S宏替换，返回字符串。字符串转enum时，展开是用S2E替换，将传入字符串转换为hash，然后匹配编译期生成的hash值，匹配到返回true。

```cpp

#pragmaonce

#include"PP.hpp"

#include"computeHash.hpp"

#include"expandMacro.h"

#include<string>


// GCC 的宏不支持和‘(’连接， VC通过

// 选择“配置属性”>“C/C++”>“命令行”属性页。

// 修改“附加选项”属性以包含 /experimental:preprocessor，然后选择“确定”


#define PARAM_ENUM_1(X) X,

#define PARAM_ENUM_2(X,Y) X = Y,


#define PARAM_ENUM_END_1(X) X

#define PARAM_ENUM_END_2(X,Y) X = Y


// 元组处理

#define CALL_FUN(FUN,X) FUN X

#define COUNT_BRACKET(...)ARG_N(__VA_ARGS__)

#define PP_BRACKET(...) __VA_ARGS__


#define PP_IF(FREE,THEN,ELSE)ARG_CONCAT(PP_IF_,PP_BOOL(FREE))(THEN, ELSE)

#define PP_IF_0(THEN,ELSE) ELSE

#define PP_IF_1(THEN,ELSE) THEN


#define PARAM_ENUM_IMPL_1(X,NUM)PP_IF(NUM,                            \

    (CALL_FUN(ARG_CONCAT(PARAM_ENUM_,CALL_FUN(COUNT_BRACKET, X)), X)),\

    (CALL_FUN(ARG_CONCAT(PARAM_ENUM_END_,CALL_FUN(COUNT_BRACKET, X)), X)))


#define PARAM_ENUM_IMPL_2(X,NUM)PP_IF(NUM,(PARAM_ENUM_1(X)),(PARAM_ENUM_END_1(X)))


#define PARAM_ENUM_IMPL(X,NUM)PP_IF(PP_IS_PARENS(X),(PARAM_ENUM_IMPL_1(X, NUM)),(PARAM_ENUM_IMPL_2(X, NUM)))

#define PARAM_ENUM(X,NUM)CALL_FUN(PP_BRACKET,CALL_FUN(PP_BRACKET,PARAM_ENUM_IMPL(X, NUM)))


#define GET_PAR_1(X) X

#define GET_PAR_2(X,Y) X

#define GET_PAR(X)CALL_FUN(ARG_CONCAT(GET_PAR_,CALL_FUN(COUNT_BRACKET, X)), X)


#define TO_STR_(X)#X

#define TO_STR(X)TO_STR_(X)

#define TUPLE_STR(X)TO_STR(GET_PAR(X))


#define E2S_(X,NUM)                                     \

    case(PP_IF(PP_IS_PARENS(X),GET_PAR(X), X)): {      \

        returnPP_IF(PP_IS_PARENS(X),TUPLE_STR(X),#X);\

    }


#define S2E_(X,NUM)                                                                                                   \

    case(compute(0,PP_IF(PP_IS_PARENS(X),TUPLE_STR(X),#X),STR_SIZE(PP_IF(PP_IS_PARENS(X),TUPLE_STR(X),#X)))): {\

        Enum =PP_IF(PP_IS_PARENS(X),GET_PAR(X), X);                                                                  \

        ret = true;                                                                                                    \

        break;                                                                                                         \

    }


#define ENUM(ENUM_NAME,TYPE,...)                                                   \

    enum ENUM_NAME: TYPE { EXPAND(PARAM_ENUM, __VA_ARGS__) };                       \

    static const char* enum2Str(ENUM_NAMEEnum)                                      \

    {                                                                                \

        switch(Enum){                                                              \

            EXPAND(E2S_, __VA_ARGS__)                                                \

        default:{                                                                   \

            break;                                                                   \

        }                                                                            \

        }                                                                            \

        return nullptr;                                                              \

    }                                                                                \

    static bool str2Enum(const char* str, const unsigned int& size,ENUM_NAME& Enum)\

    {                                                                                \

        bool ret = false;                                                            \

        unsigned int s =compute(0, str, size);                                      \

        switch(s){                                                                 \

            EXPAND(S2E_, __VA_ARGS__)                                                \

        default:{                                                                   \

            break;                                                                   \

        }                                                                            \

        }                                                                            \

        return ret;                                                                  \

    }                                                                                \

    static bool str2Enum(const std::string& str,ENUM_NAME& Enum)                    \

    {                                                                                \

        returnstr2Enum(str.c_str(),str.length(), Enum);                            \

    }                                                                                \

    static const char* getEnumName(ENUM_NAME& Enum)                                  \

    {                                                                                \

        return#ENUM_NAME;                                                           \

    }

```

## 仓库地址

[github仓库地址](https://github.com/StoneRobot/ENUM)

[gitee仓库地址](https://gitee.com/stStone/ENUM)

> 《C++标准库（第二版）》

> https://zhuanlan.zhihu.com/p/152354031
>
