#include "tree_base.h"

Boolean tree_create (struct Tree **tree, tree_type_t type) {
	*tree = (struct Tree*)malloc(sizeof(struct Tree));
	if (!(*tree))
		return false;

	(*tree)->root = NULL;

	struct tree_node_operations *node_op = treenode_get_operation();
	(*tree)->node_opera = node_op;

	(*tree)->type = type;
	(*tree)->max_child_count_of_node = -1;

	return true;
}

void tree_destory (struct Tree **tree) {
	tree_clear(tree);
	if (*tree)
		free(*tree);
}

static Int32 free_tree_node(struct tree_node *node) {
	if (!node)
		return 0;

	Int32 ret = 1,i;

	for (i = 0; i < node->child_count; ++i) {
		struct tree_node *child = node->childs[i];
		ret += free_tree_node(child);
	}
	for (i = 0; i < node->child_count; ++i) {
		free(node->childs[i]);
	}
	node->child_count = 0;
	return ret;
}

Int32 tree_clear (struct Tree **tree) {
	Int32 ret = 0;
	if (!tree || !(*tree))
		return ret;
	if (!(*tree)->root)
		return ret;
	ret = free_tree_node((*tree)->root);
	(*tree)->root = NULL;
	return ret;
}

Boolean tree_is_empty (struct Tree *tree) {
	Boolean ret = false;
	if (!tree)
		return ret;

	if (!tree->root)
		return ret;

	ret = true;
	return ret;
}

static Int32 traverse_for_depth(struct tree_node *node,Int32 depth) {
	if (!node)
		return depth;
	Int32 i,ret = depth;
	for (i = 0; i < node->child_count; ++i) {
		Int32 new_ret = traverse_for_depth(node->childs[i],depth + 1);
		if (new_ret > ret)
			ret = new_ret;
	}

	return ret;
}

Int32 tree_tree_depth (struct Tree *tree) {
	Int32 ret = 0;
	if (!tree)
		return ret;
	if (!tree->root)
		return ret;

	ret = traverse_for_depth(tree->root,0);

	return ret;
}

static Int32 get_node_child_nodes(struct tree_node *node) {
	if (!node)
		return 0;
	Int32 ret = 1,i;
	for (i = 0; i < node->child_count; ++i) {
		ret += get_node_child_nodes(node->childs[i]);
	}
	return ret;
}

Int32 tree_node_count (struct Tree *tree) {
	Int32 ret = 0;
	if (!tree)
		return ret;
	if (!tree->root)
		return ret;
	ret = get_node_child_nodes(tree->root);
	return ret;
}

static Int32 depth_priority_traverse(struct tree_node *node, Int32 (*visit) (struct tree_node*)) {
	if (!node)
		return -1;
	Int32 i;

	if (visit(node) < 0)
		return -1;

	for (i = 0; i < node->child_count; ++i) {
		if (depth_priority_traverse(node->childs[i],visit) < 0)
			return -1;
	}
	return 1;
}

static Int32 width_priority_traverse(struct tree_node *node, Int32 (*visit) (struct tree_node*)) {
	if (!node)
		return -1;

	Int32 i;
	for (i = 0; i < node->child_count; ++i) {
		if (visit(node->childs[i]) < 0)
			return -1;
	}

	for (i = 0; i < node->child_count; ++i) {
		if (width_priority_traverse(node->childs[i], visit) < 0)
			return -1;
	}
	return 1;
}

void tree_traverse (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*)) {
	if (!tree)
		return;
	if (!tree->root)
		return;
	switch (type) {
	case TREE_TRAVERSE_DEPTHPRIORITY:
		depth_priority_traverse(tree->root,visit);
		break;
	case TREE_TRAVERSE_WIDTHPRIORITY:
		if (!visit(tree->root))
			return;
		width_priority_traverse(tree->root,visit);
		break;
	default:
		break;
	}
}

struct tree_node* tree_root_of_tree (struct Tree *tree) {
	if (!tree)
		return NULL;
	return tree->root;
}


