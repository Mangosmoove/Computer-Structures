#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main(int argc, char* argv[]){
  if(argc != 2){
    exit(EXIT_FAILURE);
  }  
  
  if(strlen(argv[1]) != 32){
    exit(EXIT_FAILURE);
  }
  
  char* bin = argv[1];
  int i_bin[32]; 
  int sign;
  int exponent[8];
  int mantissa[23];
  
  int i;
  for(i = 0; i < 32; i++){
    if(bin[i] == '1'){
      i_bin[i] = 1;
    }
    else if (bin[i] == '0'){
      i_bin[i] = 0;
    }
    else{
      //not a binary string
      puts("Incorrect input argument");
      exit(EXIT_FAILURE);
    }
    //store into the different components
    if(i > 0 && i < 9){
      exponent[i-1] = i_bin[i]; 
    }
    if(i > 8){
      mantissa[i-9] = i_bin[i];
    }
  }
  sign = i_bin[0];
  
  //calculate e
  int expSum = 0;
  int exp = 7;
  for(i = 0; i < 8; i++){
    expSum += exponent[i] * pow(2, exp);
    exp--;
  }
  //printf("sum: %d", expSum);
  int add_1 = 1;
  bool denorm = false;
  if(expSum == 255 || expSum == 0){
    add_1 = 0;
    denorm = true;
  }
  
  
  double mSum = 0;
  exp = -1;
  for(i = 0; i < 23; i++){
    mSum += mantissa[i] * pow(2, exp);
    exp--;
  }
  mSum += add_1;
  //printf("%.17g\n", mSum);
  int e = 0;
  
  if(!denorm){
    e = expSum - 127;
  }
  else{
    e = -126;
  }
  double sum = 0;
  sum = pow(-1, sign) * mSum * pow(2, e);
  
  printf("Sign: %d\n", sign);
  printf("Exponent: %d\n", expSum);
  printf("Mantissa: %.17g\n", mSum);
  printf("Number: %.7g\n", sum);
  
  
  //need to subtract one for mantissa if denormalized
}
