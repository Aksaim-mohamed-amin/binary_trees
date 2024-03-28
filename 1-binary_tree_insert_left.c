#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insrt a node as the left-child of another node.
 *
 * @parent: Pointer to the node to insert the left child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);

	left_child = binary_tree_node(parent, value);
	if (left_child == NULL)
		return (NULL);

	left_child->parent = parent;
	if (parent->left)
	{
		left_child->left = parent->left;
		parent->left->parent = left_child;
	}
	parent->left = left_child;

	return (left_child);
}
