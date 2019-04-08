#include <stdio.h>

int main(void){
	int hoge = 5;
	int piyo = 10;
	int *hoge_p;

	printf("&hoge..%p\n", &hoge);
	printf("&piyo..%p\n", &piyo);
	printf("&hoge_p..%p\n", &hoge_p);
	
	/*hoge_pはint hogeをさすポインタとなっている*/
	hoge_p = &hoge;
	printf("hoge_p..%p\n", hoge_p);

	/*"*"をつけることによって，そのポインタが指す先の情報を持つようになる*/
	printf("*hoge_p..%d\n", *hoge_p);

	*hoge_p = 10;

	printf("hoge..%d\n", hoge);

	return 0;
}
