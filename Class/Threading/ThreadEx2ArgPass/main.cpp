/*
 * CSC 17B  Example 2 Threading Program
 * Purpose:  Show when threads are started
 * there is no logical order to when they
 * meet back up.  And how to pass an argument.
 */

//System Libraries
#include <pthread.h> //Threading
#include <stdio.h>   //Printf library
#include <cstdlib>   //Exit Library
#include <string.h>  //String Library

//Global Constants
const int NUM_THREADS=8;
char *messages[NUM_THREADS];
char mes[NUM_THREADS][10]={"Message 0","Message 1",
    "Message 2","Message 3","Message 4","Message 5",
    "Message 6","Message 7"};

//Function Prototypes
void pause(int);
void *PrintHello(void *);

//Execution Begins Here
int main(int argc, char *argv[]){

    pthread_t threads[NUM_THREADS];
    long taskids[NUM_THREADS];
    int rc;//Return Code

    for(int t=0;t<NUM_THREADS;t++) {
      taskids[t] = t;
      messages[t]=&mes[t][0];
      printf("Creating thread %d\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *) taskids[t]);
      if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
    }

    pthread_exit(NULL);
}

void pause(int n){
    unsigned int beg=static_cast<unsigned int>(time(0));
    unsigned int delt;
    do{
        unsigned int end=static_cast<unsigned int>(time(0));
        delt=end-beg;
    }while(delt<n);
}

void *PrintHello(void *threadid){
   long taskid;

   pause(5);
   taskid = (long) threadid;
   printf("Thread %ld: %s\n", taskid, messages[taskid]);
   pthread_exit(NULL);
}