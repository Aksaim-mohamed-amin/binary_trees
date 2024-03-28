#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: depth of the tree or 0 if tree is null.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
