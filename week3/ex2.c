#include <stdio.h>

void bubble_sort(int* a, int n) {
    int tmp;

    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bubble_sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
