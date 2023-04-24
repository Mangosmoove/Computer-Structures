#include <stdio.h>
#ifndef ASIZE
  #define ASIZE 10000
#endif
#ifndef NTHREADS
  #define NTHREADS 50
#endif
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
int array[ASIZE];

struct traverse_arr{
  int j;
  int k;
};

typedef struct traverse_arr arr;

void* sum_arr(void* arg){
  arr* args = (arr*) arg;
  int i;
  for(i = args->j; i < args->k; i++){
    sum += array[i];
  }
  return NULL;
}

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }

  int i;
  for(i = 0; i < ASIZE; i++){
    array[i] = i*atoi(argv[1]);
  }

  pthread_t tid[NTHREADS];
  arr threads[NTHREADS];
  
  for(i = 0; i < NTHREADS; i++){
    threads[i].j = (ASIZE * i)/NTHREADS;
    threads[i].k = (ASIZE * (i+1))/NTHREADS;
    pthread_create(&tid[i], NULL, sum_arr, (void*) &threads[i]);
  }
  
  for(i =0; i < NTHREADS; i++){
    pthread_join(tid[i], NULL);
  }
  printf("%d\n", sum);

  exit(EXIT_SUCCESS);
}
