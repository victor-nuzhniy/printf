#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"


int my_putchar(char c) {
    return write (1, &c, 1);
}

int my_putstr(char* param_1) {
    int result = 0;
    while(*param_1) {
        my_putchar(*param_1);
        param_1++;
        result++;
    }
    return result;
}

char* convert_number(long long int number, char b) {
    long long int num = number;
    int base = 10;
    int j = 0;
    int remainder = 0;
    char* help;
    help = malloc(100000);
    char* result;
    result = malloc(100000);
    char sign = 0;
    if (num == 0) {
        *result = '0';
        return result;
    }
    if (b == 'o') {
        base = 8;
    }
    if (b == 'x') {
        base = 16;
    }
    if (num < 0) {
        sign = 1;
        num = num * -1;
    }
    while (num) {
        remainder = num % base;
        if ((remainder > 9) && (remainder < 16)) {
            *(help + j) = remainder + 87;
        }
        else {
            *(help + j) = remainder + 48;
        }
        num -= remainder;
        num /= base;
        j++;
    }
    j--;
    remainder = j;
    if ((sign == 1) && (b == 'd')) {
        *result = '-';
        result++;
    }
    while (j >= 0) {
        *(result + remainder - j) = *(help + j);
        j--;
    }
    return result;
}

int my_printf(char* restrict format, ...) {
    char* string;
    string = malloc(100000);
    char* f = format;
    int summ = 0;
    va_list sample;
    va_start(sample, format);
    while(*f != '\0') {
        if (*f != '%') {
            my_putchar(*f);
            summ++;
        }
        else {
            f++;
            if ((*f == 'd') || (*f == 'u') || (*f == 'o') || (*f == 'x')) {
                summ += my_putstr(convert_number(va_arg(sample, int), *f));
            }
            else if (*f == 'c') {
                my_putchar(va_arg(sample, int));
                summ++;
            }
            else if (*f == 's') {
                string = va_arg(sample, char*);
                if (!string) {
                    string = "(null)";
                }
                summ += my_putstr(string);
            }
            else if (*f == 'p') {
                summ += my_putstr(convert_number(va_arg(sample, long long), 'x'));
            }
            else {
                my_putchar('%');
                summ++;
                f--;
            }
        }
        f++;
    }
    va_end(sample);
    return summ;
}