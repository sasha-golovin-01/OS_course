#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t n = getpid();
    if (fork()) {
        printf("Hello from parent [%d - 811]\n", n);
    }
    else {
        printf("Hello from child [%d - 811]\n", n);
    }

    return 0;
}
