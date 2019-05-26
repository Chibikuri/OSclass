#include<stdio.h>
#include<stdlib.h>

typedef struct {
 int num;
} strct;
 
int main(void) {
 int num;
 strct *entity;

 entity = (strct*)malloc(num);

 printf("%p\n", &entity);
 free(entity);
 
 return 0;
}