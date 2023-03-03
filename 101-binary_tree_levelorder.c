#include "binary_trees.h"
size_t binary_tree_height2(const binary_tree_t *tree);

/**
 * binary_tree_height2 - measures the height of a binary tree
 * @tree: pointer to tree
 * Return: height
 */
size_t binary_tree_height2(const binary_tree_t *tree)
{
int cont1 = 0, cont2 = 0;

if (tree == NULL)
	return (0);
if (tree->left != NULL)
	cont1 += binary_tree_height2(tree->left);
if (tree->right != NULL)
	cont2 += binary_tree_height2(tree->right);
if (cont1 > cont2)
	return (cont1 + 1);
return (cont2 + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to tree
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);

return ((binary_tree_height2(tree)) - 1);
}

/**
 * print_level - print the nodes by level
 * @func: pointer to a functionn
 * @level: the level
 * @node: pointer to the node
 */
void print_level(const binary_tree_t *node, void (*func)(int), int level)
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
	size_t height = 0, counter;

	height = binary_tree_height(tree);
	for (counter = 0; counter <= height + 1; counter++)
		print_level(tree, func, counter);
}
