#include "binary_trees.h"

/**
 * max - return the max value between 2 integers
 * @a: first integer
 * @b: second integer
 *
 * Return: larger value
 */
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Lh, Rh;

	if (tree == NULL)
		return (0);
	else
	{
		Lh = binary_tree_height(tree->left);
		Rh = binary_tree_height(tree->right);
		return (max(Lh, Rh) + 1);
	}
}
