#ifndef _TREE_H
#define _TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "tree_define.h"
#include "tree_node.h"


struct Tree {
	struct tree_node* root;
	tree_type_t type;
	Int32 max_child_count_of_node;
	struct tree_operations *tree_opera;
	struct tree_node_operations *node_opera;
};

/// operations for tree
struct tree_operations {
	/// operations for tree
	void (*create) (struct Tree **tree, tree_type_t type);
	void (*destory) (struct Tree **tree);
	Int32 (*clear) (struct Tree **tree); /// returns numbers of cleared nodes
	Boolean (*is_empty) (struct Tree *tree);
	Int32 (*tree_depth) (struct Tree *tree);
	void (*traverse) (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*));
	struct tree_node* (*root_of_tree) (struct Tree *tree);
};

#endif // _TREE_H
