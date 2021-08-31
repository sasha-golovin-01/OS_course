#include <stdio.h>
#include <math.h>

void ordinary_piramyd(int n) {
    int stars = 1;

    for (int i = 1; i <= n; i++) {
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
}

void reversed_pyramyd(int n) {
    int stars = 2 * n - 1;

    for (int i = 1; i <= n; i++) {
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
        stars -= 2;
    }
}

void left_corner(int n) {
    int stars = 1;

    for (int i = 1; i <= ceil(n / 2); i++) {
        for (int j = 1; j <= stars; j++) {
            printf("*");
        }
        printf("\n");
        stars += 1;
    }

    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= stars; j++) {
            printf("*");
        }
        printf("\n");
        stars -= 1;
    }
}

void square(int n) {
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int n, type;

    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    else {
        printf("Command line arguments expected.\n");
        return 0;
    }

    printf("Choose the type of figure to be printed: \n");
    printf("1 - ordinary pyramid\n");
    printf("2 - reversed pyramid\n");
    printf("3 - left-corner triangle\n");
    printf("4 - square\n");

    printf("Enter the number: ");
    scanf("%d", &type);

    if (type == 1) {
        ordinary_piramyd(n);
    }
    else if (type == 2) {
        reversed_pyramyd(n);
    }
    else if (type == 3) {
        left_corner(n);
    }
    else if (type == 4) {
        square(n);
    }

    return 0;
}
