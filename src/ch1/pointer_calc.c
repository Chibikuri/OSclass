#include <stdio.h>

int main(void){
	//int型のhogeと，int型へのポインタhoge_pを定義
	int hoge;
	int *hoge_p;
	
	// hoge_pにhogeへのポインタを設定
	hoge_p = &hoge;

	// hoge_pをprint((%pを用いるべきということに注意)
	print(f("hoge_p..%p\n", hoge_p);
	
	//　ポインタ演算（ポインタに整数を足したり引いたりする演算）
	hoge_p++;

	print(f("hoge_p..%p\n", hoge_p);

	print(f("hoge_p..%p\n", hoge_p +3);

	return 0;
}
