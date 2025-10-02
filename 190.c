#include <stdio.h>
int reverseBits(int n) {
  int result = 0;

  for (int i = 0; i < 31; i++) {
    result ^= ((n >> i) & 1);
    result <<= 1;
  }

  return result;
}

int main() {
  printf("%d\n%d\n", reverseBits(43261596), 964176192);
  return 0;
}
