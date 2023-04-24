#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char * argv[]){
  if(argc != 3){
    exit(EXIT_FAILURE);
  }
  
  int fd[2];
  if(pipe(fd) < 0){
    exit(EXIT_FAILURE);
  }
  
  int returnVal = fork();
  char bin[30] = "/bin/";
  char path[30];
  char buffer[30];
  
  if(returnVal > 0){ //padre
    write(fd[1], argv[1], 30);
    write(fd[1], argv[2], 30);
    
    int child;
    wait(&child);
    
    close(fd[0]);
    close(fd[1]);
    
    if(child != 0){
      //puts("here");
      exit(EXIT_FAILURE);
    }
  }
  else if(returnVal == 0){ //da bebe
    read(fd[0], path, 30);
    read(fd[0], buffer, 30);

    if(strstr(path, "/bin/") == NULL){ //does not have bin in name
      //note for future self: for strstr, have to set to NULL and not '/0' bc NULL is the return value if the str is not found
      strcat(bin, path); //add bin to the path boiiiiiiiiiiiiiiiiii
      if(execl(bin, path, buffer, NULL) != 0){
        exit(EXIT_FAILURE);
      }
    }
    else{ //has bin in name
      //add 5 because /bin/ is 5 characters
      if(execl(path, path+5, buffer, NULL) != 0){
        exit(EXIT_FAILURE);
      }
    }  
  }
  else{
    exit(EXIT_FAILURE);
  }
  
  exit(EXIT_SUCCESS);
}
