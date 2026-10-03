#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL && q == NULL) return true;
  if (p == NULL || q == NULL) return false;

  return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


//     1         1
//    2 3    null 3
//

int main(void) { 
  

  return 0; 
}
