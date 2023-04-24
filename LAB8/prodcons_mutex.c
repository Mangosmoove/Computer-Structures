#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int n;
sem_t r_mutex, w_mutex;

void *write(void* arg){
  int* temp = (int*) arg;
  
  int i;
  for(i = 0; i < *temp; i++){
    sem_wait(&w_mutex);
    n = rand() % *temp;
    printf("writer wrote: %d\n", n);
    sem_post(&r_mutex);
  }
  
  return NULL;
}

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }

  pthread_t tid[1];
  int read = atoi(argv[1]);
  if(read <= 0){
    exit(EXIT_FAILURE);
  }

  sem_init(&r_mutex, 0, 0);
  sem_init(&w_mutex, 0, 1);
  
  pthread_create(&tid[0], NULL, write, (void*) &read);
  
  int i;
  for(i = 0; i < read; i++){
    sem_wait(&r_mutex);
    printf("main read: %d\n", n);
    sem_post(&w_mutex);
  }
  
  pthread_join(tid[0], NULL);
  exit(EXIT_SUCCESS);
}
