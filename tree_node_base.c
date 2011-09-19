#include "tree_node_base.h"

struct tree_node* treenode_get_root (struct tree_node* node) {
	if (!node)
		return NULL;
	struct tree_node* ret = node->parent;
	while (ret) {
		ret = ret->parent;
	}
	return ret;
}

struct tree_node* treenode_get_parent (struct tree_node* node) {
	if (!node)
		return NULL;
	return node->parent;
}

Int32 treenode_child_count (struct tree_node *node) {
	if (!node)
		return 0;
	return node->child_count;
}

Boolean treenode_append_child (struct tree_node *node, struct tree_node *child) {
	Boolean ret = false;
	if (!node || !child)
		return ret;
	struct tree_node *insert_point = treenode_get_last_child(node);
	if (!insert_point)
		return ret;
}

Boolean treenode_insert_child (struct tree_node *node, Int32 index, struct tree_node *child) {
}

struct tree_node* treenode_get_last_child (struct tree_node *node) {
}

struct tree_node* treenode_get_first_child (struct tree_node *node) {
}

struct tree_node* treenode_get_child (struct tree_node *node, Int32 index) {
}

Int32 treenode_get_child_index (struct tree_node *node, struct tree_node *child) {
}

struct tree_node* treenode_remove_child (struct tree_node *node, int index) {
}
 /// remove node from tree, but returns the node
struct tree_node* treenode_get_left_sibling (struct tree_node *node) {
}

struct tree_node* treenode_get_right_sibling (struct tree_node *node) {
}


