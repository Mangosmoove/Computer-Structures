#include<stdio.h>
#ifndef ASIZE
  #define ASIZE 1000
#endif
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }

  int arr[ASIZE];
  int sum = 0;
  int i;
  
  for(i = 0; i < ASIZE; i++){
    arr[i] = i*atoi(argv[1]);
  }

  int fd[2];

  if(pipe(fd) <0){
    exit(EXIT_FAILURE);
  }
  
  int id = fork();
  if(id > 0){
    for(i = ASIZE/2; i < ASIZE; i++){
      sum += arr[i];
    }
    
    write(fd[1], &sum, sizeof(sum));
    int exitc;
    wait(&exitc);
    
    close(fd[1]);
    close(fd[0]);
  }
  else if(id ==0){
    read(fd[0], &sum, sizeof(sum));
    for(i = 0; i < ASIZE/2; i++){
      sum += arr[i];
    }
    
    printf("%d\n", sum); 
    
    close(fd[1]);
    close(fd[0]);
  }
  else{
    exit(EXIT_FAILURE);
  }
  
  exit(EXIT_SUCCESS);
}
