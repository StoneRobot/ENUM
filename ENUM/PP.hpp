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