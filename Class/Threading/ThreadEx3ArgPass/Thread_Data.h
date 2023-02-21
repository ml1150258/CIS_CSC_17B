/*
 * CSC 17B  Example 3 Threading Program
 * Purpose:  Show when threads are started
 * there is no logical order to when they
 * meet back up.  And how to pass a structure.
 */

#ifndef THREAD_DATA_H
#define THREAD_DATA_H

struct Thread_Data
{
   int	thread_id;
   int  sum;
   char *message;
};

const int NUM_THREADS=8;
char *messages[NUM_THREADS];
char mes[NUM_THREADS][10]={"Message 0","Message 1",
    "Message 2","Message 3","Message 4","Message 5",
    "Message 6","Message 7"};

struct Thread_Data thread_data_array[NUM_THREADS];



#endif /* THREAD_DATA_H */

