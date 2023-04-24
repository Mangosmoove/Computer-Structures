#include<stdio.h>
#ifndef INCCNT
	#define INCCNT 1000
#endif
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void *concat(void* arg){
  char *str = (char*) arg;
  printf("Concat String: %s Example\n", str);
  return NULL;
}

void *increment(void* arg){
  int *num = (int*) arg;
  printf("Count: %d\n", *num + INCCNT);
  return NULL;
}


int main(int argc, char* argv[]){
  if(argc != 3){
    exit(EXIT_FAILURE);
  }
  
  int l = strlen(argv[2]);
  int i;
  for(i = 0; i < l; i++){
    if(isalpha(argv[2][i])!=0){
      exit(EXIT_FAILURE);
    }
  }
  
  pthread_t tid[2];
  
  pthread_create(&tid[0], NULL, concat, (void*) argv[1]);
  
  int num = atoi(argv[2]);
  pthread_create(&tid[1], NULL, increment, (void*) &num);
  
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  exit(EXIT_SUCCESS);
}
