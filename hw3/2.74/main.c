/*
 * Write a function with the following prototype:
 * int tsub_ok (int x, int y);
 * This function should return 1 if the computation x - y does not overflow, 0 otherwise.
 */

#include <limits.h>
#include <stdio.h>

int tsub_ok (int x, int y) {
    /* Determine whether arguments can be subtracted without overflow 
        Reference:
        https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow#space-menu-link-content
    */
    if (((y > 0) && (x > INT_MAX - y)) || 
        ((y < 0) && (x < INT_MIN - y))) 
        return 0;

    return 1;
}

int main() {
    printf("%s", tsub_ok(444433434, 5) ? "Does not overflow" : "Overflows");
    
    return 0;
}