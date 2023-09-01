#include "binary_trees.h"
#include "queue.h" // You can include your own queue implementation or use a standard library queue

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    queue_t *queue = NULL;
    binary_tree_t *node = NULL;

    queue_push(&queue, (void *)tree);

    while (!queue_is_empty(queue))
    {
        node = (binary_tree_t *)queue_pop(&queue);

        if (node)
        {
            func(node->n);
            if (node->left)
                queue_push(&queue, (void *)node->left);
            if (node->right)
                queue_push(&queue, (void *)node->right);
        }
    }

    queue_free(&queue);
}

