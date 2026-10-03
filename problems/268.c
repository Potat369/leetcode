#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize) {
  int num = 0;

  for (int i = 1; i <= numsSize; i++) {
    num += i;
  }

  for (int i = 0; i < numsSize; i++) {
    num -= nums[i];
  }

  return num;
}

int main() {
  int nums[] = { 3, 0, 1 };
  int nums2[] = { 0, 1 };

  printf("%d = 2\n", missingNumber(nums, 3));
  printf("%d = 2\n", missingNumber(nums2, 2));

  return 0;
}
