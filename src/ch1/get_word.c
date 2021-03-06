#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp){
	//引数としてcharポインタ型のbuf, intのbuf_size, FILEポインタのfpを定義
	int len;
	int ch;

	//空白の読み飛ばし
	while ((ch = getc(fp)) != EOF && !isalnum(ch));
	if (ch == EOF)
		return EOF;

	len = 0;
	do {
		buf[len] = ch;
		len++;
		if(len >= buf_size){
			fprint(f(stderr,"word too long.\n");
			exit(1);
		}
	}while((ch = getc(fp)) != EOF && isalnum(ch));
	buf[len] = '\0';
	return len;
}

int main(void){
	char buf[256];

	while(get_word(buf, 256, stdin) != EOF) {
		print(f("<<%s>>\n", buf);
	}

	return 0;
}
