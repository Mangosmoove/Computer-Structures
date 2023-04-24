#include "bitops.h"
#include <stdio.h>
/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
  return x&y;
}

/* 
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
  return x|y;
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
  return x^y;
}


/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
  if(x < 0){
    return 0;
  }
  
  unsigned int mask = ~(0xff << 8*(32-b));
  return x&mask;
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {
  unsigned int mask = (0xff << 8*(32-b));
  return x|mask;
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b) {
  unsigned int mask = (0xff << 8*(sizeof(x)-b));
  return x^mask;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
  return (x << sc);
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
  return x >> sc;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
  return !x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
  int binBits[16];
  int i;
  
  for(i = 0; x > 0; i++){
    binBits[i] = x % 2;
    x /= 2;
  }
  
  //reverse it
  for (i = i-1; i >= 0; i--){
    printf("%d", binBits[i]);
  }
}  
