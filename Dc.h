#ifndef DC_H
#define DC_H

#define _CRT_SECURE_NO_WARNINGS

#ifdef DC_EXPORTS
    #define DC_API __declspec(dllexport)
#else
    #define DC_API __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 基础转换函数
DC_API char* text_to_binary(const char* text);
DC_API char* text_to_octal(const char* text);
DC_API char* text_to_decimal(const char* text);
DC_API char* text_to_hex(const char* text);
DC_API char* decimal_to_base(int n, int base);
DC_API char* text_to_base3(const char* text);
DC_API char* text_to_base4(const char* text);
DC_API char* text_to_base5(const char* text);
DC_API char* decimal_to_sexagesimal(int n);
DC_API char* text_to_morse(const char* text);
DC_API char* text_to_sexagesimal(const char* text);

#endif // DC_H