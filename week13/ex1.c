//
// Created by Саша Головин on 16.11.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    FILE* f = fopen("/Users/sasha/Documents/labas/input_dl.txt", "r");

    if (f == NULL) {
        printf ("Cannot open file.\n");
        exit(1);
    }

    int e[3], a[3], c[5][3], r[5][3], p[5];

    for (int i = 0; i < 3; i++) {
        fscanf(f, "%d", &e[i]);
    }

    for (int i = 0; i < 3; i++) {
        fscanf(f, "%d", &a[i]);
    }

    for (int i=0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(f, "%d", &c[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(f, "%d", &r[i][j]);
        }
    }

    while (true) {
        int lr = -1;
        for (int i = 0; i < 5; i++) {

            if (p[i] == 1) {
                continue;
            }

            bool isTrue = true;
            for (int j = 0; j < 3; j++) {
                if (r[i][j] > a[j]) {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue) {
                lr = i;
                break;
            }
        }

        if (lr == -1) {
            int dl = -1;  //checks f deadlock preserved
            for (int i = 0; i < 5; i++) {
                if (p[i] == 0) {
                    dl = i;
                    break;
                }
            }
            if(dl == -1) {
                printf("No deadlocks detected!\n");
            }
            else {
                printf("Deadlock on is detected on process %d\n", dl);
            }
            return 1;
        }

        for (int i = 0; i < 3; i++) {
            a[i] += c[lr][i];
        }

        p[lr] = 1;
    }

    return 0;
}
