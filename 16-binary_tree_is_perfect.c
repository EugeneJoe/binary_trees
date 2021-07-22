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

	Lh = binary_tree_height(tree->left);
	Rh = binary_tree_height(tree->right);
	return (max(Lh, Rh) + 1);
}

/**
 * count_no_of_nodes - count number of nodes in a binary tree
 * @root: pointer to root node of tree
 *
 * Return: no. of nodes
 */
int count_no_of_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + count_no_of_nodes(root->left) + count_no_of_nodes(root->right));
}

/**
 * binary_tree_is_perfect - determine whether a binary tree is a perfect tree
 * @root: pointer to root node of tree
 *
 * Return: 1 if tree is a perfect tree, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *root)
{
	int h, total_no_of_nodes, hh = 1;

	h = binary_tree_height(root);
	total_no_of_nodes = count_no_of_nodes(root);
	hh = 1;
	while (h != 0)
	{
		hh *= 2;
		--h;
	}
	if (total_no_of_nodes == (hh - 1))
		return (1);
	else
		return (0);
}
