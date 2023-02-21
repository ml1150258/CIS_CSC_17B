#include <pthread.h>

typedef struct data_control {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  int active;
} data_control;
