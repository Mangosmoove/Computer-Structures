#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }
  
  int fd[2];
  if(pipe(fd) < 0){
    exit(EXIT_FAILURE);
  }
  
  char s[30];
  int returnVal = fork();
  
  if(returnVal > 0){
    write(fd[1], argv[1], 30);
    int child;
    wait(&child);
    close(fd[0]);
    close(fd[1]);
    
    if(child != 0){
      exit(EXIT_FAILURE);
    }
  }
  else if (returnVal == 0){
    read(fd[0], s, 30);
    printf("%s\n", s);
  }
  else{
    exit(EXIT_FAILURE);
  }
  
  exit(EXIT_SUCCESS);
}
