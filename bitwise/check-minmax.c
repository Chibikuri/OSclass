#include<stdio.h>
#include<limits.h>

int main(void){
    printf("Minimum value of short int = %d\n", SHRT_MIN);
    printf("Maximum value of short int = %d\n", SHRT_MAX);
    printf("Maximum value of short int = %d\n\n", USHRT_MAX);

    printf("Maximum value of int = %d\n", INT_MIN);
    printf("Minimum value of int = %d\n", INT_MAX);
    printf("Maximum value of int = %u\n\n", UINT_MAX);

    printf("Maximum value of long int = %ld\n", LONG_MIN);
    printf("Maximum value of long int = %ld\n", LONG_MAX);
    printf("Maximum value of long int = %lu\n", ULONG_MAX);

    return 0;
}