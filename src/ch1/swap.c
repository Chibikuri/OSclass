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
	print(f("x..%d, y..%d\n", a, b);
}
