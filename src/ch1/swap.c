#include<stdio.h>

void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	int a = 3;
	int b = 5;
	swap(&a, &b);
	printf("x..%d, y..%d\n", a, b);
}
