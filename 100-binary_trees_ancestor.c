#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (!first || !second)
        return NULL;

    if (first == second)
        return (binary_tree_t *)first;

    if (binary_tree_is_descendant(second, first))
        return (binary_tree_t *)first;

    if (binary_tree_is_descendant(first, second))
        return (binary_tree_t *)second;

    return binary_trees_ancestor(first->parent, second->parent);
}

/**
 * binary_tree_is_descendant - Checks if a node is descendant of another node
 * @node: The node to check if it's a descendant
 * @target: The potential ancestor node
 *
 * Return: 1 if @node is a descendant of @target, 0 otherwise
 */
int binary_tree_is_descendant(const binary_tree_t *node, const binary_tree_t *target)
{
    if (!node)
        return 0;

    if (node == target)
        return 1;

    return binary_tree_is_descendant(node->parent, target);
}
