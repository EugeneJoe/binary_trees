#include "binary_trees.h"

/**
 * binary_tree_depth - return the depth of a node in a binary tree
 * @tree: pointer to node to find depth of
 *
 * Return: depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
