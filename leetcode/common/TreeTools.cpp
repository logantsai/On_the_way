#include <iostream>
#include "TreeTools.h"

/**
  * Preorder : root left right
  * Postorder : left right root
  * Inorder : left root right
  */

void printTreePreorder(TreeNode *root)
{
	if (!root) return;
	std::cout << root->val << " ";
	printTreePreorder(root->left);
	printTreePreorder(root->right);
}
