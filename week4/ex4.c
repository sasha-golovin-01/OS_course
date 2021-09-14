#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[128];
    int f, now;

    while (1 == 1) {
        f = fork();
        fgets(command, 126, stdin);
        if (f == 0) { //if the proccess is child
            argv[2] = command;
            execvp("/bin/sh", argv);
        }
        else {   //otherwise
            while (wait(&now) != f);
        }
    }

    return 0;
}
