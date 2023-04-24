#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

void *a(){
  sem_wait(&s);
  printf("A\n");
  return NULL;
}

void *b(){
  sem_wait(&s);
  printf("B\n");
  return NULL;
}

void *c(){
  sem_wait(&s);
  printf("C\n");
  return NULL;
}

int main(int argc, char* argv[]){
  if(argc != 1){
    exit(EXIT_FAILURE);
  }
  
  (void) argv[0];

  sem_init(&s, 1, 2);
  pthread_t tid[3];

  //FIX for code issue
  sem_post(&s);
  
  pthread_create(&tid[0], NULL, a, NULL);  
  pthread_create(&tid[1], NULL, b, NULL);
  pthread_create(&tid[2], NULL, c, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);

  exit(EXIT_SUCCESS);
}
