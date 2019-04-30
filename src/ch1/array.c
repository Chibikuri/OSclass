#include <stdio.h>

int main(void){
	int array[5];
	int i;

	//配列に値を格納
	for (i = 0; i < 5; i++){
		array[i] = i;
	}

	//表示
	for(i=0; i<5; i++){
		print(f("%d\n", array[i]);
	}
	//各要素の*アドレス*を表示
	for(i=0; i < 5; i++){
		print(f("&array[%d]..%p\n", i, &array[i]);
	}

	return 0;
}
