#include "tree_base.h"

void tree_create (struct Tree **tree, tree_type_t type) {
}

void tree_destory (struct Tree **tree) {
}

Int32 tree_clear (struct Tree **tree) {
	return 0;
}

Boolean tree_is_empty (struct Tree *tree) {
	return true;
}

Int32 tree_tree_depth (struct Tree *tree) {
}

void tree_traverse (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*)) {
}

struct tree_node* tree_root_of_tree (struct Tree *tree) {
}


