#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree != NULL)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (0);
	}
	size_t lDepth = binary_tree_height(tree->left);
	size_t rDepth = binary_tree_height(tree->right);

	if (lDepth > rDepth)
		return (lDepth + 1);
	else
		return (rDepth + 1);
}
