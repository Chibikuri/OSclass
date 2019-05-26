#include<stdio.h>

int main(){
    char   c;
    int    i;
    float  f;
    double d;
    
    printf("char    %p\n"
           "int     %p\n"
           "float   %p\n"
           "double  %p\n", 
           &c, &i, &f, &d);

    return 0;
}