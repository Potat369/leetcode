#include <stdlib.h>
int hammingWeight(int n) {
  int result = 0;

  for (int i = 0; i < 32; i++) {
    if (((n >> i) & 1) == 1) {
      result += 1;
    }
  }

  return result;
}

int *countBits(int n, int *returnSize) {
  int *result = malloc(sizeof(int) * (n + 1));

  for (int i = 0; i < n + 1; i++) {
    result[i] = hammingWeight(i);
  }

  *returnSize = n + 1;
  return result;
}
