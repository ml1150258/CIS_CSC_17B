/*
 * CSC 17B  Example 4 Threading Program
 * Purpose:  Show calculations end up being
 *           the same.
 */

//System Libraries
#include <pthread.h> //Threading
#include <stdio.h>   //Printf library
#include <stdlib.h>  //Exit Library
#include <string.h>  //String Library
#include <cmath>     //Math Library

//Function Prototypes
void *BusyWork(void *t);

//Execution Starts Here!
int main (int argc, char *argv[]){
   const int NUM_THREADS=4;
   pthread_t thread[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   void *status;

   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for(long t=0; t<NUM_THREADS; t++) {
      printf("Main: creating thread %ld\n", t);
      rc = pthread_create(&thread[t], &attr, BusyWork, (void *)t); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for(long t=0; t<NUM_THREADS; t++) {
      rc = pthread_join(thread[t], &status);
      if (rc) {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      }
      printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
   }
 
    printf("Main: program completed. Exiting.\n");
    pthread_exit(NULL);
}

void *BusyWork(void *t){
   long tid;
   double result=0;
   tid = (long)t;
   printf("Thread %ld starting...\n",tid);
   for (int i=0; i<100000000; i++){
       double mult=sin(i)*cos(i);
       mult=(mult<0?-mult:mult);
      result += mult;
       //result+=fabs(sin(i)*cos(i));
   }
   //result = 1.0;
   printf("Thread %ld done. Result = %e\n",tid, result);
   pthread_exit((void*) t);
}