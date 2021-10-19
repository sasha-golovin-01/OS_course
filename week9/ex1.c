#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * Outout files are fully following the given in chat of BS20-04 group
 * with following parameters:
 *
 * page frame = 10 (ex1_ou.txt)
 * page frame = 50 (ex2_ou.txt)
 * page frame = 100 (ex3_ou.txt)
 *
 * hit=0.000000 miss=1000.000000 ratio=0.000000 is given in output
 *
 * Made by Alexander Golovin, BS20-04
 */

typedef struct page{
    int id;
    uint16_t age;
} page;

int search(int n, int id, page frames[]){
    for (int i = 0; i < n; i++) {
        if (frames[i].id == id) {
            return i;
        }
    }

    return -1; //if not found
}

int main() {
    int n;
    printf("Num of page frames: ");
    scanf("%d", &n);
    page frames[n];

    for (int i = 0; i < n; i++) {
        frames[i].id = -1;
        frames[i].age = 0;
    }

    FILE* in = fopen("/Users/sasha/Documents/BootCamp/C/input.txt", "r");
    FILE* out = fopen("/Users/sasha/Documents/BootCamp/C/ex1_ou.txt", "w");
    int pageIdNow, isValid = 0;
    float miss = 0, hit = 0;

    while (!feof(in)) {
        isValid = fscanf(in, "%d", &pageIdNow);
        if (isValid != 1)
            continue;  //just to stop the reading and go out of cycle

        for (int i = 0; i < n; i++)
            fprintf(out, "i = %d  id = %d age = %d\n", i, frames[i].id, frames[i].age);

        fprintf(out, "current page number %d", pageIdNow);
        fprintf(out, "\n\n");

        for (int i = 0; i < n; i++)
            frames[i].age >>= 1;

        int currPos = search(n, pageIdNow, frames);
        if (currPos  == -1) {
            miss += 1;
            int pos = -1;

            for (int i = 0; i < n; i++)
                if (frames[i].id == -1)
                    pos = i;

            if (pos != -1) {
                frames[pos].id = currPos;
                frames[currPos].age |= 1 << (sizeof(uint16_t) * 8 - 1);
            }
            else {
                uint16_t min = UINT16_MAX;
                for (int i = 0; i < n; i++){
                    if (min >= frames[i].age) {
                        min = frames[i].age;
                        pos = i;
                    }
                }
                frames[pos].id = currPos;
                frames[pos].age = 0;
                frames[currPos].age |= 1 << (sizeof(uint16_t) * 8 - 1);
            }
        }
        else{
            hit++;
            frames[currPos].age |= 1 << (sizeof(uint16_t) * 8 - 1);
        }
    }

    printf("hit=%f miss=%f ratio=%f", hit, miss, hit / miss);
    return 0;
}