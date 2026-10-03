#include <stdio.h>
#include <stdlib.h>

int search(int *nums, int numsSize, int target) {
  int l = 0, r = numsSize - 1, m;
  while (l <= r) {
    m = abs(l - r) / 2 + l;
    if (nums[m] > target) {
      r = m - 1;
    } else if (nums[m] < target) {
      l = m + 1;
    } else {
      return m;
    }
  }
  return -1;
}

int main(void) {
  int a[] = {-1, 0, 3, 5, 9, 12};
  printf("%d", search((int *)&a, 6, 9));
  // 4

  return EXIT_SUCCESS;
}
