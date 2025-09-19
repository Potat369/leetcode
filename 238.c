#include <stdio.h>
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
  int *output = malloc(numsSize * sizeof(int));
  int curr = 1;

  for (int i = 0; i < numsSize; i++) {
    output[i] = 1;
    output[i] *= curr;
    curr *= nums[i];
  }

  curr = 1;
  for (int i = numsSize - 1; i >= 0; i--) {
    output[i] *= curr;
    curr *= nums[i];
  }

  *returnSize = numsSize;
  return output;
}

int main(void) {
  int a[] = {1, 2, 3, 4};

  int ret;
  int *b = productExceptSelf(a, 4, &ret);

  for (int i = 0; i < ret; i++) {
    printf("%d ", b[i]);
  }

  return EXIT_SUCCESS;
}
