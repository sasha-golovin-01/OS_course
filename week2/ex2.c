#include <stdio.h>
#include <string.h>

int main() {
    char s[100], r[100];
    int i;

    printf("Enter a string:\n");
    gets(s);

    int end = strlen(s);
    int n = end;

    for (i = 0; i < n; i++) {
        r[i] = s[end - 1];
        end--;
    }

    r[i] = '\0';

    printf("%s\n", r);

    return 0;
}
