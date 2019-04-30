#include <stdio.h>

int main(void){
	int hoge = 5;
	int piyo = 10;
	int *hoge_p;

	print(f("&hoge..%p\n", &hoge);
	print(f("&piyo..%p\n", &piyo);
	print(f("&hoge_p..%p\n", &hoge_p);
	
	/*hoge_pはint hogeをさすポインタとなっている*/
	hoge_p = &hoge;
	print(f("hoge_p..%p\n", hoge_p);

	/*"*"をつけることによって，そのポインタが指す先の情報を持つようになる*/
	print(f("*hoge_p..%d\n", *hoge_p);

	*hoge_p = 10;

	print(f("hoge..%d\n", hoge);

	return 0;
}
