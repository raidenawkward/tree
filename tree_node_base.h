#ifndef _TREE_NODE_BASE_H
#define _TREE_NODE_BASE_H

#include <stdio.h>
#include <stdlib.h>
#include "tree_define.h"
#include "tree_node.h"

/// get root node from a node
struct tree_node* treenode_get_root (struct tree_node* node);
/// get parent node of a node
struct tree_node* treenode_get_parent (struct tree_node* node);
/// get child count of a node
Int32 treenode_child_count (struct tree_node *node);
/// append node 'child' as last child of target node, true returns if suddeed
Boolean treenode_append_child (struct tree_node *node, struct tree_node *child);
/// insert node 'child' to target node as index, true returns if suddeed
Boolean treenode_insert_child (struct tree_node *node, Int32 index, struct tree_node *child);
/// get first child of node
struct tree_node* treenode_get_first_child (struct tree_node *node);
/// get last child of node
struct tree_node* treenode_get_last_child (struct tree_node *node);
/// get index child of node
struct tree_node* treenode_get_child (struct tree_node *node, Int32 index);
/// get index of child node from parent node, -1 returns if not found
Int32 treenode_get_child_index (struct tree_node *node, struct tree_node *child);
/// remove node from node, but returns the node that was removed from node
struct tree_node* treenode_remove_child (struct tree_node *node, int index);
/// get left sibling of node in parent node
struct tree_node* treenode_get_left_sibling (struct tree_node *node);
/// get right sibling of node in parent node
struct tree_node* treenode_get_right_sibling (struct tree_node *node);
/// compare tree node
Boolean treenode_equal_node (struct tree_node *n1, struct tree_node *n2);
#endif // _TREE_NODE_BASE_H
