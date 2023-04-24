#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char * argv[]){
  if(argc != 3){
    exit(EXIT_FAILURE);
  }
  char path[100] = "/bin/";
  
  strcat(path, argv[1]); //to make complete path like in slides
  execl(path, argv[1], argv[2], NULL);
  
  exit(EXIT_SUCCESS);
}
