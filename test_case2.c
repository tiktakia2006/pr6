#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(2000 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 2000; i++) {
        arr[i] = i;
    }
    free(arr);
    return 0;
}
