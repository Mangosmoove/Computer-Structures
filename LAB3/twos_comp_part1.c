#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

int power(int);

int main(int argc, char* argv[]){
  //error checking time woooooooooooo
  bool is_neg = false;
  //https://stackoverflow.com/questions/13145777/c-char-to-int-conversion
  int num;
  
  if (argc != 2){
    exit(EXIT_FAILURE);
  }
  
  //do i need to check for non numeric values?
  int l = strlen(argv[1]);
  int i;
  for(i = 0; i < l; i++){
    //printf("%c", argv[1][i]);
    if(isalpha(argv[1][i])!=0){
      exit(EXIT_FAILURE);
    }
  }
  
  num = atoi(argv[1]);
  
  //printf("%d", num);
  
  if(num < -128 || num > 127){
    exit(EXIT_FAILURE);
  }
  
  if(num < 0){
    is_neg = true;
    num *= -1;
  }
  
  int binRep[8];
  int exp = 7;
  int two_pow;
  int temp;
  int runningSum = 0;
  
  for(i = 0; i < 8; i++){
    two_pow = power(exp);
    temp = num - two_pow;
    
    if(runningSum + two_pow <= num && temp >= 0){
      if(is_neg){
        //inverting for a negative number
        binRep[i] = 0;
      }
      else{
        binRep[i] = 1;
      }
      //printf("num: %d\n", num);
      runningSum += two_pow;
    }
    else{
      if(is_neg){
        //inverting for a negative number
        binRep[i] = 1;
      }
      else{
        binRep[i] = 0;
      }
    }  
    //printf("%d", binRep[i]);
    exp--;
  }
  
  if(is_neg){
    int temp = binRep[7] + 1;
    bool carry = false;
  
    if(temp == 2){
      carry = true;
      //puts("carry");
    }
    
    binRep[7] = temp%2;
    //printf("%d", binRep[7]);
    //puts("shee");
    
    for(i = 6; i >= 0; i--){
      if(carry){
        temp = binRep[i] + 1;
        carry = false;
      }
      else{
        temp = binRep[i];
      }
      
      if(temp >= 2){
        carry = true;
      }
      binRep[i] = temp % 2;
    }    
  }
   
  for(i = 0; i < 8; i++){
    printf("%d", binRep[i]);
    if(i == 7){
      printf("\n");
    }
  }
  exit(EXIT_SUCCESS);
}


//made my own power function because C hates me
int power(int exp){
  int i;
  int sum = 1;
  
  for(i = 1; i <= exp; i++){
    sum *=2;
    
  }
  return sum;
}

