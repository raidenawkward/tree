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
	if (!node)
		return false;
	return treenode_insert_child(node,node->child_count - 1,child);
}

Boolean treenode_insert_child (struct tree_node *node, Int32 index, struct tree_node *child) {
	Boolean ret = false;
	if (!node || !child)
		return ret;
	if (index < 0 || node->child_count || index >= node->child_count)
		return ret;

	struct tree_node **new_base = (struct tree_node**)realloc(node->childs,(node->child_count + 1) * sizeof(struct tree_node*));
	if (!new_base)
		return ret;
	node->childs = new_base;
	++ node->child_count;
	Int32 i;
	for (i = index; i < node->child_count - 1; ++i) {
		node->childs[i + 1] = node->childs[i];
	}
	node->childs[index] = child;

	ret = true;
	return ret;
}

struct tree_node* treenode_get_last_child (struct tree_node *node) {
	if (!node)
		return NULL;
	return treenode_get_child(node,node->child_count - 1);
}

struct tree_node* treenode_get_first_child (struct tree_node *node) {
	return treenode_get_child(node,0);
}

struct tree_node* treenode_get_child (struct tree_node *node, Int32 index) {
	if (!node)
		return NULL;
	if (index < 0 || index >= node->child_count)
		return NULL;

	return node->childs[index];
}

Int32 treenode_get_child_index (struct tree_node *node, struct tree_node *child) {
	Int32 ret = -1;
	if (!node || !child)
		return ret;

	Int32 i;
	for (i = 0; i < node->child_count; ++i) {
		struct tree_node *node = node->childs[i];
		if (treenode_equal_node) {
			ret = i;
			break;
		}
	}
	return ret;
}

struct tree_node* treenode_remove_child (struct tree_node *node, int index) {
	if (!node)
		return NULL;
	if (index < 0 || index >= node->child_count)
		return NULL;

	struct tree_node *ret = node->childs[index];
	Int32 i;
	for (i = index; i < node->child_count - 1; ++i) {
		node->childs[i] = node->childs[i + 1];
	}
	-- node->child_count;

	return ret;
}

struct tree_node* treenode_get_left_sibling (struct tree_node *node) {
	if (!node)
		return NULL;
	if (!node->parent)
		return NULL;

	int index = treenode_get_child_index(node->parent, node);
	return treenode_get_child(node->parent,index - 1);
}

struct tree_node* treenode_get_right_sibling (struct tree_node *node) {
	if (!node)
		return NULL;
	if (!node->parent)
		return NULL;

	int index = treenode_get_child_index(node->parent, node);
	return treenode_get_child(node->parent,index + 1);
}

Boolean treenode_equal_node (struct tree_node *n1, struct tree_node *n2) {
	Boolean ret = false;
	if (!n1 || !n2)
		return ret;

	if (n1->flag != n2->flag)
		return ret;
	if (n1->parent != n2->parent)
		return ret;
	if (n1->child_count != n2->child_count)
		return ret;
	if (n1->data != n2->data)
		return ret;
	if (n1->childs != n2->childs)
		return ret;

	ret = true;
	return ret;
}
