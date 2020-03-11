#include "binary_trees.h"
/**
 * binary_tree_rotate_right - function that performs
 *  a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x, *y = NULL;
	int flag = 0;

	if (!tree || !tree->left)
		return (NULL);

	x = tree;
	y = tree->left;

	tree->left = y->right;
	if (y->right != NULL)
		y->right->parent = tree;
	y->parent = tree->parent;
	if (tree->parent == NULL)
	{
		tree = y;
		tree->right = x;
		flag = 1;
	}
	else if (tree == tree->parent->right)
		tree->parent->right = y;
	else
	{
		tree->parent->left = y;
		y->right = y;
	}
	x->parent = y;
	if (flag == 1)
		return (tree);
	return (y->parent);
}
