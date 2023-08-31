#include "binary_trees.h"

/**
 * binary_tree_balance - meausres the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0;
	int height_right = 0;

	if (tree == NULL)
		return (0);

	height_left = (tree->left) ? (int)binary_tree_height(tree->left) : -1;
	height_right = (tree->right) ? (int)binary_tree_height(tree->right) : -1;

	return (height_left - height_right);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the tree to measure the height
 * Return: height of 0 on failure
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height  > right_height ? left_height : right_height));
}
