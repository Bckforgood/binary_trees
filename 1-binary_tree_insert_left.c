#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* Check if parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new left child node */
	binary_tree_t *new_left = binary_tree_node(parent, value);

	if (new_left == NULL)
		return (NULL);

	/* If parent already has a left child, rearrange nodes */
	if (parent->left != NULL)
	{
		new_left->left = parent->left;
		parent->left->parent = new_left;
	}

	/* Set new left child and return */
	parent->left = new_left;
	return (new_left);
}
