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
	struct tree_node_operations *node_opera;
};

/// operations for tree
struct tree_operations {
	/// operations for tree
	Boolean (*create) (struct Tree **tree, tree_type_t type);
	void (*destory) (struct Tree **tree);
	Int32 (*clear) (struct Tree **tree); /// returns numbers of cleared nodes
	Boolean (*is_empty) (struct Tree *tree);
	Int32 (*tree_depth) (struct Tree *tree); /// returns depth of tree (0 is beginning)
	Int32 (*tree_width) (struct Tree *tree); /// returns node count between most left and most right nodes;
	Int32 (*node_count) (struct Tree *tree); /// get total nodes count in a tree
	void (*traverse) (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*)); /// traverse stops until visit returns less than 0
	struct tree_node* (*root_of_tree) (struct Tree *tree);
	Boolean (*isParallel) (struct Tree *t1, struct Tree *t2); /// returns if t1,t2 have no joint node
};

#endif // _TREE_H
