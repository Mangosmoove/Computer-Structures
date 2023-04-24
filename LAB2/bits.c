/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 3
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}

/* 
 * getByte - Extract nth byte from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 6
 */
int getByte(int x, int n) {
  return (0xFF&(x >> (n << 3)));
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + - << >>
 *  Points: 6
 */
int byteSwap(int x, int n, int m) {
    return 2;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 10
 */
int logicalShift(int x, int n) {
  return (x >> n) ^ (((x&(1 << 31)) >> n) << 1);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitCount(int x) {
  //I'm so sorry but I genuinely did not know what else to do
  int mask = 0x01;
  int sum = x & mask;
  
  sum += x >> 1 & mask;
  sum += x >> 2 & mask;
  sum += x >> 3 & mask;
  sum += x >> 4 & mask;
  sum += x >> 5 & mask;
  sum += x >> 6 & mask;
  sum += x >> 7 & mask;
  sum += x >> 8 & mask;
  sum += x >> 9 & mask;
  sum += x >> 10 & mask;
  sum += x >> 11 & mask;
  sum += x >> 12 & mask;
  sum += x >> 13 & mask;
  sum += x >> 14 & mask;
  sum += x >> 15 & mask;
  sum += x >> 16 & mask;
  sum += x >> 17 & mask;
  sum += x >> 18 & mask;
  sum += x >> 19 & mask;
  sum += x >> 20 & mask;
  sum += x >> 21 & mask;
  sum += x >> 22 & mask;
  sum += x >> 23 & mask;
  sum += x >> 24 & mask;
  sum += x >> 25 & mask;
  sum += x >> 26 & mask;
  sum += x >> 27 & mask;
  sum += x >> 28 & mask;
  sum += x >> 29 & mask;
  sum += x >> 30 & mask;
  sum += x >> 31 & mask;
  
  return sum;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + - << >>
 *   Points: 15
 */
int bang(int x) {
  int oneComp = 1 + ~x;
  
  int plus = ((x >> 31) & 0x01);
  int minus = ((oneComp >> 31) & 0x01);
  
  return (plus | minus) ^ 0x01;
}

/*
 * bitParity - returns 1 if x contains an odd number of 1's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + - << >>
 *   Points: 15
 */
int bitParity(int x) {
  int mask = 0x1;
  int p = x & mask;
  
  //I watched this video to figure out the relationship between xor and modulo: https://www.youtube.com/watch?v=tNnaEyWxsEI
  p = p ^ ((x >> 1) & mask);
  p = p ^ ((x >> 2) & mask);
  p = p ^ ((x >> 3) & mask);
  p = p ^ ((x >> 4) & mask);
  p = p ^ ((x >> 5) & mask);
  p = p ^ ((x >> 6) & mask);
  p = p ^ ((x >> 7) & mask);
  p = p ^ ((x >> 8) & mask);
  p = p ^ ((x >> 9) & mask);
  p = p ^ ((x >> 10) & mask);
  p = p ^ ((x >> 11) & mask);
  p = p ^ ((x >> 12) & mask);
  p = p ^ ((x >> 13) & mask);
  p = p ^ ((x >> 14) & mask);
  p = p ^ ((x >> 15) & mask);
  p = p ^ ((x >> 16) & mask);
  p = p ^ ((x >> 17) & mask);
  p = p ^ ((x >> 18) & mask);
  p = p ^ ((x >> 19) & mask);
  p = p ^ ((x >> 20) & mask);
  p = p ^ ((x >> 21) & mask);
  p = p ^ ((x >> 22) & mask);
  p = p ^ ((x >> 23) & mask);
  p = p ^ ((x >> 24) & mask);
  p = p ^ ((x >> 25) & mask);
  p = p ^ ((x >> 26) & mask);
  p = p ^ ((x >> 27) & mask);
  p = p ^ ((x >> 28) & mask);
  p = p ^ ((x >> 29) & mask);
  p = p ^ ((x >> 30) & mask);
  p = p ^ ((x >> 31) & mask);
  
  return p;
}
