#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

//range: -128-127 (inclusive)
int binToDec(int[], bool);
int power(int, int);

int main(int argc, char* argv[]){
  bool is_signed;
  
  //check possible argument errors
  
  //not enough args
  if(argc != 3){
    exit(EXIT_FAILURE);
  }
  
  //incorrect third argument
  if (strcmp("signed", argv[2]) == 0){
    is_signed = true;
  }
  else if(strcmp("unsigned", argv[2]) == 0){
    is_signed = false;
  }
  else{
    exit(EXIT_FAILURE);
  }
  
  
  char* bin = argv[1];
  //printf("%s", bin);
  
  //not an 8 bit binary string
  if(strlen(bin) > 8 || strlen(bin) < 8){
    exit(EXIT_FAILURE);
  }
  
  
  //convert char* to int array
  int i_bin[8];
  int i;
  for(i = 0; i < 8; i++){
    if(bin[i] == '1'){
      i_bin[i] = 1;
    }
    else if (bin[i] == '0'){
      i_bin[i] = 0;
    }
    else{
      //not a binary string
      exit(EXIT_FAILURE);
    }
  }
 /* for(i = 0; i <8; i++){
    printf("%d", i_bin[i]);
  }*/
  
  int value = 0;
  //unsigned or signed w leading 0  
  if(!is_signed || i_bin[0] == 0){ 
    value = binToDec(i_bin, is_signed); 
    
    
    //getting to exit failure bc maths
    if (value < 0 || value > 255){
      //exceeds range which shouldn't happen with unsigned 
      //but oh whale
      exit(EXIT_FAILURE);
    } 
  } 
  else{ //signed
    //invert bits
    
    int invert[8];
    for(i = 0; i < 8; i++){
      if(i_bin[i] == 0){
        invert[i] = 1;
      }
      else{
        invert[i] = 0;
      }
      //printf("%d", invert[i]);
    }
    value = (binToDec(invert, is_signed) + 1) * -1;
    
    if(value < -128 || value > 127){
      exit(EXIT_FAILURE);
    }
  }

  
  printf("%d", value);
  exit(EXIT_SUCCESS);
}

int binToDec(int a[], bool is_signed){
  int start = 0;
  int sum = 0;
  int exp = 7;
  int end = 8;
  
  if(is_signed){
    sum = power(exp, a[start]) * -1;
    start = 1;
    exp--;
  }
  
  
  for(start = start; start < end; start++){
    sum = sum + power(exp, a[start]);
    exp--;
  }
  return sum;
}

//made my own power f(x) cuz I couldn't get the math.h to link
int power(int exp, int multiplicand){
  int i;
  int sum = 0;
  if(multiplicand == 0){
    return sum;
  }

  sum = 1;
  for(i = 1; i <= exp; i++){
    sum *=2;
    
  }
  return sum;
}
