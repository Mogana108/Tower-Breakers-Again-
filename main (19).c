#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potential(int num) {
    int deg = 0;
    if (num % 2 ==0) {
        deg++;
        while (num % 2 == 0) num /= 2;
    }
    for (int i=3; i<=num; i++) {
        while (num % i == 0) {
            num /= i;
            deg++;
        }
    }
    return deg;
}

int towerBreakers(int n, int* arr) {
    int xor = 0;
    for (int i=0; i<n; i++) xor ^= potential(arr[i]);
    if (xor == 0) return 2;
    return 1;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int t; scanf("%d", &t);
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n; scanf("%d", &n);
        int* arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int result = towerBreakers(n, arr);
        fprintf(fptr, "%d\n", result);
    }
    fclose(fptr);
    return 0;
}
