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
 */bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;

	bst_t *node = bst_search(root, value);

	if (node == NULL)
		return root; // Value not found

	// If node has at most one child
	if (node->left == NULL || node->right == NULL) {
		bst_t *child = (node->left != NULL) ? node->left : node->right;

		if (child != NULL)
			child->parent = node->parent;

		if (node->parent == NULL)
			root = child;
		else if (node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;

		free(node);
	} else { // If node has two children
		bst_t *successor = bst_successor(node);
		node->n = successor->n;
		root = bst_remove(root, successor->n); // Remove the successor
	}

	return root;
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
 * bst_successor - Swap a node with it in order successor.
 *
 * @node: Pointer to the node to swap.
 *
 * Return: Pointer to the new position of the node.
 */
bst_t *bst_successor(binary_tree_t *node)
{
	int tmp;
	bst_t *leaf;

	leaf = (node->right != NULL) ? node->right : node->left;

	while (leaf->left || leaf->right)
	{
		if (leaf->left)
			leaf = leaf->left;
		else
			leaf = leaf->right;
	}
	tmp = leaf->n;
	leaf->n = node->n;
	node->n = tmp;

	return (leaf);
}
