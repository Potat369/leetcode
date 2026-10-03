#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
  if (root == NULL) return NULL;

  struct TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  invertTree(root->left);
  invertTree(root->right);

  return root;
}

struct TreeNode* createTreeNode(int val) {
  struct TreeNode* node = malloc(sizeof(struct TreeNode));

  node->val = val;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int main() {
  struct TreeNode* root = createTreeNode(4);
  root->left = createTreeNode(5);
  root->left->left = createTreeNode(6);

  invertTree(root);

  printf("%d %d %d\n", root->val, root->right->val, root->right->right->val);

  return 0; 
}
