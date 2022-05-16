#include <stdio.h>

int main() {
    /* Create some arbitrary values */
    int x = 43;
    int y = 19;
    /* Convert to unsigned */
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    printf("%s", (x < y) == (-x > -y) ? "TRUE" : "FALSE");
    printf("\n%s", ((x + y) << 4) + y - x == 17*y + 15*x ? "TRUE" : "FALSE");
    printf("\n%s", ~x + ~y + 1 == ~(x+y) ? "TRUE" : "FALSE");
    printf("\n%s", (ux - uy) == -(unsigned) (y - x) ? "TRUE" : "FALSE");
    printf("\n%s", ((x >> 2) << 2) <= x ? "TRUE" : "FALSE");
    return 0;
}