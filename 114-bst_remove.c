#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: pointer to the node containing a value equals to value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree->n != value)
	{
		if (tree->n > value)
			tree = tree->left;
		else
			tree = tree->right;
		if (!tree)
			return (NULL);
	}
	return ((bst_t *)tree);
}

/**
 * min - get the min node into the right direction of binary tree
 * @node: Node to catch to know the min value
 * Return: Min node;
 */
bst_t *min(bst_t *node)
{
	bst_t *tmp = node;

	while (tmp->left != NULL)
	{
		tmp = tmp->left;
	}
	return (tmp);
}

/**
 * bst_remove - function that removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where you
 * will remove a node
 * @value: is the value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *r = root, *tmp = NULL, *child = NULL;

	tmp = bst_search(root, value);
	if (!tmp)
		return (r);

	if (!tmp->left && !tmp->right)
	{
		free(tmp);
		return (r);
	}
	else if (tmp->left && tmp->right)
	{
		child = min(tmp->right);
		child->parent->left = NULL;
		child->parent = tmp->parent;
		if (tmp->left && tmp->left != child)
		{
			child->left = tmp->left;
			tmp->left->parent = child;
		}
		if (tmp->right && tmp->right != child)
		{
			child->right = tmp->right;
			tmp->right->parent = child;
		}
		free(tmp);
	}
	else
	{
		child = (tmp->left) ? tmp->left : tmp->right;
		child->parent = tmp->parent;
	}
	if (child->parent && child->n < tmp->parent->n)
		tmp->parent->left = child;
	else if (child->parent && child->n > tmp->parent->n)
		tmp->parent->right = child;
	if (!child->parent)
		return (child);
	return (r);
}
