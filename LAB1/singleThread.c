#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){
  FILE *fptr;
  char *buffer = NULL;
  size_t bSize = 0;
  clock_t start;
  clock_t stop;
  double time;
  int co1 = 0;
  int co2 = 0;
  int substrlen;

  if(argc != 5){
     printf("Error: Incorrect number of arguments\n");
     exit(EXIT_FAILURE);
  }
  else{
     start = clock();	
     fptr = fopen(argv[1], "r");
     if(fptr == NULL){
        puts("file not found");
        exit(EXIT_FAILURE);
     }
     substrlen = strlen(argv[2]);
     while((getline(&buffer, &bSize, fptr)) != -1){
        char* temp = buffer;
        while(1){
           temp = strstr(temp, argv[2]);
	   if(temp != NULL){
	      co1++;
	      temp = temp + substrlen;
	    }else{
	       break;
	    }
         }
      }
      fclose(fptr);
	
      fptr = fopen(argv[3], "r");
      if(fptr == NULL){
         exit(EXIT_FAILURE);
      }
      substrlen = strlen(argv[4]);
      while((getline(&buffer, &bSize, fptr)) != -1){
         char* temp = buffer;
         while(1){
            temp = strstr(temp, argv[4]);
	    if(temp != NULL){
	       co2++;
	       temp = temp + substrlen;
	     }else{
	       break;
	     }
	  }
      }
      fclose(fptr);
      stop = clock();
      
      printf("%s Count: %d\n", argv[2], co1);
      printf("%s Count: %d\n", argv[4], co2);

      time = (double) (stop-start);
      fptr = fopen("README.md", "w+");
      fprintf(fptr, "Time: %lf", time);
      fclose(fptr);
      exit(EXIT_SUCCESS);
   }
}
