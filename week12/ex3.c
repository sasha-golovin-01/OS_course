#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <malloc.h>
#include <time.h>
#include <sys/resource.h>
#include <stdint.h>
#include <dirent.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct arr{
    int keys[6];
} arr;

void setDefault (arr s){
    for (int i = 0; i < 6; i++){
        s.keys[i] = -1;
    }
}

// Cappuccino phrase  C(46)-A(30)-P(25)

int cappuccino(arr s){
    int counter = 0; //counter of desirable keys
    for (int i = 0; i < 6; i++){
        if (s.keys[i] == 46) {
            counter++;
            break;
        }
    }
    for (int i=0; i<6; i++) {
        if (s.keys[i] == 30){
            counter++;
            break;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (s.keys[i] == 25) {
            counter++;
            break;
        }
    }
    if (counter == 3) {
        return 1;  // yes we have it
    }
    else {
        return 0; //no, we haven't'
    }
}

//exam phrase - P(25)-E(18)

int exam(arr s){
    int counter = 0;  //counter of desirable keys
    for (int i = 0; i < 6; i++) {
        if (s.keys[i] == 25) {
            counter++;
            break;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (s.keys[i] == 18){
            counter++;
            break;
        }
    }
    if (counter == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

//"Save your ass" phrase - S(31)-Y(21)-A(30)

int ass(arr s){
    int counter = 0;  //counter of desirable keys
    for (int i = 0; i < 6; i++) {
        if (s.keys[i] == 31) {
            counter++;
            break;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (s.keys[i] == 21) {
            counter++;
            break;
        }
    }
    for (int i = 0; i < 6; i++) {
        if(s.keys[i] == 30){
            counter++;
            break;
        }
    }
    if(counter == 3) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    FILE* output = fopen("./ex3.txt", "w+");
    arr s;
    int keyboard;
    struct input_event eve;

    keyboard = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

    if (keyboard == -1) {
        return -1;
    }

    printf("C+A+P - \"Get some cappuccino!\"\n");
    printf("P+E - \"I passed the Exam!\"\n");
    printf("S+Y+A - \"Save your ass!\"\n");
    fputs("C+A+P - \"Get some cappuccino!\"\n", output);
    fputs("P+E - \"I passed the Exam!\"\n", output);
    fputs("S+Y+A - \"Save your ass!\"\n", output);
    fflush(output);

    int it = 0;

    while(true) {
        read(keyboard, &eve, sizeof(eve));
        if (eve.type == EV_KEY) {
            if (eve.value == 0){
                for(int i = 0; i < 6; i++){
                    s.keys[i] = -1; //set as default
                }
                it = 0;
            }
            else if (eve.value == 1) {
                if (it > 5) {
                    it = 0;
                }
                s.keys[it] = (int)eve.code;
                it++;
                
                if (cappuccino(s)) {
                    printf("Taste some cappuccino!\n");
                    fputs("Taste some cappuccino!\n", output);
                }
                else if (exam(s)) {
                    printf("I passed the Exam!\n");
                    fputs("I passed the Exam!\n", output);
                }
                else if (ass(s)) {
                    printf("See you on retake!\n");
                    fputs("See you on retake!\n", output);
                }
                setDefault(s);
                it = 0;
                fflush(output);
            }
        }
    }

    return 0;
}
