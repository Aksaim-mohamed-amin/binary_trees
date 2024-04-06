#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree,
 *              If the node to be deleted has two children,
 *              it must be replaced with its first in-order successor
 *              (not predecessor).
 *
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the node.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else if (value == root->n)
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(tmp);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}

		tmp = root->right;
		while (tmp !=NULL && tmp->left != NULL)
			tmp = tmp->left;

		root->n = tmp->n;

		root->right = bst_remove(root->right, tmp->n);
	}

	return (root);
}
