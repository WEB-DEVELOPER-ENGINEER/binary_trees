#include "binary_trees.h"
size_t balance(const binary_tree_t *tree, const binary_tree_t *tree2);
/**
 * balance - measures the balance factor of a binary tree
 * @tree: pointer to tree
 * @tree2: pointer to sub tree
 * Return: Balance factor
 */
size_t balance(const binary_tree_t *tree, const binary_tree_t *tree2)
{
int cont1 = 0, cont2 = 0;

if (tree == NULL)
	return (0);
if (tree->left != NULL)
	cont1 += balance(tree->left, tree2);
if (tree->right != NULL)
	cont2 += balance(tree->right, tree2);
if (tree == tree2)
	return (cont1 - cont2);
if (cont1 > cont2)
	return (cont1 + 1);
return (cont2 + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to tree
 * Return: Balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
if (tree == NULL)
	return (0);
return (balance(tree, tree));
}
