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

	print(f("&func1_variable..%p\n", &func1_variable);
	print(f("&func1_static_variable..%p\n", &func1_static_variable);

}

void func2(void){
	int func2_variable;
	
	print(f("&func2_variable..%p\n", &func2_variable);
}

int main (void){
	int *p;
	print(f("&func1..%p\n", func1);
	print(f("&func2..%p\n", func2);

	print(f("String literal..%p\n", "abc");

	print(f("&global_variable..%p\n", &global_variable);

	print(f("&file_static_variable..%p\n", &file_static_variable);

	func1();
	func2();

	p = malloc(sizeof(int));
	print(f("malloc address...%p\n", p);
	
	return 0;
}
