#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 10
int A[SZ][SZ];

int main(int argc, char* argv[]){
  if(argc != 1){
    exit(EXIT_FAILURE);
  }
  
  int i;
  int j;

  for(i = 0; i < SZ; i++){
    for(j = 0; j < SZ; j++){
      A[i][j] = i*j;
    }
  }
  
  clock_t start;
  clock_t stop;
  
  start = clock();  
  for(j = 1; j < SZ; j++){
    for(i = 0; i < SZ; i++){
      A[i][j] = ( A[i][j-1] + A[i][j] ) / 2;
    }
  }
  stop = clock();
  double time = (double)(stop-start);
  printf("Time: %lf\n", time);
  exit(EXIT_SUCCESS);
}
