#pragma once
/******************** 宏展开 **********************************/

/************************** 获取宏的参数个数 ********************/
#define ARG_N(...) \
    ARG_N_(0, ##__VA_ARGS__, ARG_N_RESQ)

#define ARG_N_(...) \
    ARG_N_M(__VA_ARGS__)

#define ARG_N_M(                                      \
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

/************************** 将宏的参数展开 ********************/
#define EXPAND_ARG0()
#define EXPAND_ARG1(MACRO, x) MACRO(x)
#define EXPAND_ARG2(MACRO, x, ...) MACRO(x) EXPAND_ARG1(MACRO, __VA_ARGS__)
#define EXPAND_ARG3(MACRO, x, ...) MACRO(x) EXPAND_ARG2(MACRO, __VA_ARGS__)
#define EXPAND_ARG4(MACRO, x, ...) MACRO(x) EXPAND_ARG3(MACRO, __VA_ARGS__)
#define EXPAND_ARG5(MACRO, x, ...) MACRO(x) EXPAND_ARG4(MACRO, __VA_ARGS__)
#define EXPAND_ARG6(MACRO, x, ...) MACRO(x) EXPAND_ARG5(MACRO, __VA_ARGS__)
#define EXPAND_ARG7(MACRO, x, ...) MACRO(x) EXPAND_ARG6(MACRO, __VA_ARGS__)
#define EXPAND_ARG8(MACRO, x, ...) MACRO(x) EXPAND_ARG7(MACRO, __VA_ARGS__)
#define EXPAND_ARG9(MACRO, x, ...) MACRO(x) EXPAND_ARG8(MACRO, __VA_ARGS__)
#define EXPAND_ARG10(MACRO, x, ...) MACRO(x) EXPAND_ARG9(MACRO, __VA_ARGS__)
#define EXPAND_ARG11(MACRO, x, ...) MACRO(x) EXPAND_ARG10(MACRO, __VA_ARGS__)
#define EXPAND_ARG12(MACRO, x, ...) MACRO(x) EXPAND_ARG11(MACRO, __VA_ARGS__)
#define EXPAND_ARG13(MACRO, x, ...) MACRO(x) EXPAND_ARG12(MACRO, __VA_ARGS__)
#define EXPAND_ARG14(MACRO, x, ...) MACRO(x) EXPAND_ARG13(MACRO, __VA_ARGS__)
#define EXPAND_ARG15(MACRO, x, ...) MACRO(x) EXPAND_ARG14(MACRO, __VA_ARGS__)
#define EXPAND_ARG16(MACRO, x, ...) MACRO(x) EXPAND_ARG15(MACRO, __VA_ARGS__)
#define EXPAND_ARG17(MACRO, x, ...) MACRO(x) EXPAND_ARG16(MACRO, __VA_ARGS__)
#define EXPAND_ARG18(MACRO, x, ...) MACRO(x) EXPAND_ARG17(MACRO, __VA_ARGS__)
#define EXPAND_ARG19(MACRO, x, ...) MACRO(x) EXPAND_ARG18(MACRO, __VA_ARGS__)
#define EXPAND_ARG20(MACRO, x, ...) MACRO(x) EXPAND_ARG19(MACRO, __VA_ARGS__)
#define EXPAND_ARG21(MACRO, x, ...) MACRO(x) EXPAND_ARG20(MACRO, __VA_ARGS__)
#define EXPAND_ARG22(MACRO, x, ...) MACRO(x) EXPAND_ARG21(MACRO, __VA_ARGS__)
#define EXPAND_ARG23(MACRO, x, ...) MACRO(x) EXPAND_ARG22(MACRO, __VA_ARGS__)
#define EXPAND_ARG24(MACRO, x, ...) MACRO(x) EXPAND_ARG23(MACRO, __VA_ARGS__)
#define EXPAND_ARG25(MACRO, x, ...) MACRO(x) EXPAND_ARG24(MACRO, __VA_ARGS__)
#define EXPAND_ARG26(MACRO, x, ...) MACRO(x) EXPAND_ARG25(MACRO, __VA_ARGS__)
#define EXPAND_ARG27(MACRO, x, ...) MACRO(x) EXPAND_ARG26(MACRO, __VA_ARGS__)
#define EXPAND_ARG28(MACRO, x, ...) MACRO(x) EXPAND_ARG27(MACRO, __VA_ARGS__)
#define EXPAND_ARG29(MACRO, x, ...) MACRO(x) EXPAND_ARG28(MACRO, __VA_ARGS__)
#define EXPAND_ARG30(MACRO, x, ...) MACRO(x) EXPAND_ARG29(MACRO, __VA_ARGS__)
#define EXPAND_ARG31(MACRO, x, ...) MACRO(x) EXPAND_ARG30(MACRO, __VA_ARGS__)
#define EXPAND_ARG32(MACRO, x, ...) MACRO(x) EXPAND_ARG31(MACRO, __VA_ARGS__)
#define EXPAND_ARG33(MACRO, x, ...) MACRO(x) EXPAND_ARG32(MACRO, __VA_ARGS__)
#define EXPAND_ARG34(MACRO, x, ...) MACRO(x) EXPAND_ARG33(MACRO, __VA_ARGS__)
#define EXPAND_ARG35(MACRO, x, ...) MACRO(x) EXPAND_ARG34(MACRO, __VA_ARGS__)
#define EXPAND_ARG36(MACRO, x, ...) MACRO(x) EXPAND_ARG35(MACRO, __VA_ARGS__)
#define EXPAND_ARG37(MACRO, x, ...) MACRO(x) EXPAND_ARG36(MACRO, __VA_ARGS__)
#define EXPAND_ARG38(MACRO, x, ...) MACRO(x) EXPAND_ARG37(MACRO, __VA_ARGS__)
#define EXPAND_ARG39(MACRO, x, ...) MACRO(x) EXPAND_ARG38(MACRO, __VA_ARGS__)
#define EXPAND_ARG40(MACRO, x, ...) MACRO(x) EXPAND_ARG39(MACRO, __VA_ARGS__)
#define EXPAND_ARG41(MACRO, x, ...) MACRO(x) EXPAND_ARG40(MACRO, __VA_ARGS__)
#define EXPAND_ARG42(MACRO, x, ...) MACRO(x) EXPAND_ARG41(MACRO, __VA_ARGS__)
#define EXPAND_ARG43(MACRO, x, ...) MACRO(x) EXPAND_ARG42(MACRO, __VA_ARGS__)
#define EXPAND_ARG44(MACRO, x, ...) MACRO(x) EXPAND_ARG43(MACRO, __VA_ARGS__)
#define EXPAND_ARG45(MACRO, x, ...) MACRO(x) EXPAND_ARG44(MACRO, __VA_ARGS__)
#define EXPAND_ARG46(MACRO, x, ...) MACRO(x) EXPAND_ARG45(MACRO, __VA_ARGS__)
#define EXPAND_ARG47(MACRO, x, ...) MACRO(x) EXPAND_ARG46(MACRO, __VA_ARGS__)
#define EXPAND_ARG48(MACRO, x, ...) MACRO(x) EXPAND_ARG47(MACRO, __VA_ARGS__)
#define EXPAND_ARG49(MACRO, x, ...) MACRO(x) EXPAND_ARG48(MACRO, __VA_ARGS__)
#define EXPAND_ARG50(MACRO, x, ...) MACRO(x) EXPAND_ARG49(MACRO, __VA_ARGS__)
#define EXPAND_ARG51(MACRO, x, ...) MACRO(x) EXPAND_ARG50(MACRO, __VA_ARGS__)
#define EXPAND_ARG52(MACRO, x, ...) MACRO(x) EXPAND_ARG51(MACRO, __VA_ARGS__)
#define EXPAND_ARG53(MACRO, x, ...) MACRO(x) EXPAND_ARG52(MACRO, __VA_ARGS__)
#define EXPAND_ARG54(MACRO, x, ...) MACRO(x) EXPAND_ARG53(MACRO, __VA_ARGS__)
#define EXPAND_ARG55(MACRO, x, ...) MACRO(x) EXPAND_ARG54(MACRO, __VA_ARGS__)
#define EXPAND_ARG56(MACRO, x, ...) MACRO(x) EXPAND_ARG55(MACRO, __VA_ARGS__)
#define EXPAND_ARG57(MACRO, x, ...) MACRO(x) EXPAND_ARG56(MACRO, __VA_ARGS__)
#define EXPAND_ARG58(MACRO, x, ...) MACRO(x) EXPAND_ARG57(MACRO, __VA_ARGS__)
#define EXPAND_ARG59(MACRO, x, ...) MACRO(x) EXPAND_ARG58(MACRO, __VA_ARGS__)
#define EXPAND_ARG60(MACRO, x, ...) MACRO(x) EXPAND_ARG59(MACRO, __VA_ARGS__)
#define EXPAND_ARG61(MACRO, x, ...) MACRO(x) EXPAND_ARG60(MACRO, __VA_ARGS__)
#define EXPAND_ARG62(MACRO, x, ...) MACRO(x) EXPAND_ARG61(MACRO, __VA_ARGS__)
#define EXPAND_ARG63(MACRO, x, ...) MACRO(x) EXPAND_ARG62(MACRO, __VA_ARGS__)

#define ARG_CONCAT_(l, r) l##r
#define ARG_CONCAT(l, r) ARG_CONCAT_(l, r)

/************************** 对外调用的接口 ********************/
/******** 拼接前缀EXPAND_ARG和对应的数字，获得对应的用于展开的宏 ***********/
#define EXPAND(MACRO, ...) ARG_CONCAT(EXPAND_ARG, ARG_N(__VA_ARGS__))(MACRO, __VA_ARGS__)
