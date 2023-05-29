#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int* g = malloc(sizeof(int) * 5);
    float f;
    printf("%d", g[-9]);
    return 0;
}