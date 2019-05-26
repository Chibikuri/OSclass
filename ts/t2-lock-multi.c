// author:Ryosuke Satoh (cocori)
#include<stdio.h>
#include<assert.h>
#include<pthread.h>

#define NUM_THREADS 10

int gcounter = 1000000000;

pthread_mutex_t master_lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg){
	pthread_mutex_lock(&master_lock);
    int lcounter = gcounter/NUM_THREADS; 
	printf("%s:\n", (char *) arg);
    while(lcounter){
        if(lcounter % 10000000 == 0)
            printf("%s: %d\n", (char *) arg, lcounter);
		gcounter--;
        lcounter --;
    }
	pthread_mutex_lock(&master_lock);
	printf("lcounter: %d\n", lcounter);
    
    return NULL;
}

int main(int argc, char*argv[]){
    pthread_t p1, p2;
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc==0);
    rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc==0);
    rc = pthread_join(p1, NULL); assert(rc==0);
    rc = pthread_join(p2, NULL); assert(rc==0);
	printf("gcounter: %d\n", gcounter);
    printf("main: end\n");
    return 0;
}
