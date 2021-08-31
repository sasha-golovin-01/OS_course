#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, j, n, stars;

    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    else {
        printf("Command line arguments expected.\n");
    }

    stars = 1;

    for (i = 1; i <= n; i++) {
        int space = (2 * n - 1 - stars) / 2;
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= stars; j++) {
            printf("*");
        }
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        printf("\n");
        stars += 2;
    }

    return 0;
}
