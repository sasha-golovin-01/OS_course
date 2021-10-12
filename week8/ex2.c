#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Exercise 2: from vm_stat we may observe that throttle amount is always 0,
 * si (here swipeins) has some values apart from 0, but so (here swipeouts) is almost 0 all of the time
 * as well as pageins and pageouts
 *
 * Excercise 3: PhysMemory, CPU usage and VM are increasing consequently
 */

int main() {
    int n = 10;
    int size = 10 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int* ptr = (int*)malloc(size);
        memset(ptr, 0, size);
        sleep(1);
    }

    return 0;
}
