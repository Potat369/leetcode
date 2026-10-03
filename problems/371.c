#include <stdio.h>

void print_binary(int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", num >> i & 1);
  }
  puts("");
}

int getSum(int a, int b) {
  int res = 0;

  int pushNext = 0;
  for (int i = 0; i < sizeof(int) * 8; i++) {
    int aEqual = a >> i & 1 == 1;
    int bEqual = b >> i & 1 == 1;
    if ((pushNext && !aEqual && !bEqual) || (!pushNext && aEqual && !bEqual) || (!pushNext && !aEqual && bEqual)) {
      res |= 1 << i;
      pushNext = 0;
    } else if ((pushNext && aEqual && !bEqual) || (!pushNext && aEqual && bEqual) || (pushNext && !aEqual && bEqual)) {
      pushNext = 1;
    } else if (pushNext && aEqual && bEqual) {
      res |= (unsigned int)(1) << i;
    }
  }

  return res;
}

// 2 -> 00010
// 3 -> 00011
// 5 -> 00101
//
//   -> 00001

int main() {
  print_binary(-12);
  puts("");
  print_binary(-8);
  puts("");
  print_binary(-20);
  puts("");
  printf("%d\n", getSum(-8, -12));


  return 0;
}
