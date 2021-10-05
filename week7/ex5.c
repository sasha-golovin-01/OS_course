#include <stdio.h>
#include <stdlib.h>

int main() {

    char** s = (char**)malloc(sizeof(char*)); //we need to allocate memory here to proceed further
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);

    return(0);
}
