#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* self_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return(void*)malloc(size*sizeof(void));  //if the memory is not "given" originally
    }

    if (size == 0) {   //if we assign the empty slot, the consequently means to free up the memory
        free(ptr);
        return NULL;
    }

    void* buff = (void*)malloc(size*(sizeof(void)));     //change size
    memcpy(buff, ptr, size);
    
    return buff;
}

int main() {
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    int* a1 = (int*)malloc(n1 * sizeof(int));
    int i;
    for (i = 0; i < n1; i++){
        a1[i] = 100;
        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Usage of my function in order to change the array to size n2
    a1 = self_realloc(a1, n2);

    //If the new array is a larger size, set all new members to 0

    if (n2 > n1) {
        for (i = n1; i < n2; i++) {
            a1[i] = 0;
        }
    }

    for(i = 0; i < n2; i++){
        printf("%d ", a1[i]);
    }
    printf("\n");
    return 0;
}
