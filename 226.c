#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
  struct TreeNode *toLookup[50];
  toLookup[0] = root;
  int top = 1;
  int bottom = 0;
  while (bottom < top) {
    if (toLookup[bottom % 50]) {
      if (toLookup[bottom % 50]->left) {
        toLookup[top % 50] = toLookup[bottom % 50]->left;
        top++;
      }
      if (toLookup[bottom % 50]->right) {
        toLookup[top % 50] = toLookup[bottom % 50]->right;
        top++;
      }
      struct TreeNode *tmp = toLookup[bottom % 50]->right;
      toLookup[bottom % 50]->right = toLookup[bottom % 50]->left;
      toLookup[bottom % 50]->left = tmp;
      bottom++;
    } else {
      break;
    }
  }

  return root;
}

int main() { return 0; }
