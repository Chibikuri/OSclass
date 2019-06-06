/* Threads with enough work to hopefully have something interesting happen. */

#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define NUM_THREADS 10

int gcounter = 100000000; /* 1E8 */

pthread_mutex_t master_lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg) {
    int lcounter = gcounter/NUM_THREADS;
    printf("%c: start\n", *(char *) arg);
    while (lcounter) {
	    if (gcounter % 10000000 == 0)
		    printf("%s: %d\n",(char *)arg,gcounter);
	    pthread_mutex_lock(&master_lock); // wrapper; exits on failure
	    gcounter--;
	    pthread_mutex_unlock(&master_lock);
	    lcounter--;
    }
    printf("lcounter: %d\n",lcounter);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    char a = 'A';
    printf("main: begin\n");
    for (int i = 0 ; i < NUM_THREADS ; i++ ) {
	    rc = pthread_create(&threads[i], NULL, mythread, &a); assert(rc == 0);
	    a++;
    }
    // join waits for the threads to finish
    printf("Okay, main() (our original thread) now waiting...\n");
    for (int i = 0 ; i < NUM_THREADS ; i++ ) {
	    rc = pthread_join(threads[i], NULL); assert(rc == 0);
    }
    printf("gcounter: %d\n",gcounter);
    printf("main: end\n");
    return 0; 
}
