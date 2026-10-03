#include <stdio.h>
int min(int a, int b) { return a < b ? a : b; }

int maxArea(int *height, int heightSize) {
  int i = 0, j = heightSize - 1;
  int max = 0;

  while (i < j) {
    int m = min(height[i], height[j]) * (j - i);
    max = m > max ? m : max;

    if (height[i] < height[j]) {
      i++;
    } else {
      j--;
    }
  }

  return max;
}

int main(void) {
  int a[] = {1, 18, 6, 2, 5, 18, 8, 3, 7};
  printf("%d\n", maxArea(a, sizeof(a) / sizeof(int)));

  return 0;
}
