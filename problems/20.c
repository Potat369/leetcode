#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s) {
  int len = strlen(s);
  char stack[len];
  int top = 0;

  for (int i = 0; i < len; i++) {
    char c = s[i];
    if (c == '(' || c == '{' || c == '[') {
      stack[top] = c;
      top += 1;
    } else if (top > 0 && ((stack[top - 1] == '(' && c == ')') ||
                           (stack[top - 1] == '[' && c == ']') ||
                           (stack[top - 1] == '{' && c == '}'))) {
      top -= 1;
    } else {
      return false;
    }
  }

  return top == 0;
}

int main(void) {

  // printf("%d", isValid("()"));
  // 1
  printf("%d", isValid("({})"));

  return EXIT_SUCCESS;
}
