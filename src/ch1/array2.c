#include<stdio.h>

int main(void){

	//要素数5の配列と,ポインタpとintを定義
	int array[5];
	int *p;
	int i;

	// 配列に値をセット
	for(i=0; i<5; i++){
		array[i] = i;
	}

	//その内容（ポインタを表示）
	for(p=&array[0]; p!=&array[5]; p++){
		print(f("%d\n", *p);
	}
}
