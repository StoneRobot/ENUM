/*BSD 3-Clause License

Copyright (c) 2023, STONE(STSZ)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#pragma once
#include "computeHash.hpp"
#include "expandMalloc.h"
#include <string>

// enum转string的宏
#define E2S(x)     \
    case (x): {    \
        return #x; \
    }

// string转enum的宏，计算得到string的hash值，根据case获得enum
#define S2E(x)                             \
    case (compute(0, #x, STR_SIZE(#x))): { \
        Enum = x;                          \
        ret = true;                        \
        break;                             \
    }

#define ENUM(ENUM_NAME, TYPE, ...)                                                   \
    enum ENUM_NAME : TYPE { __VA_ARGS__ };                                           \
    /*enum 转 string*/                                                              \
    static const char* enum2Str(ENUM_NAME Enum)                                      \
    {                                                                                \
        /*使用EXPAND根据宏的参数替换代码，下同*/                      \
        switch (Enum) {                                                              \
            EXPAND(E2S, __VA_ARGS__)                                                 \
        }                                                                            \
        return nullptr;                                                              \
    }                                                                                \
    /*根据字符串获取enum值，如果enum中没有这个元素，返回false*/ \
    static bool str2Enum(const char* str, const unsigned int& size, ENUM_NAME& Enum) \
    {                                                                                \
        bool ret = false;                                                            \
        unsigned int s = compute(0, str, size);                                      \
        switch (s) {                                                                 \
            EXPAND(S2E, __VA_ARGS__)                                                 \
        }                                                                            \
        return ret;                                                                  \
    }                                                                                \
    static bool str2Enum(const std::string& str, ENUM_NAME& Enum)                    \
    {                                                                                \
        return str2Enum(str.c_str(), str.length(), Enum);                            \
    }                                                                                \
    static const char* getEnumName(ENUM_NAME& Enum)                                  \
    {                                                                                \
        return #ENUM_NAME;                                                           \
    }
