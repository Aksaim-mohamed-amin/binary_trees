#include "binary_trees.h"

/**
 * binary_tree_contain - Check if a tree contain a node.
 *
 * @tree: Pointer to the tree to search in it.
 * @node: The node to search for it.
 *
 * Return: 1 if the tree contain the node 0 otherwise.
 */
size_t binary_tree_contain(const binary_tree_t *tree,
			   const binary_tree_t *node)
{
	binary_tree_t *left, *right;

	if (tree == NULL || node == NULL)
		return (0);

	if (tree == node)
		return (1);

	left = tree->left;
	right = tree->right;
	return (binary_tree_contain(left, node) + binary_tree_contain(right, node));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the first node.
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         If no common ancestor was found NULL will be returned.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	while (first != NULL)
	{
		if (binary_tree_contain(first, second))
			return ((binary_tree_t *)first);
		first = first->parent;
	}

	return (NULL);
}
