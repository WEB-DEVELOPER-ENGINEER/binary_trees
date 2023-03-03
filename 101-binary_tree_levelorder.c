#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);
	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	}
	return ((l > r) ? l : r);
}

/**
 * print_level - print the nodes by level
 * @func: pointer to a functionn
 * @level: the level
 * @node: pointer to the node
 */
void print_level(binary_tree_t *node, void (*func)(int), int level)
{
	if (node != NULL && func != NULL)
	{
		if (level == 1)
			func(node->n);
		if (level > 1)
		{
			print_level(node->left, func, level - 1);
			print_level(node->right, func, level - 1);
		}
	}
}

/**
 * binary_tree_levelorder - level-order traversal
 * @tree: pointer to the tree
 * @func: pointer to a function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	size_t height = 0;
	size_t counter;
	binary_tree_t *copy_tree = (binary_tree_t *)tree;

	height = binary_tree_height(tree);
	for (counter = 0; counter <= height + 1; counter++)
		print_level(copy_tree, func, counter);
}
