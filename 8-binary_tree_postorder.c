#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through binary tree using pre-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left)
		binary_tree_postorder(tree->left, func);

	if (tree->right)
		binary_tree_postorder(tree->right, func);

	func(tree->n);
}
