#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lower(){
  //https://www.scaler.com/topics/tolower-in-c/
  printf("%c\n", rand() % 26 + 97);
}

void upper(){
  printf("%c\n", rand() % 26 + 65);
}

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }

  char* input = argv[1];
  
  int i;
  for(i = 0 ; i < 10; i++){
    if(strcmp("-l", input) == 0){
      lower();
    }
    else if(strcmp("-u", input) == 0){
      upper();
    }
    else{
      exit(EXIT_FAILURE);
    }
  }
  
  exit(EXIT_SUCCESS);
}
