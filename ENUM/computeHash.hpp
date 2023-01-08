/************************************计算HASH值********************************************/
#pragma once

// 返回字符串长度
#define STR_SIZE(STR) (sizeof(STR) - 1)
// Hash计算公式
#define COMPUTE(SEED, STR, N) ((unsigned int)(SEED ^ STR[N] + 0x9e3779b9 + (SEED << 6) + (SEED >> 2)))
// 字符串计算hash值
constexpr unsigned int compute(unsigned int&& seed, const char* val, int NUM)
{
    return NUM > 0 ? compute(COMPUTE(seed, val, NUM - 1), val, NUM - 1) : seed;
}
