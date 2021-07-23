#include <stdlib.h>
#include "binary_trees.h"

/**
 * min_node - returns the min node in a tree
 * @node: pointer to the node whose min node is required
 *
 * Return: min node or NULL
 */
bst_t *min_node(bst_t *node)
{
	bst_t *temp = node;

	while (temp != NULL && temp->left != NULL)
		temp = temp->left;

	return (temp);
}

/**
 * bst_search - insert a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to search the value in
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the node or NULL on failure
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *curr = (bst_t *)tree;

	while (curr != NULL)
	{
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else if (value == curr->n)
			break;
	}
	return (curr);
}


/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *parent = NULL, *curr = NULL, *succ = NULL;

	if (root == NULL)
		return (root);

	curr = bst_search(root, value);
	if (curr == NULL)
		return (root);

	parent = curr->parent;
	if (curr->left == NULL && curr->right != NULL)
	{
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
		free(curr);
	}
	else if (curr->left != NULL && curr->right != NULL)
	{
		succ = min_node(curr->right);
		curr->n = succ->n;
		bst_remove(curr->right, succ->n);
	}
	else
	{
		if (curr->left != NULL)
			succ = curr->left;
		else
			succ = curr->right;

		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = succ;
			else
				parent->right = succ;
		}
		else
		{
			root = succ;
		}
		free(curr);
	}
	return (root);
}
