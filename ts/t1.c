// author:Ryosuke Satoh (cocori)
#include<stdio.h>
#include<assert.h>
#include<pthread.h>

void *mythread(void *arg){
    int counter = 100000000;
    printf("%s:\n", (char *) arg);
    while(counter){
        if(counter % 10000000 == 0)
            printf("%s: %d\n", (char *) arg, counter);
        counter --;
    }
    
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
    printf("main: end\n");
    return 0;
}