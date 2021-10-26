#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dirp = opendir("./tmp");
    if (dirp == NULL) {
        return -1;
    }
    struct dirent *dp;

    int8_t arr[255];
    char *files[255];
    int counter = 0;

    while ((dp = readdir(dirp)) != NULL) {
        arr[counter] = dp->d_ino;
        files[counter++] = dp->d_name;
    }

    for (int i = 0; i < counter; i++) {
        int isFound = 0;
        for (int j = i + 1; j < counter; j++) {
            if ((arr[j] == arr[i]) && (arr[j] != -1)) { //-1 - used
                if (isFound == 0) {
                    printf("%s -- %s, %s", files[i], files[i], files[j]);
                    isFound = 1;
                }
                else {
                    printf(", %s", files[j]);
                }
                arr[j] = -1; //-1 - used
            }
        }
        if (isFound) {
            printf("\n");
        }
    }

    (void)closedir(dirp);
    return 0;
}
