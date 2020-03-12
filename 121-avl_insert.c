#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling node or NULL
 */
binary_tree_t *sibling(binary_tree_t *node)
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
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL, *parent = NULL, *node = NULL;
	int lr = 0;

	if (!tree)
		return (NULL);

	current = *tree;

	node = binary_tree_node(current, value);
	if (!node)
		return (NULL);

	if (!current)
	{
		*tree = node;
		return (node);
	}
	while (1)
	{
		parent = current;

		if (value < parent->n)
			current = current->left, lr = 0;
		else if (value > parent->n)
			current = current->right, lr = 1;
		else
			break;

		if (!current)
		{
			if (lr == 0)
				parent->left = node;
			else
				parent->right = node;
			node->parent = parent;
			return (node);
		}
	}
	free(node);
	return (NULL);
}


/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL, *current = NULL;
	avl_t *x = NULL, *y = NULL, *z = NULL;
	int  heightA, heightB, diff;

	printf("TRYING INSERT %d\n", value);
	if (!tree)
		return (NULL);

	new_node = bst_insert(tree, value);

	if (!new_node)
		return (NULL);

	if (!(*tree))
		return (new_node);

	current = new_node;

	printf("CURRENT %d\n", current->n);
	for (; current && current->parent && current->parent->parent
		     ; current = current->parent)
	{

		z = current->parent->parent;
		y = current->parent;
		x = current;
		if (!(z->parent))
			break;
		heightA = tree_height(z);
		heightB = tree_height(sibling(z));
		diff = abs(heightA - heightB);
		printf("Z %d HA %d HB %d\n", z->n, heightA, heightB);
		if (diff >= 1)
		{
			printf("Inside DIFF %d Z %d\n", diff, z->n);
			if (z->left == y && y->left == x)
			{
				printf("Left Left\n");
				binary_tree_rotate_right(z);
			}
			else if (z->left == y && y->right == x)
			{
				printf("Left Right\n");
				binary_tree_rotate_left(y);
				binary_tree_rotate_right(z);
			}
			else if (z->right == y && y->right == x)
			{
				printf("Right Right\n");
				binary_tree_rotate_left(z);
			}
			else if (z->right == y && y->left == x)
			{
				printf("Right Left\n");
				binary_tree_rotate_right(y);
				binary_tree_rotate_left(z);
			}

			break;
		}
	}

	return (new_node);
}
