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
	bst_t *node;

	if (root == NULL)
		return (root);

	node = bst_search(root, value);

	/* If value not found in tree */
	if (node == NULL)
		return (root);

	/* If value found in a leaf */
	if (node->left == NULL && node->right == NULL)
		binary_tree_remove_leaf(node);

	/* If value have a child or two */
	if (node->left || node->right)
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

	if (tree->n < value)
		return (bst_search(tree->right, value));

	return (NULL);
}

/**
 * binary_tree_remove_leaf - Remove a leaf from binary tree.
 *
 * @leaf: Pointer to the leaf.
 */
void binary_tree_remove_leaf(binary_tree_t *leaf)
{
	if (leaf->parent)
	{
		if (leaf->parent->left == leaf)
			leaf->parent->left = NULL;
		else
			leaf->parent->right = NULL;
	}
	free(leaf);
}

/**
 * bst_swapp_with_leaf - Swap the root with a leaf node in-order successor.
 *
 * @root: Pointer to the root to swap.
 *
 * Return: pointer to the leaf swapped with it.
 */
bst_t *bst_swapp_with_leaf(bst_t *root)
{
	int tmp;
	bst_t *leaf;

	leaf = (root->right != NULL) ? root->right : root->left;

	while (leaf->left || leaf->right)
	{
		if (leaf->left)
			leaf = leaf->left;
		else
			leaf = leaf->right;
	}
	tmp = leaf->n;
	leaf->n = root->n;
	root->n = tmp;

	return (leaf);
}
