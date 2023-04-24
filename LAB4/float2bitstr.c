#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int power(int);

int main(int argc, char* argv[]){
  if(argc < 2){
    puts("No input given");
    exit(EXIT_FAILURE);
  }
  
  double input = atof(argv[1]);
  //printf("input: %f\n", input);
  int sign;
  if(input < 0){
    sign = 1;
    input *= -1;
  }
  else{
    sign = 0;
  }
  //printf("sign: %d\n", sign);
  int wholeNum = (int)input;
  double decPart = input - wholeNum;
  
  //printf("whole num: %d\n", wholeNum);
  //printf("dec part: %f\n", decPart);
  
/*******************************WHOLE NUMBER CONVERSION******************************/
  int temp[16];
  int i;
  int size = 0;
  
  //in case number is less than 1 but greater than -1
  if(wholeNum == 0){
    temp[0] = 0;
    size = 1;
  }
  else{
    int tWN = wholeNum;
    for(i = 0; tWN > 0; i++){
      temp[i] = tWN % 2;
      tWN /= 2;
      //printf("%d", temp[i]);
      size += 1;
    }
  }
  //puts("\n");
  //printf("%d", size);
  
  //reverse it
  int j = 0;
  int binBits[size];
  for (i = size -1; i >= 0; i--){
    binBits[j] = temp[i];
    //printf("%d", binBits[j]);
    j++;
  }  
  
  //printf("\nwhole number size: %d\n", size);
  //puts("\n");
  
/*******************************FRACTION CONVERSION******************************/
  int rem[32];
  int index = 0;
  double tempFrac = decPart;
  double frac;
  
  while(index < 31 && tempFrac != 0){
    tempFrac *= 2;
    //printf("tempFrac: %lf\n", tempFrac);
    rem[index] = (int)tempFrac;
    //printf("rem: %d\n", rem[index]);
    frac = tempFrac - (int)tempFrac;
    tempFrac = frac;
    index += 1;
  }
  
  //copy over to a different array just in case there's too many extra bits
  int fracBin[index];
  
  for(i = 0; i < index; i++){
    fracBin[i] = rem[i];
    //printf("%d", fracBin[i]);
  }
  //printf("\nfraction size: %d\n", index);
  //puts("\n");
  
/*******************************SCIENTIFIC NOTATION + BIAS ******************************/
//the amount you move will be: the length of the array - the index of the first one - 1
//but the first one will always be at the 0th-index
//but this only applies to a number that is greater than 0

  int exp;
  bool resized = false;
  int resizedIndex; //if we're dealing with a number that is less than 1 but greater than -1, we have to change our array
  
  if(wholeNum >= 1 || wholeNum <= -1){
    exp = size - 1;
    resizedIndex = index;
    //puts("no resizing");
  }
  else{
    resized = true;
    for(i = 0; i < index; i++){
      if(fracBin[i] == 1){
        exp = i+1;
        break;
      }
    }
    exp *= -1;
    resizedIndex = 0;
  }
  //printf("exp: %d\n", exp);
  
  int bias = 127 + exp;
  //printf("bias: %d\n", bias);
  
  //represent bias as an 8bit 
  int expBit[8];
  int pow = 7;
  int two_pow;
  int t;
  int runningSum = 0;
  
  for(i = 0; i < 8; i++){
    two_pow = power(pow);
    t = bias - two_pow;
    
    if(runningSum + two_pow <= bias && t >= 0){
      expBit[i] = 1;
      runningSum += two_pow;
    }
    else{
      expBit[i] = 0;
    }  
    //printf("%d", expBit[i]);
    pow--;
  }
  //puts("\n");
  
/*******************************PUTTING THINGS TOGETHER*******************************/

  //start copying things over
  int result[32];
  
  //assign the sign bit
  result[0] = sign;
  //puts("8 bit");
  //assign the 8bit exp
  int expIndexer = 0;
  for(i = 1; i < 9; i++){
    result[i] = expBit[expIndexer];
    //printf("%d", result[i]);
    expIndexer++;
  }
  
  //puts("\n");
  //assign 23-bit mantissa  
  int rIndex = 9;
  
  if(!resized){
    //get the remaining whole number bits
    for(i = 1; i < size; i++){
      result[rIndex] = binBits[i];
      //printf("%d", result[rIndex]);
      rIndex++;
    }
    //printf("\n%d\n", rIndex);
  
    //puts("\n");
    //get the fraction bits
    for(i = 0; i < resizedIndex; i++){
      //just in case the whole number bits and the fraction bits end up being over 23 bits
      if(rIndex > 31){
        break;
      }
      result[rIndex] = fracBin[i];
      //printf("%d", result[rIndex]);
      rIndex++;
    }
    //printf("\n%d\n", rIndex);
  
    //add padding if needed to the mantissa
     while(rIndex < 32){
       result[rIndex] = 0;
       rIndex++;
    }   
  }  
  else{
    //if the number is >=-1 && <= 1, we only have the sign bit and the exp
    //so we need the mantissa
    //the mantissa will be the newfracbin array with added 0s as necessary

    /*for(i = 0; i < index; i++){
      printf("%d", fracBin[i]);
    }
    puts("\n");*/
    
    if(exp < 0){
      exp *= -1;
    }
    int newfracBin[index-exp+1];
    for(i = exp; i < index; i++){
      newfracBin[resizedIndex] = fracBin[i];
      //printf("%d", newfracBin[resizedIndex]);
      resizedIndex++;
    }
    //puts("\n");   
    
   // printf("new mantissa size so far: %d\n", resizedIndex);
    if(resizedIndex > 22){
      resizedIndex = 23;
    }
    for(i = 0; i < resizedIndex; i++){
      result[rIndex] = newfracBin[i];
      rIndex++;
    }
  
    while(rIndex < 32){
      result[rIndex] = 0;
      rIndex++;
    }
  }
  
  //puts("\n");
  //print the resulting array
  
  for(i = 0; i < 32; i++){
    printf("%d", result[i]);
    if(i == 31){
      printf("\n");
    }
  }
  
}

int power(int e){
  int i;
  int sum = 1;
  
  for(i = 1; i <= e; i++){
    sum *=2;
  }
  return sum;
}
