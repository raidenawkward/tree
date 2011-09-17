#include <stdio.h>

#include "tree_define.h"


struct tree_node {
	TreeElement data;
	struct tree_node* child;
	struct tree_node* parent;
	UInt32 flag;
};
