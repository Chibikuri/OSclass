#include <stdio.h>
#include <time.h>

int main(int argc, char *args[]){
		clock_t start, end;
		start = clock();
		printf("Hello world!\n");
		end = clock();
		printf("It takes %f sec to execute.\n", (double)(end-start)/CLOCKS_PER_SEC);
		return 0;
}
