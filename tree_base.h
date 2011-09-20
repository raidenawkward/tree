#ifndef _TREE_BASE_H
#define _TREE_BASE_H

#include "tree_define.h"
#include "tree.h"
#include "tree_operation.h"

/// empty new tree created, root node returns, NULL if failed
Boolean tree_create (struct Tree **tree, tree_type_t type);
/// tree destory, and nodes of tree would also be deleted
void tree_destory (struct Tree **tree);
/// clear tree members, and nodes of tree would also be deleted
Int32 tree_clear (struct Tree **tree);
/// returns numbers of cleared nodes
Boolean tree_is_empty (struct Tree *tree);
/// returns depth of tree (0 is beginning)
Int32 tree_tree_depth (struct Tree *tree);
/// travserse tree though function visit, traverse stops until visit returns less than 0
void tree_traverse (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*));
/// returns root node of a tree
struct tree_node* tree_root_of_tree (struct Tree *tree);


#endif // _TREE_BASE_H
