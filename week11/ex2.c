#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *main_dir;
    struct dirent *dir;

    dir = opendir("/");
    
    if (main_dir) {
	dir = readdir(main_dir);

        while (dir != NULL)
            printf("dir: %s\n", dir->d_name);
        closedir(main_dir);
    }
    
    return(0);
}
