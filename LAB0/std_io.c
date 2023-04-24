#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char* argv[]) {
   if (argc == 1){
      printf("Error: Incorrect number of arguments\n");
      exit(EXIT_FAILURE);
   }
   else{
      if(strcmp(argv[1],"printf")==0){
         int i;
	 printf("You entered: ");
	 for(i = 2; i < argc; i++){
           printf("%s", argv[i]);
         }
	 printf("\n");
	 exit(EXIT_SUCCESS);
      }
      else if(strcmp(argv[1], "fprintf")==0){
	 //referenced this for file writing: https://www.programiz.com/c-programming/c-file-input-output
         FILE* fptr;
	 fptr = fopen("print.txt","w");
	 if(fptr != NULL){
	    int i;
	    for(i = 2; i < argc; i++)
	    {  
               if(i == argc-1){
	          fprintf(fptr, "%s", argv[i]);
	       }
	       else{
	          fprintf(fptr,"%s ",argv[i]);
	       }
	    }
	    fclose(fptr);
	    exit(EXIT_SUCCESS);
	 }
	 else{
            exit(EXIT_FAILURE);
         }
      }
      else if(strcmp(argv[1], "scanf")==0){
	 char input[100];
         printf("Please enter your input: ");
         scanf("%s", input);
	 printf("You entered: %s\n", input);
	 exit(EXIT_SUCCESS);
      }
      else{
         exit(EXIT_FAILURE);
      }
   }
}
