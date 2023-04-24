#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
  if(argc != 3){
    exit(EXIT_FAILURE);
  }
  
  int fd[2];
  
  if(pipe(fd) < 0){
    exit(EXIT_FAILURE);
  }
  
  write(fd[1], argv[1], 30);
  write(fd[1], argv[2], 30);
  
  char s1[30];
  char s2[30];
  
  read(fd[0], s1, 30);
  read(fd[0], s2, 30);
  
  printf("%s\n", s1);
  printf("%s\n", s2);
  
  close(fd[0]);
  close(fd[1]);
  exit(EXIT_SUCCESS);
}
