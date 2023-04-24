#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int num;

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }
  
  num = atoi(argv[1]);
  
  int returnVal = fork();
  
  printf("Hello World\n");
  
  if(returnVal > 0){
    printf("Parent: %d\n", num+1);
  }
  else if(returnVal == 0){
    printf("Child: %d\n", num-1);
  }
  else{
    exit(EXIT_FAILURE);
  }
 
  exit(EXIT_SUCCESS);
}
