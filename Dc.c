// Dc.c
#include "Dc.h"

#define MAX_BASE_DIGITS 32
#define BUFFER_SIZE 4096

// 通用进制转换函数
char* decimal_to_base(int n, int base) {
    if (base < 2 || base > 60) return NULL;

    char* result = malloc(MAX_BASE_DIGITS + 1);
    if (!result) return NULL;

    int index = MAX_BASE_DIGITS;
    result[index--] = '\0';

    if (n == 0) {
        result[index] = '0';
        char* final = strdup(&result[index]);
        free(result);
        return final;
    }

    while (n > 0 && index >= 0) {
        int remainder = n % base;
        result[index--] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        n /= base;
    }

    char* final = strdup(&result[index + 1]);
    free(result);
    return final;
}

// 二进制转换
char* text_to_binary(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_base((unsigned char)*text, 2);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 八进制转换
char* text_to_octal(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_base((unsigned char)*text, 8);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 十进制转换
char* text_to_decimal(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char temp[4];
        snprintf(temp, sizeof(temp), "%d", (unsigned char)*text);
        strncat(result, temp, BUFFER_SIZE - strlen(result) - 1);
        if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
    }
    return realloc(result, strlen(result) + 1);
}

// 十六进制转换
char* text_to_hex(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char temp[3];
        snprintf(temp, sizeof(temp), "%02x", (unsigned char)*text);
        strncat(result, temp, BUFFER_SIZE - strlen(result) - 1);
        if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
    }
    return realloc(result, strlen(result) + 1);
}

// 三进制转换
char* text_to_base3(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_base((unsigned char)*text, 3);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 四进制转换
char* text_to_base4(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_base((unsigned char)*text, 4);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 五进制转换
char* text_to_base5(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_base((unsigned char)*text, 5);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 六十进制转换
char* decimal_to_sexagesimal(int n) {
    return decimal_to_base(n, 60);
}

char* text_to_sexagesimal(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char* part = decimal_to_sexagesimal((unsigned char)*text);
        if (part) {
            strncat(result, part, BUFFER_SIZE - strlen(result) - 1);
            free(part);
            if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
        }
    }
    return realloc(result, strlen(result) + 1);
}

// 摩尔斯电码转换
typedef struct {
    char key;
    const char* value;
} MorseEntry;

// 修正后的 MORSE_CODE_TABLE 定义
const MorseEntry MORSE_CODE_TABLE[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'0', "-----"}, {',', "--..--"}, {'.', ".-.-.-"}, {'?', "..--.."}, {'/', "-..-."},
    {'-', "-....-"}, {'(', "-.--."}, {')', "-.--.-"}, {' ', "/"}, {0, NULL}
};

char* text_to_morse(const char* text) {
    char* result = calloc(BUFFER_SIZE, 1);
    if (!result) return NULL;

    for (; *text; text++) {
        char upper = toupper(*text);
        const char* code = "?";

        for (const MorseEntry* entry = MORSE_CODE_TABLE; entry->key; entry++) {
            if (entry->key == upper) {
                code = entry->value;
                break;
            }
        }

        strncat(result, code, BUFFER_SIZE - strlen(result) - 1);
        if (*(text + 1)) strncat(result, " ", BUFFER_SIZE - strlen(result) - 1);
    }
    return realloc(result, strlen(result) + 1);
}