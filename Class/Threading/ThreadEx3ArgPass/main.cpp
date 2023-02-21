/*
 * CSC 17B  Example 3 Threading Program
 * Purpose:  Show when threads are started
 * there is no logical order to when they
 * meet back up.  And how to pass an structure
 * Argument
 */

//System Libraries
#include <pthread.h> //Threading
#include <stdio.h>   //Printf library
#include <cstdlib>   //Exit Library
#include <string.h>  //String Library

//User Libraries
#include "Thread_Data.h"

//Function Prototypes
void pause(int);
void *PrintHello(void *);

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    int *taskids[NUM_THREADS];
    int rc, sum=0;

    for(int t=0;t<NUM_THREADS;t++) {
      messages[t]=&mes[t][0];
      sum = sum + t;
      thread_data_array[t].thread_id = t;
      thread_data_array[t].sum = sum;
      thread_data_array[t].message = messages[t];
      printf("Creating thread %d\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *) 
           &thread_data_array[t]);
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

void *PrintHello(void *threadarg){
   int taskid, sum;
   char * hello_msg;
   struct Thread_Data *my_data;

   pause(5);
   my_data = (struct Thread_Data *) threadarg;
   taskid = my_data->thread_id;
   sum = my_data->sum;
   hello_msg = my_data->message;
   printf("Thread %d: %s  Sum=%d\n", taskid, hello_msg, sum);
   pthread_exit(NULL);
}