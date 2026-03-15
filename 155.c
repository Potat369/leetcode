#include <stdio.h>
#include <stdlib.h>

struct StackNode {
  int val;
  int min;
  struct StackNode* next;
};

typedef struct {
  struct StackNode* top;
} MinStack;

MinStack* minStackCreate() {
  MinStack* stack = malloc(sizeof(MinStack));

  stack->top = NULL;

  return stack;
}

void minStackPush(MinStack* obj, int val) {
  struct StackNode* node = malloc(sizeof(struct StackNode));

  node->val = val;
  if (obj->top != NULL) {
    node->min = obj->top->min > val ? val : obj->top->min;
    node->next = obj->top;
  } else {
    node->min = val;
    node->next = NULL;
  }
  obj->top = node;
}

void minStackPop(MinStack* obj) {
  struct StackNode* node = obj->top;

  obj->top = obj->top->next;
  free(node);
}

int minStackTop(MinStack* obj) {
  return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
  return obj->top->min;
}

void minStackFree(MinStack* obj) {
  struct StackNode* node = obj->top;  

  while (node != NULL) {
    obj->top = obj->top->next;
    free(node);
    node = obj->top;
  }

  free(obj);
}

int main(void) {
  MinStack* stack = minStackCreate();
  minStackPush(stack, -2);
  minStackPush(stack, 0);
  minStackPush(stack, -3);
  printf("%d\n", minStackGetMin(stack));
  minStackPop(stack);
  printf("%d\n", minStackTop(stack));
  printf("%d\n", minStackGetMin(stack));
  minStackFree(stack);

  return 0;
}
