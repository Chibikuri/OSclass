#include<stdio.h>
#include<stdlib.h>

//int型のglobal_variableを定義
int global_variable;

//staticなint型のfile_static_variableを定義
static int file_static_variable;

void func1(void){
	//def int type of func1_variable
	int func1_variable;
	//def static int type of func1_static_variable
	static int func1_static_variable;

	printf("&func1_variable..%p\n", &func1_variable);
	printf("&func1_static_variable..%p\n", &func1_static_variable);

}

void func2(void){
	int func2_variable;
	
	printf("&func2_variable..%p\n", &func2_variable);
}

int main (void){
	int *p;
	printf("&func1..%p\n", func1);
	printf("&func2..%p\n", func2);

	printf("String literal..%p\n", "abc");

	printf("&global_variable..%p\n", &global_variable);

	printf("&file_static_variable..%p\n", &file_static_variable);

	func1();
	func2();

	p = malloc(sizeof(int));
	printf("malloc address...%p\n", p);
	
	return 0;
}
