#include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that performs
 * a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y = NULL;
	int flag = 0;

	if (tree == NULL)
		return (NULL);

	x = tree;
	y = tree->right;

	if (tree->right)
	{
		tree->right = y->left;
		if (y->left != NULL)
			y->left->parent = tree;
		y->parent = tree->parent;
		if (tree->parent == NULL)
		{
			tree = y;
			y->left = x;
			flag = 1;
		}
		else if (tree == tree->parent->left)
		{
			tree->parent->left = y;
			tree->parent->right = y->right;
		}
		else
		{
			tree->parent->right = y;
			y->left = x;
		}
		x->parent = y;
		if (flag == 1)
			return (tree);
		return (y->parent);
	}
	return (tree);
}
