#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *curr = head;
  struct ListNode *prev = NULL;
  while (curr != NULL) {
    struct ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

int main(void) {

  struct ListNode *head = malloc(sizeof(struct ListNode));
  head->val = 1;
  head->next = malloc(sizeof(struct ListNode));
  head->next->val = 2;
  head->next->next = malloc(sizeof(struct ListNode));
  head->next->next->val = 3;
  head->next->next->next = malloc(sizeof(struct ListNode));
  head->next->next->next->val = 4;
  head->next->next->next->next = malloc(sizeof(struct ListNode));
  head->next->next->next->next->val = 5;
  head->next->next->next->next->next = NULL;

  for (struct ListNode *temp = head; temp != NULL; temp = temp->next) {
    printf("%d ", temp->val);
  }
  printf("\n");

  head = reverseList(head);

  for (struct ListNode *temp = head; temp != NULL; temp = temp->next) {
    printf("%d ", temp->val);
  }
  printf("\n");

  return 0;
}
