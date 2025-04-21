#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(0);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Memory allocated successfully\n");
    free(arr);
    return 0;
}
