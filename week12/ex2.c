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
#include <stdbool>

int main(){
     int keyboard;
    struct input_event ev;
    keyboard = open("/dev/input/by-path/platform-i8042-serio-0-ev-kbd", O_RDONLY);

    if (keyboard == -1) return -1;

    while(true) {
        read(keyboard, &ev, sizeof(ev));
        if (ev.type == EV_KEY) {
            if (ev.value == 0)
                printf("RELEASED 0x%04x (%d)\n", ev.code, ev.code);
            else if (ev.value == 1)
                printf("PRESSED 0x%04x (%d)\n", ev.code, ev.code);
        }
    }
    
    return 0;
}
