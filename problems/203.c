#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
  struct ListNode* start = NULL;
  struct ListNode* ptr = head;

  while (ptr != NULL) {
    if (start == NULL) {
      if (ptr->val == val) {
        struct ListNode* temp = ptr;
        ptr = ptr->next;
        free(temp);
      } else {
        start = ptr;
      }
    } else if (ptr->next == NULL) {
      break;
    } else if (ptr->next->val == val) {
      ptr->next = ptr->next->next;
    } else {
      ptr = ptr->next;
    }
  }

  return start;
}

int main(void) {
  return 0;
}
