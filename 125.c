#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s) {
  size_t len = strlen(s);
  char b[len + 1];
  int p = 0;

  for (size_t i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      b[p++] = s[i] + 32;
    } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
      b[p++] = s[i];
    }
  }
  if (p == 1 || p == 0)
    return true;

  for (int i = 0; i < p / 2; i++) {
    if (b[i] != b[p - 1 - i]) {
      return false;
    }
  }

  return true;
}
int main(void) {
  printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
  // amanaplanacanalpanama1
  // printf("%d %d %d %d\n", 'a', ' ', 'A', 'Z');
  // 97 122 65 90
  return 0;
}
