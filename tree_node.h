#ifndef _TREE_NODE_H
#define _TREE_NODE_H

#include <stdio.h>
#include "tree_define.h"


struct tree_node {
	TreeElement data;
	struct tree_node** childs;
	struct tree_node* parent;
	Int32 child_count;
	UInt32 flag;
};

/// operations for tree nodes
struct tree_node_operations {
	struct tree_node* (*get_root) (struct tree_node* node);
	struct tree_node* (*get_parent) (struct tree_node* node);
	Int32 (*child_count) (struct tree_node *node);
	Boolean (*append_child) (struct tree_node *node, struct tree_node *child);
	Boolean (*insert_child) (struct tree_node *node, Int32 index, struct tree_node *child);
	struct tree_node* (*get_first_child) (struct tree_node *node);
	struct tree_node* (*get_last_child) (struct tree_node *node);
	struct tree_node* (*get_child) (struct tree_node *node, Int32 index);
	Int32 (*get_child_index) (struct tree_node *node, struct tree_node *child);
	struct tree_node* (*remove_child) (struct tree_node *node, int index); /// remove node from tree, but returns the node
	struct tree_node* (*get_left_sibling) (struct tree_node *node);
	struct tree_node* (*get_right_sibling) (struct tree_node *node);
	Boolean (*equal_node) (struct tree_node *n1, struct tree_node *n2);
};

#endif // _TREE_NODE_H
