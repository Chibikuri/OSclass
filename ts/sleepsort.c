// author:Ryosuke Satoh (cocori)
#include<stdio.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

struct tharg{
    char name[10];
    int val;
};

void *mythread(void *arg){
    struct tharg *targ = (struct tharg *)arg;
    printf("in mythread\n");
    printf("%s: start\n", targ->name);
    sleep(targ-> val);
    printf("%d ", targ-> val);
    free(arg);
    return NULL;
}

int datalist[] = {1, 1, 1, 1, 1};

int main(int argc, char*argv[]){
    pthread_t *pthreads;
    int rc, i;
    unsigned long listen = sizeof(datalist)/sizeof(int);
    // printf("main : begin sorting list of %lu numbers\n", listlen);
    pthreads = malloc(sizeof(pthread_t)*listen);
    if(!pthreads){
        printf("fail! abort\n");
        exit(-1);
    }
    for (i = 0; i< listen; i++){
        struct tharg *t = (struct tharg *)malloc(sizeof(struct tharg));
        printf("i: %d\n", i);
        if(!t){
            printf("fail! abort!\n");
            exit(-1);
        }
        sprintf(t->name, "T: %d", i);
        t->val = datalist[i];
        rc = pthread_create(&pthreads[i], NULL, mythread, t); assert(rc==0);
        printf("i: %d thread created\n", i);
    }
    for (i=0; i<listen;i++){
        rc = pthread_join(pthreads[i], NULL); assert(rc==0);
        // printf("%d", rc);
    }
    printf("\n");
    printf("main: end\n");
    return 0;
}