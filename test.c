#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int cpt = 0;
    float d = 128.167;
    
    char* h = (char*) malloc(20);
    sprintf(h, "%xh", *(unsigned int*)&d);

    printf("decimal = %f\n", d);
    printf("hexa = %s\n", h);
    return 0;
}