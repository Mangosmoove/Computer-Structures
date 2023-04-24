#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

char arr[5];
sem_t s, s2, mutex;
int w, r;

void *lower(void* arg){
  int* id = (int*) arg;
  int i;
  for(i = 0; i < 5; i++){
    sem_wait(&s);
    sem_wait(&mutex);
    arr[w] = rand() % 26 + 97;
    printf("writer ID: %d, char written: %c\n", *id, arr[w]);
    w = (w + 1) % 5;
    sem_post(&mutex);
    sem_post(&s2);
  }
  return NULL;
}

void *upper(void* arg){
  int* id = (int*) arg;
  int i;
  for(i = 0; i < 5; i++){
    sem_wait(&s);
    sem_wait(&mutex);
    arr[w] = rand() % 26 + 65;
    printf("writer ID: %d, char written: %c\n", *id, arr[w]);
    w = (w + 1) % 5;
    sem_post(&mutex);
    sem_post(&s2);
  }
  return NULL;
}

void *buffer(void* arg){
  int* id = (int*) arg;
  int i;
  for(i = 0; i < 5; i++){
    sem_wait(&s2);
    sem_wait(&mutex);
    printf("reader ID: %d, char read: %c\n", *id, arr[r]);
    r = (r + 1) % 5;
    sem_post(&mutex);
    sem_post(&s);
  }
  return NULL;
}

int main(int argc, char* argv[]){
  if(argc != 1){
    exit(EXIT_FAILURE);
  }
  
  sem_init(&s, 1, 5);
  sem_init(&s2, 1, 0);
  sem_init(&mutex, 0, 1);
  (void)argv[0];

  pthread_t tid[8];
  w = 0;
  r = 0;
  
  int zero = 0;
  int one = 1;
  int two = 2;
  int three = 3;
  
  pthread_create(&tid[0], NULL, lower, (void*) &zero);
  pthread_create(&tid[1], NULL, lower, (void*) &one);
  pthread_create(&tid[2], NULL, upper, (void*) &two);
  pthread_create(&tid[3], NULL, upper, (void*) &three);
  pthread_create(&tid[4], NULL, buffer, (void*) &zero);
  pthread_create(&tid[5], NULL, buffer, (void*) &one);
  pthread_create(&tid[6], NULL, buffer, (void*) &two);
  pthread_create(&tid[7], NULL, buffer, (void*) &three);
  
  int i;
  for(i = 0; i < 8; i++){
    pthread_join(tid[i], NULL);
  }
  exit(EXIT_SUCCESS);
}
