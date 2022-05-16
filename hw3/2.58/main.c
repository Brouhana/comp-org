/*
 * Write a procedure is_little_endian that will return 1 when compiled and run
 * on a little-endian machine, and will return 0 when compiled and run on a
 * bigendian machine. This program should run on any machine, regardless of its
 * word size.
 */

#include <stdbool.h>
#include <stdio.h>

bool is_little_endian() {
    unsigned x = 1;
    return (char*)&x;
}

int main() {
    printf("%s", is_little_endian() ? "Little endian" : "Big endian");
    
    return 0;
}