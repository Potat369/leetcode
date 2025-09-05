#include <stdio.h>
#include <stdlib.h>

int *getConcatenation(int *nums, int numsSize, int *returnSize) {
  int *arr = malloc(sizeof(int) * numsSize * 2);
  for (int i = 0; i < numsSize * 2; i++) {
    arr[i] = nums[i % numsSize];
  }

  *returnSize = numsSize * 2;
  return arr;
}

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 3};

  int r = 0;
  int *b = getConcatenation(a, 3, &r);

  for (int i = 0; i < r; i++) {
    printf("%d\n", b[i]);
  }

  return EXIT_SUCCESS;
}
