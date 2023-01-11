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
#include "expandMacro.h"
#include <string>

// GCC 的宏不支持和‘(’连接， VC通过
// 选择“配置属性”>“C/C++”>“命令行”属性页。
// 修改“附加选项”属性以包含 /experimental:preprocessor，然后选择“确定”

#define PARAM_ENUM_1(X) X
#define PARAM_ENUM_2(X, Y) X = Y

#define COUNT(...) ARG_N(__VA_ARGS__)

#define PARAM_ENUM(X) ARG_CONCAT(ARG_CONCAT(PARAM_ENUM_, ARG_CONCAT(COUNT, X)), X)

#define EXPAND_AR0()
#define EXPAND_AR1(x) PARAM_ENUM(x)
#define EXPAND_AR2(x, ...) PARAM_ENUM(x), EXPAND_AR1(__VA_ARGS__)
#define EXPAND_AR3(x, ...) PARAM_ENUM(x), EXPAND_AR2(__VA_ARGS__)

#define EXPAND_2(...) ARG_CONCAT(EXPAND_AR, ARG_N(__VA_ARGS__))(__VA_ARGS__)

#define GET_PAR_1(X) X
#define GET_PAR_2(X, Y) X
#define GET_PAR(X) ARG_CONCAT(ARG_CONCAT(GET_PAR_, ARG_CONCAT(COUNT, X)), X)

#define TO_STR_(X) #X
#define TO_STR(X) TO_STR_(X)

#define E2S_(X)                    \
    case (GET_PAR(X)): {           \
        return TO_STR(GET_PAR(X)); \
    }

#define S2E_(X)                                                            \
    case (compute(0, TO_STR(GET_PAR(X)), STR_SIZE(TO_STR(GET_PAR(X))))): { \
        Enum = GET_PAR(X);                                                 \
        ret = true;                                                        \
        break;                                                             \
    }

#define ENUM_TEST(ENUM_NAME, TYPE, ...)                                       \
    enum ENUM_NAME : TYPE { EXPAND_2(__VA_ARGS__) };                          \
    const char* enum2Str(ENUM_NAME Enum)                                      \
    {                                                                         \
        switch (Enum) {                                                       \
            EXPAND(E2S_, __VA_ARGS__)                                         \
        default: {                                                            \
            break;                                                            \
        }                                                                     \
        }                                                                     \
        return nullptr;                                                       \
    }                                                                         \
    bool str2Enum(const char* str, const unsigned int& size, ENUM_NAME& Enum) \
    {                                                                         \
        bool ret = false;                                                     \
        unsigned int s = compute(0, str, size);                               \
        switch (s) {                                                          \
            EXPAND(S2E_, __VA_ARGS__)                                         \
        default: {                                                            \
            break;                                                            \
        }                                                                     \
        }                                                                     \
        return ret;                                                           \
    }                                                                         \
    bool str2Enum(const std::string& str, ENUM_NAME& Enum)                    \
    {                                                                         \
        return str2Enum(str.c_str(), str.length(), Enum);                     \
    }                                                                         \
    const char* getEnumName(ENUM_NAME& Enum)                                  \
    {                                                                         \
        return #ENUM_NAME;                                                    \
    }

/////////////////////////// GCC和VC通过
// 选择“配置属性”>“C/C++”>“命令行”属性页。
// 修改“附加选项”属性以包含 /experimental:preprocessor，然后选择“确定”。

#define E2S(x)     \
    case (x): {    \
        return #x; \
    }

#define S2E(x)                             \
    case (compute(0, #x, STR_SIZE(#x))): { \
        Enum = x;                          \
        ret = true;                        \
        break;                             \
    }

#define ENUM(ENUM_NAME, TYPE, ...)                                            \
    enum ENUM_NAME : TYPE { __VA_ARGS__ };                                    \
    const char* enum2Str(ENUM_NAME Enum)                                      \
    {                                                                         \
        switch (Enum) {                                                       \
            EXPAND(E2S, __VA_ARGS__)                                          \
        default: {                                                            \
            break;                                                            \
        }                                                                     \
        }                                                                     \
        return nullptr;                                                       \
    }                                                                         \
    bool str2Enum(const char* str, const unsigned int& size, ENUM_NAME& Enum) \
    {                                                                         \
        bool ret = false;                                                     \
        unsigned int s = compute(0, str, size);                               \
        switch (s) {                                                          \
            EXPAND(S2E, __VA_ARGS__)                                          \
        default: {                                                            \
            break;                                                            \
        }                                                                     \
        }                                                                     \
        return ret;                                                           \
    }                                                                         \
    bool str2Enum(const std::string& str, ENUM_NAME& Enum)                    \
    {                                                                         \
        return str2Enum(str.c_str(), str.length(), Enum);                     \
    }                                                                         \
    const char* getEnumName(ENUM_NAME& Enum)                                  \
    {                                                                         \
        return #ENUM_NAME;                                                    \
    }
