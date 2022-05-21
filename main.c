#include "my_printf.h"
#include <stdio.h>

int main () {
    char c = 5;
    void* p;
    p = &c;
    int a = 25;
    int b = 15;
    int d = 31;
    char u = 'z';
    char* s;
    s = "abcdef";

    char* x;
    x = 0;

    my_printf("Hello World!!!\nd = %d, u = %u, o = %o, x = %x, c = %c, char = %c, s = %s, p = %p\n", 100, -30, 12, 36, 'a', u, "Hello World!!!", p);
    int z = my_printf("a = %d, b = %o, d = %x, string = %s\n", a, b, d, s);
    int y = printf("a = %d, b = %o, d = %x, string = %s\n", a, b, d, s);

    my_printf("z = %d\n", z);
    my_printf("y = %d\n", y);
    my_printf("x = %s\n", x);
    printf("x = %s\n", x);
    return 0;
}