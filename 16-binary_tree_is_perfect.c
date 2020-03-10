#include "binary_trees.h"
/**
 * depthLeft - get the depth for all left nodes
 * @root: node to check
 * Return: Depth of node
 */
int depthLeft(const binary_tree_t *root)
{
	int d = 0;

	while (root != NULL)
	{
		d++;
		root = root->left;
	}
	return (d);
}
/**
 * isPerfectRec - recursive function to check if
 * a binary tree is full and has the same level of childs
 * @root: node to check
 * @d: depth for left nodes
 * @level: Initial level compared with depth
 * Return: 1 if it is perfect, 0 is NULL or isn't perfect
 */
int isPerfectRec(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (0);
	if (root->left == NULL && root->right == NULL)
		return (d == level + 1);
	if (root->left == NULL || root->right == NULL)
		return (0);
	return (isPerfectRec(root->left, d, level + 1)
		&& isPerfectRec(root->right, d, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if it is NULL or if it is imperfect or 1 it is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depthLeft(tree);

	return (isPerfectRec(tree, d, 0));
}
