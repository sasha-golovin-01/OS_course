#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* ptr;

    printf("Type in the size N:\n");
    scanf("%d",&N);
    ptr = (int*)malloc(N * sizeof(int));

    if (ptr == NULL) {
        printf("Memory is not allocated\n");
        exit(0);
    }
    if (ptr != NULL) {
        printf("Memory is allocated successfully\n");
        for (int i = 0; i < N; i++) {
            ptr[i] = i + 1;
        }

        printf("Array of size %d consist of: ", N);
        for (int i = 0; i < N; i++) {
            printf("%d ", ptr[i]);
        }

        free(ptr);
        printf("\nMemory is deallocated successfully");
    }

    return 0;
}