#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char *s) {
  int len = strlen(s);
  int result = 0;
  bool started = false;
  bool negative = false;

  for (int i = 0; i < len; i++) {
    char c = s[i];
    if ('0' <= c && c <= '9') {
      if (result > (INT_MAX - (c - '0')) / 10) {
        return negative ? INT_MIN : INT_MAX;
      }
      result = result * 10 + (c - '0');
      started = true;
    } else {
      if (!started) {
        if (c == '-') {
          negative = true;
          started = true;
        } else if (c == '+') {
          started = true;
        } else if (c != ' ') {
          break;
        }
      } else {
        break;
      }
    }
  }

  return negative ? -result : result;
}

int main(void) {
  // printf("%d", myAtoi("2147483647"));
  printf("%d", myAtoi("2147483646"));
  return EXIT_SUCCESS;
}
