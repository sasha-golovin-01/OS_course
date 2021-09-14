#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int process = fork();
    if (process == 0) {
        char command[128];
        while (1 == 1) {
            sleep(3);
            fgets(command, 126, stdin);
            system(command);
        }
    }

    return 0;
}
