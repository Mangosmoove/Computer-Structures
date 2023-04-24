#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

struct input_args{
  char* a;
  char* b;
};

typedef struct input_args IA;

void* word_count(void *arg){
  IA *args = (IA*) arg;
  FILE *fp;
  char *buffer = NULL;
  char *tempbuffer = NULL;
  size_t bufsize = 0;
  ssize_t chars;
  int count=0;
  
  fp = fopen(args->a, "r");
  if(fp == NULL){
    exit(EXIT_FAILURE);
  }

  while((chars = getline(&buffer, &bufsize, fp) != -1)){
    tempbuffer = buffer;
    while((tempbuffer = strstr(tempbuffer, args->b)) != NULL){
      count +=1;
      *tempbuffer = *tempbuffer + strlen(args->b);
    }
  }
  fclose(fp);
  printf("%s Count: %d\n", args->b, count);
  return NULL;
}


int main(int argc, char* argv[]){
  //clock_t start_main;
  //clock_t stop_main;
  
  //start_main = clock();
  if(argc != 5 ){
    exit(EXIT_FAILURE);
  }
  
  //clock_t start_thread;
  //clock_t stop_thread;
  //double time;
  //double temp;
  pthread_t tid[2];
  IA arg1 ={.a = argv[1], .b = argv[2]};
  //start_thread = clock();
  pthread_create(&tid[0], NULL, word_count, (void*) &arg1);
  //stop_thread = clock();
  //time = (double) (stop_thread-start_thread);
  //printf("Thread 1: %lf\n", time);
  //temp = time;
  
  IA arg2 = {.a = argv[3], .b = argv[4]};
  //start_thread = clock();
  pthread_create(&tid[1], NULL, word_count, (void*) &arg2);
  //stop_thread = clock();
  //time = (double) (stop_thread-start_thread);
  //printf("Thread 2: %lf\n", time);
  //temp = temp + time;
  
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  //stop_main = clock();
  //time = (double) (stop_main-start_main);
  //printf("Main Thread: %lf\n", time);
  //printf("Both threads: %lf\n", temp);
  exit(EXIT_SUCCESS);
}
