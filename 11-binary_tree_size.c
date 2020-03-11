#include "binary_trees.h"

/**
 * binary_tree_height_add - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height_add(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height_add(tree->left);

	if (tree->right)
		height_r = 1 + binary_tree_height_add(tree->right);

	return (height_l + height_r);
}


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the node to measure the size
 *
 * Return: Size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height_add(tree) + 1);
}
