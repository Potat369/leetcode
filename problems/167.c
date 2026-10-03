#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int i = 0, j = numbersSize - 1;

  int sum;
  while ((sum = numbers[i] + numbers[j]) != target) {
    if (sum > target) {
      j--;
    } else {
      i++;
    }
  }

  int *res = malloc(sizeof(int) * 2);
  res[0] = i + 1;
  res[1] = j + 1;

  *returnSize = 2;
  return res;
}
