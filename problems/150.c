#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StructNode {
  int val;
  struct StructNode *prev;
} StructNode;

typedef struct Stack {
  struct StructNode *head;
} Stack;

Stack *stackCreate() {
  Stack *stack = malloc(sizeof(Stack));
  stack->head = NULL;

  return stack;
}

int stackPop(Stack *stack) {
  StructNode *head = stack->head;
  stack->head = head->prev;
  int res = head->val;
  free(head);
  return res;
}

void stackPush(Stack *stack, int val) {
  StructNode *head = malloc(sizeof(StructNode));
  head->prev = stack->head;
  head->val = val;

  stack->head = head;
}

int evalRPN(char **tokens, int tokensSize) {
  Stack *stack = stackCreate();

  for (int i = 0; i < tokensSize; i++) {
    if (isdigit(tokens[i][0]) ||
        (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
      stackPush(stack, atoi(tokens[i]));
    } else {
      int second = stackPop(stack);
      int first = stackPop(stack);

      switch (tokens[i][0]) {
      case '/':
        stackPush(stack, first / second);
        break;
      case '*':
        stackPush(stack, first * second);
        break;
      case '+':
        stackPush(stack, first + second);
        break;
      case '-':
        stackPush(stack, first - second);
        break;
      }
    }
  }

  return stack->head->val;
}

int main(void) {

  char *a[] = {"10", "6", "9",  "3", "+", "-11", "*",
               "/",  "*", "17", "+", "5", "+"};

  printf("\n%d\n", evalRPN(a, 13));

  return 0;
}
