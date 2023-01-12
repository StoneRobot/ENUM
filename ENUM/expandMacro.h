#pragma once

#define ARG_N_RESQ                              \
    63, 62, 61, 60,                             \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define ARG_N_M(                                      \
    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,      \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
    _61, _62, _63, N, ...) N

#define ARG_N_(...) \
    ARG_N_M(__VA_ARGS__)

#define ARG_N(...) \
    ARG_N_(0, ##__VA_ARGS__, ARG_N_RESQ)

#define EXPAND_ARG0()
#define EXPAND_ARG1(MACRO, x) MACRO(x, 0)
#define EXPAND_ARG2(MACRO, x, ...) MACRO(x, 1) EXPAND_ARG1(MACRO, __VA_ARGS__)
#define EXPAND_ARG3(MACRO, x, ...) MACRO(x, 2) EXPAND_ARG2(MACRO, __VA_ARGS__)
#define EXPAND_ARG4(MACRO, x, ...) MACRO(x, 3) EXPAND_ARG3(MACRO, __VA_ARGS__)
#define EXPAND_ARG5(MACRO, x, ...) MACRO(x, 4) EXPAND_ARG4(MACRO, __VA_ARGS__)
#define EXPAND_ARG6(MACRO, x, ...) MACRO(x, 5) EXPAND_ARG5(MACRO, __VA_ARGS__)
#define EXPAND_ARG7(MACRO, x, ...) MACRO(x, 6) EXPAND_ARG6(MACRO, __VA_ARGS__)
#define EXPAND_ARG8(MACRO, x, ...) MACRO(x, 7) EXPAND_ARG7(MACRO, __VA_ARGS__)
#define EXPAND_ARG9(MACRO, x, ...) MACRO(x, 8) EXPAND_ARG8(MACRO, __VA_ARGS__)
#define EXPAND_ARG10(MACRO, x, ...) MACRO(x, 9) EXPAND_ARG9(MACRO, __VA_ARGS__)
#define EXPAND_ARG11(MACRO, x, ...) MACRO(x, 10) EXPAND_ARG10(MACRO, __VA_ARGS__)
#define EXPAND_ARG12(MACRO, x, ...) MACRO(x, 11) EXPAND_ARG11(MACRO, __VA_ARGS__)
#define EXPAND_ARG13(MACRO, x, ...) MACRO(x, 12) EXPAND_ARG12(MACRO, __VA_ARGS__)
#define EXPAND_ARG14(MACRO, x, ...) MACRO(x, 13) EXPAND_ARG13(MACRO, __VA_ARGS__)
#define EXPAND_ARG15(MACRO, x, ...) MACRO(x, 14) EXPAND_ARG14(MACRO, __VA_ARGS__)
#define EXPAND_ARG16(MACRO, x, ...) MACRO(x, 15) EXPAND_ARG15(MACRO, __VA_ARGS__)
#define EXPAND_ARG17(MACRO, x, ...) MACRO(x, 16) EXPAND_ARG16(MACRO, __VA_ARGS__)
#define EXPAND_ARG18(MACRO, x, ...) MACRO(x, 17) EXPAND_ARG17(MACRO, __VA_ARGS__)
#define EXPAND_ARG19(MACRO, x, ...) MACRO(x, 18) EXPAND_ARG18(MACRO, __VA_ARGS__)
#define EXPAND_ARG20(MACRO, x, ...) MACRO(x, 19) EXPAND_ARG19(MACRO, __VA_ARGS__)
#define EXPAND_ARG21(MACRO, x, ...) MACRO(x, 20) EXPAND_ARG20(MACRO, __VA_ARGS__)
#define EXPAND_ARG22(MACRO, x, ...) MACRO(x, 21) EXPAND_ARG21(MACRO, __VA_ARGS__)
#define EXPAND_ARG23(MACRO, x, ...) MACRO(x, 22) EXPAND_ARG22(MACRO, __VA_ARGS__)
#define EXPAND_ARG24(MACRO, x, ...) MACRO(x, 23) EXPAND_ARG23(MACRO, __VA_ARGS__)
#define EXPAND_ARG25(MACRO, x, ...) MACRO(x, 24) EXPAND_ARG24(MACRO, __VA_ARGS__)
#define EXPAND_ARG26(MACRO, x, ...) MACRO(x, 25) EXPAND_ARG25(MACRO, __VA_ARGS__)
#define EXPAND_ARG27(MACRO, x, ...) MACRO(x, 26) EXPAND_ARG26(MACRO, __VA_ARGS__)
#define EXPAND_ARG28(MACRO, x, ...) MACRO(x, 27) EXPAND_ARG27(MACRO, __VA_ARGS__)
#define EXPAND_ARG29(MACRO, x, ...) MACRO(x, 28) EXPAND_ARG28(MACRO, __VA_ARGS__)
#define EXPAND_ARG30(MACRO, x, ...) MACRO(x, 29) EXPAND_ARG29(MACRO, __VA_ARGS__)
#define EXPAND_ARG31(MACRO, x, ...) MACRO(x, 30) EXPAND_ARG30(MACRO, __VA_ARGS__)
#define EXPAND_ARG32(MACRO, x, ...) MACRO(x, 31) EXPAND_ARG31(MACRO, __VA_ARGS__)
#define EXPAND_ARG33(MACRO, x, ...) MACRO(x, 32) EXPAND_ARG32(MACRO, __VA_ARGS__)
#define EXPAND_ARG34(MACRO, x, ...) MACRO(x, 33) EXPAND_ARG33(MACRO, __VA_ARGS__)
#define EXPAND_ARG35(MACRO, x, ...) MACRO(x, 34) EXPAND_ARG34(MACRO, __VA_ARGS__)
#define EXPAND_ARG36(MACRO, x, ...) MACRO(x, 35) EXPAND_ARG35(MACRO, __VA_ARGS__)
#define EXPAND_ARG37(MACRO, x, ...) MACRO(x, 36) EXPAND_ARG36(MACRO, __VA_ARGS__)
#define EXPAND_ARG38(MACRO, x, ...) MACRO(x, 37) EXPAND_ARG37(MACRO, __VA_ARGS__)
#define EXPAND_ARG39(MACRO, x, ...) MACRO(x, 38) EXPAND_ARG38(MACRO, __VA_ARGS__)
#define EXPAND_ARG40(MACRO, x, ...) MACRO(x, 39) EXPAND_ARG39(MACRO, __VA_ARGS__)
#define EXPAND_ARG41(MACRO, x, ...) MACRO(x, 40) EXPAND_ARG40(MACRO, __VA_ARGS__)
#define EXPAND_ARG42(MACRO, x, ...) MACRO(x, 41) EXPAND_ARG41(MACRO, __VA_ARGS__)
#define EXPAND_ARG43(MACRO, x, ...) MACRO(x, 42) EXPAND_ARG42(MACRO, __VA_ARGS__)
#define EXPAND_ARG44(MACRO, x, ...) MACRO(x, 43) EXPAND_ARG43(MACRO, __VA_ARGS__)
#define EXPAND_ARG45(MACRO, x, ...) MACRO(x, 44) EXPAND_ARG44(MACRO, __VA_ARGS__)
#define EXPAND_ARG46(MACRO, x, ...) MACRO(x, 45) EXPAND_ARG45(MACRO, __VA_ARGS__)
#define EXPAND_ARG47(MACRO, x, ...) MACRO(x, 46) EXPAND_ARG46(MACRO, __VA_ARGS__)
#define EXPAND_ARG48(MACRO, x, ...) MACRO(x, 47) EXPAND_ARG47(MACRO, __VA_ARGS__)
#define EXPAND_ARG49(MACRO, x, ...) MACRO(x, 48) EXPAND_ARG48(MACRO, __VA_ARGS__)
#define EXPAND_ARG50(MACRO, x, ...) MACRO(x, 49) EXPAND_ARG49(MACRO, __VA_ARGS__)
#define EXPAND_ARG51(MACRO, x, ...) MACRO(x, 50) EXPAND_ARG50(MACRO, __VA_ARGS__)
#define EXPAND_ARG52(MACRO, x, ...) MACRO(x, 51) EXPAND_ARG51(MACRO, __VA_ARGS__)
#define EXPAND_ARG53(MACRO, x, ...) MACRO(x, 52) EXPAND_ARG52(MACRO, __VA_ARGS__)
#define EXPAND_ARG54(MACRO, x, ...) MACRO(x, 53) EXPAND_ARG53(MACRO, __VA_ARGS__)
#define EXPAND_ARG55(MACRO, x, ...) MACRO(x, 54) EXPAND_ARG54(MACRO, __VA_ARGS__)
#define EXPAND_ARG56(MACRO, x, ...) MACRO(x, 55) EXPAND_ARG55(MACRO, __VA_ARGS__)
#define EXPAND_ARG57(MACRO, x, ...) MACRO(x, 56) EXPAND_ARG56(MACRO, __VA_ARGS__)
#define EXPAND_ARG58(MACRO, x, ...) MACRO(x, 57) EXPAND_ARG57(MACRO, __VA_ARGS__)
#define EXPAND_ARG59(MACRO, x, ...) MACRO(x, 58) EXPAND_ARG58(MACRO, __VA_ARGS__)
#define EXPAND_ARG60(MACRO, x, ...) MACRO(x, 59) EXPAND_ARG59(MACRO, __VA_ARGS__)
#define EXPAND_ARG61(MACRO, x, ...) MACRO(x, 60) EXPAND_ARG60(MACRO, __VA_ARGS__)
#define EXPAND_ARG62(MACRO, x, ...) MACRO(x, 61) EXPAND_ARG61(MACRO, __VA_ARGS__)
#define EXPAND_ARG63(MACRO, x, ...) MACRO(x, 62) EXPAND_ARG62(MACRO, __VA_ARGS__)

#define ARG_CONCAT_(l, r) l##r
#define ARG_CONCAT(l, r) ARG_CONCAT_(l, r)

#define EXPAND(MACRO, ...) ARG_CONCAT(EXPAND_ARG, ARG_N(__VA_ARGS__))(MACRO, __VA_ARGS__)

#define PP_BOOL(N) ARG_CONCAT(PP_BOOL_, N)
#define PP_BOOL_0 0
#define PP_BOOL_1 1
#define PP_BOOL_2 1
#define PP_BOOL_3 1
#define PP_BOOL_4 1
#define PP_BOOL_5 1
#define PP_BOOL_6 1
#define PP_BOOL_7 1
#define PP_BOOL_8 1
#define PP_BOOL_9 1
#define PP_BOOL_10 1
#define PP_BOOL_11 1
#define PP_BOOL_12 1
#define PP_BOOL_13 1
#define PP_BOOL_14 1
#define PP_BOOL_15 1
#define PP_BOOL_16 1
#define PP_BOOL_17 1
#define PP_BOOL_18 1
#define PP_BOOL_19 1
#define PP_BOOL_20 1
#define PP_BOOL_21 1
#define PP_BOOL_22 1
#define PP_BOOL_23 1
#define PP_BOOL_24 1
#define PP_BOOL_25 1
#define PP_BOOL_26 1
#define PP_BOOL_27 1
#define PP_BOOL_28 1
#define PP_BOOL_29 1
#define PP_BOOL_30 1
#define PP_BOOL_31 1
#define PP_BOOL_32 1
#define PP_BOOL_33 1
#define PP_BOOL_34 1
#define PP_BOOL_35 1
#define PP_BOOL_36 1
#define PP_BOOL_37 1
#define PP_BOOL_38 1
#define PP_BOOL_39 1
#define PP_BOOL_40 1
#define PP_BOOL_41 1
#define PP_BOOL_42 1
#define PP_BOOL_43 1
#define PP_BOOL_44 1
#define PP_BOOL_45 1
#define PP_BOOL_46 1
#define PP_BOOL_47 1
#define PP_BOOL_48 1
#define PP_BOOL_49 1
#define PP_BOOL_50 1
#define PP_BOOL_51 1
#define PP_BOOL_52 1
#define PP_BOOL_53 1
#define PP_BOOL_54 1
#define PP_BOOL_55 1
#define PP_BOOL_56 1
#define PP_BOOL_57 1
#define PP_BOOL_58 1
#define PP_BOOL_59 1
#define PP_BOOL_60 1
#define PP_BOOL_61 1
#define PP_BOOL_62 1
#define PP_BOOL_63 1