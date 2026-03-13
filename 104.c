#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) { 
  if (root == NULL) return 0;

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  return (left > right ? left : right) + 1;
}

struct TreeNode* createTreeNode(int val) {
  struct TreeNode* node = malloc(sizeof(struct TreeNode));

  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {

  struct TreeNode* root = createTreeNode(1);
  root->left = createTreeNode(4);
  root->right = createTreeNode(2);
  root->right->right = createTreeNode(2);

  printf("%d\n", maxDepth(root));

  return 0;
}
