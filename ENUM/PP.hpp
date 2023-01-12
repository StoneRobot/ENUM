#pragma once

// 符号拼接
#define PP_CONCAT(A, B) PP_CONCAT_IMPL(A, B)
#define PP_CONCAT_IMPL(A, B) A##B

// 逻辑运算
#define PP_NOT(N) PP_CONCAT(PP_NOT_, N)
#define PP_NOT_0 1
#define PP_NOT_1 0

#define PP_AND(A, B) PP_CONCAT(PP_AND_, PP_CONCAT(A, B))
#define PP_AND_00 0
#define PP_AND_01 0
#define PP_AND_10 0
#define PP_AND_11 1

#define PP_GET_N_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) _8
// PP_HAS_COMMA() 用于检查变长参数里 有没有逗号（原理类似下文的 PP_NARG()）

#define PP_HAS_COMMA(...) PP_GET_N_8(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 0, 0)
// PP_COMMA_V() 用于 吃掉(eat) 变长参数，并返回一个 逗号
#define PP_COMMA_V(...) ,

// 长度判空
#define PP_IS_EMPTY(...)                                                                   \
    PP_AND(PP_AND(PP_NOT(PP_HAS_COMMA(__VA_ARGS__)), PP_NOT(PP_HAS_COMMA(__VA_ARGS__()))), \
        PP_AND(PP_NOT(PP_HAS_COMMA(PP_COMMA_V __VA_ARGS__)), PP_HAS_COMMA(PP_COMMA_V __VA_ARGS__())))

#define PP_EMPTY_V(...)
#define PP_IS_PARENS(SYMBOL) PP_IS_EMPTY(PP_EMPTY_V SYMBOL)

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