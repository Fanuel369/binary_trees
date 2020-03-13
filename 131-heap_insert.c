#include "binary_trees.h"
/**
 * binary_tree_height_add - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
int _height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (-1);

	height_l = _height(tree->left);
	height_r = _height(tree->right);

	if (height_l > height_r)
		return (height_l + 1);
	return (height_r + 1);
}
/**
 * greater_than_parent - check if child is greather than parent to check
 * @parent: Node parent of the inserting node
 * @child: Node inserted to check with the parent
 * Return: Not return, only order the tree in a heap
 */
void greater_than_parent(heap_t **parent, heap_t **child)
{
	heap_t *n_child = *child, *n_parent = *parent;

	if (n_child->n > n_parent->n)
	{
		if (n_parent->right)
			n_child->right = n_parent->right;
		if (n_parent->left)
			n_child->right->left = n_parent->left;
		if (n_parent->left == n_child)
			n_parent->left = n_child->left;
		n_child->left->parent = n_parent;
	}
}
/**
 * is_perfect - check if the subtrees has the same height
 * and check for each subtree be perfect
 * @root: Tree or subtree to check
 * Return: 1 if subtree or tree is perfect or not
 */
int is_perfect(const binary_tree_t *root)
{
	if (root->left && _height(root->left) == _height(root->right))
	{
		if (_height(root->left) == -1)
			return (1);

		if ((root->right) &&
		    (!(root->right->left) && !(root->right->right)) &&
		    (root->left) &&
		    (!(root->left->right) && !(root->left->left)))
			return (1);

		if (root && root->left && root->right)
			return (is_perfect(root->left)
				&& is_perfect(root->right));
	}
	return (0);
}
/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @tree: double pointer to the root node of the Heap to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;

	if (!root)
	{
		*root = binary_tree_node(NULL, value);
		return (NULL);
	}
	if (is_perfect(*root) && is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new = heap_insert(&(*root)->left, value);
			greater_than_parent(&(*root)->left, &new);
			return (new);
		}

		else if ((*root)->right)
		{
			new = heap_insert(&(*root)->right, value);
			greater_than_parent(&(*root)->right, &new);
			return (new);
		}
	}
	if ((*root)->right)
	{
		new = heap_insert(&(*root)->right, value);
		greater_than_parent(&(*root)->right, &new);
	}

		else if ((*root)->right)
		{
			new = heap_insert(&(*root)->right, value);
			greater_than_parent(&(*root)->right, &new);
		}
	}
	return (NULL);
}
