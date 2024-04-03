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
	if (root == NULL)
		return (NULL);

	bst_t *node = bst_search(root, value);

	if (node == NULL)
		return (root);

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent == NULL)
		{
			free(node);
			return (NULL);
		}
		binary_tree_remove_leaf(node);
	}
	else
	{
		node = bst_swapp_with_leaf(node);
		binary_tree_remove_leaf(node);
	}
	return (root);
}

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

	return (bst_search(tree->right, value));
}

/**
 * binary_tree_remove_leaf - Remove a leaf from binary tree.
 *
 * @leaf: Pointer to the leaf.
 */
void binary_tree_remove_leaf(binary_tree_t *leaf)
{
	if (leaf->parent->left == leaf)
		leaf->parent->left = NULL;
	else
		leaf->parent->right = NULL;

	free(leaf);
}

/**
 * bst_swapp_with_leaf - Swap the node with its first in-order successor.
 *
 * @node: Pointer to the node to be swapped.
 *
 * Return: Pointer to the in-order successor swapped with the node.
 */
bst_t *bst_swapp_with_leaf(bst_t *node)
{
	bst_t *successor = node->right;

	while (successor->left != NULL)
		successor = successor->left;

	int tmp = successor->n;

	successor->n = node->n;
	node->n = tmp;

	return (successor);
}
