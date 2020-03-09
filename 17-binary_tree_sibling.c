#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *dad = NULL;

	if (!node || !(node->parent))
		return (NULL);

	dad = node->parent;

	if (dad->left && (dad->left != node))
		return (dad->left);
	else if (dad->right && (dad->right != node))
		return (dad->right);
	return (NULL);
}
