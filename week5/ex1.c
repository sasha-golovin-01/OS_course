#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *myThread(int i) {
    printf(" >>Hello from Thread %d\n", i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t thread;

    int n, i;
    printf("Input number of threads: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (pthread_create(&thread, NULL, myThread, i)) {
            printf(" >>ERROR IN CREATING Thread #%d!\n", i);
            pthread_exit(NULL);
            return 1;
        }
        else {
            printf("Thread #%d created!\n", i);
            pthread_join(thread, NULL);
            printf("    >>Thread %d exit.\n", i);
        }
    }

    pthread_exit(NULL);

    return 0;
}
