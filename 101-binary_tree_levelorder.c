#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

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

/**
 * binary_tree_inorder - Goes through a binary tree using pre-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: Level of the node to apply func on it.
 */
void binary_tree_inorder_level(const binary_tree_t *tree,
			       void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left)
		binary_tree_inorder_level(tree->left, func, level);

	if (binary_tree_depth(tree) == level)
		func(tree->n);

	if (tree->right)
		binary_tree_inorder_level(tree->right, func, level);
}
/**
 * binary_tree_levelorder - Goes through a binary tree using
 *                          level-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_height, level = 0;

	if (tree == NULL)
		return;

	tree_height = binary_tree_height(tree);

	while (level < tree_height)
	{
		binary_tree_inorder_level(tree, func, level);
		level++;
	}
}