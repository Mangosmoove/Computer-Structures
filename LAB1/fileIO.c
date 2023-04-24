#define  _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
   FILE *fptr;
   fptr = fopen(argv[1], "r");
   if(fptr == NULL || argc != 3){
      exit(EXIT_FAILURE);
   }
   else{
      int count = 0;
      size_t bSize = 0;
      char* buffer = 0;
      
      while (getline(&buffer, &bSize, fptr) != -1) {
	 if(strstr(buffer, argv[2]) != NULL){
            count++;
         }
      }
      fclose(fptr);
      printf("%d\n", count);
      exit(EXIT_SUCCESS);
   }
}
