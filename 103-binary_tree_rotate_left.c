#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_tree = tree->right;

	tree->right = new_tree->left;
	tree->parent = new_tree;

	new_tree->left = tree;
	new_tree->parent = tree->parent;

	return (new_tree);
}
