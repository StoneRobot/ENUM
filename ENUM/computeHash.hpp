
#pragma once

#define STR_SIZE(STR) (sizeof(STR) - 1)

#define COMPUTE(SEED, STR, N) ((unsigned int)(SEED ^ STR[N] + 0x9e3779b9 + (SEED << 6) + (SEED >> 2)))

constexpr unsigned int compute(unsigned int&& seed, const char* val, int NUM)
{
    return NUM > 0 ? compute(COMPUTE(seed, val, NUM - 1), val, NUM - 1) : seed;
}
