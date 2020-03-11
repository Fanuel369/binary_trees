#include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that performs
 *  a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x, *y = NULL;
	int flag = 0;

	x = tree;
	y = tree->right;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	tree->right = y->left;
	if (y->left != NULL)
		y->left->parent = tree;
	y->parent = tree->parent;
	if (tree->parent == NULL)
	{
		tree = y;
		tree->left = x;
		flag = 1;
	}
	else if (tree == tree->parent->left)
		tree->parent->left = y;
	else
	{
		tree->parent->right = y;
		y->left = y;
	}
	x->parent = y;
	if (flag == 1)
		return(tree);
	return (y->parent);
}
