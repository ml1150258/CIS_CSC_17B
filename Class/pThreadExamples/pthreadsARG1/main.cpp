//Old Program using pthreads
//Illustrates the creation of a thread


#include <pthread.h>//Obviously threads!
#include <stdlib.h>//general purpose functions, 
//including dynamic memory management, 
//random number generation, communication with the environment,
#include <unistd.h>//standard symbolic constants and types, 
//i.e. POSIX versions, etc....  such as sleep()
#include <stdio.h>//printf function

void *thread_function(void *arg) {
  int i,time,thread;
  time=*(reinterpret_cast<int *>(arg));
  thread=*(reinterpret_cast<int *>(arg)+1);
  printf("Thread %d will run for %d secs!\n",thread,time);
  for ( i=0; i<=time; i++ ) {
    printf("Thread %d says %d secs of %d secs!\n",thread,i,time);
    sleep(1);
  }
  return NULL;
}

int main(void) {

  //Create the threads
  int nThreads=2;
  pthread_t mythread[nThreads];
  
  //Start the thread execution for the first thread
  int time1[]={10,1};
  if ( pthread_create( &mythread[0], NULL, thread_function,time1) ) {
    printf("error creating thread.");
    abort();
  }
  
  //Start the execution of the second thread
  int time2[]={6,2};
  if ( pthread_create( &mythread[1], NULL, thread_function,time2) ) {
    printf("error creating thread.");
    abort();
  }

  //Time to join them back up
  for(int i=0;i<nThreads;i++){
        if ( pthread_join ( mythread[i], NULL ) ) {
                printf("error joining thread.");
                abort();
        }
  }
  
  exit(0);
}