#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 *
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: Pointer to the node containing a value equals to value,
 *         and NULL if nothing is found or tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));

	if (tree->n < value)
		return (bst_search(tree->right, value));

	return (NULL);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 *
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *rm_node;

	rm_node = bst_search(root, value);

	/* Case if value not found in the tree */
	if (rm_node == NULL)
		return (root);

	
	return (root);
}
