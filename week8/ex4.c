#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int size = 10 * 1024 * 1024;

    for (int i = 0; i < 10; i++) {
        int* ptr = (int*)malloc(size);
        memset(ptr, 0, size);

        struct rusage mem;
        getrusage(RUSAGE_SELF, &mem);
        printf("Memory Usage: %ld\n", mem.ru_maxrss);

        sleep(1);
    }
    return 0;
}
