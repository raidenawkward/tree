#include <stdio.h>
#include "tree_define.h"
#include "tree.h"
#include "tree_base.h"
#include "tree_node.h"
#include "tree_node_base.h"
#include "tree_operation.h"

static Int32 print_node (struct tree_node* node) {
	if (node) {
		printf("node : %c\n",node->data);
		return 1;
	} else
		return -1;
}

int main(int argc, char** argv) {
	struct tree_operations *tree_op = tree_get_operation();
	struct tree_node_operations *node_op = treenode_get_operation();

	if (!node_op || !tree_op)
		return -1;

	struct Tree *tree;
	tree_op->create(&tree,TREE_TYPE_NORMAL);
	tree->node_opera = node_op;

	struct tree_node *n1 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n1->data = 'a';
	n1->child_count = 0;
	struct tree_node *n2 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n2->data = 'b';
	n2->child_count = 0;
	struct tree_node *n3 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n3->data = 'c';
	n3->child_count = 0;
	struct tree_node *n4 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n4->data = 'd';
	n4->child_count = 0;
	struct tree_node *n5 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n5->data = 'e';
	n5->child_count = 0;
	struct tree_node *n6 = (struct tree_node*)malloc(sizeof(struct tree_node));
	n6->data = 'f';
	n6->child_count = 0;

	tree->root = n1;
	node_op->append_child(n1,n2);
	node_op->append_child(n1,n3);
	node_op->append_child(n2,n4);
	node_op->append_child(n3,n5);
	node_op->append_child(n3,n6);
//	tree->root = NULL;
#if 1
	struct tree_node **ret_nodes;
	Int32 depth = 0;
	Int32 count = tree_op->depth_nodes(tree,depth,&ret_nodes);
	printf("childs count of depth %d : %d\n",depth,count);
	printf("they are : \n");
	Int32 i;
	for (i = 0; i < count; ++i) {
		printf("%c\n",ret_nodes[i]->data);
	}
#endif
#if 0
	printf("%d nodes saved\n",tree_op->save(tree,"./save.tree"));

	struct Tree *tree2;
	printf("%d nodes loaded\n",tree_op->load(&tree2,"./save.tree"));

	printf("childs of root 1 : %d\n",node_op->child_count(tree->root));
	printf("childs of root 2 : %d\n",node_op->child_count(tree2->root));
	printf("traverse t1 : \n");
	tree_op->traverse(tree,TREE_TRAVERSE_DEPTHPRIORITY,print_node);
	printf("\ntraverse t2 : \n");
	tree_op->traverse(tree2,TREE_TRAVERSE_DEPTHPRIORITY,print_node);
#endif
#if 0
	printf("distance between n4 and n6 : %d\n",node_op->get_node_distance(n4,n6));
	printf("distance between n1 and n6 : %d\n",node_op->get_node_distance(n1,n6));
	printf("distance between n2 and n6 : %d\n",node_op->get_node_distance(n2,n6));
#endif
#if 0
	printf("depth of n1 : %d\n",node_op->get_node_depth(n1));
	printf("depth of n2 : %d\n",node_op->get_node_depth(n2));
	printf("depth of n3 : %d\n",node_op->get_node_depth(n3));
	printf("depth of n4 : %d\n",node_op->get_node_depth(n4));
	printf("depth of n5 : %d\n",node_op->get_node_depth(n5));
	printf("depth of n6 : %d\n",node_op->get_node_depth(n6));
#endif
#if 0
//	tree_op->traverse(tree,TREE_TRAVERSE_DEPTHPRIORITY,print_node);
	tree_op->traverse(tree,TREE_TRAVERSE_WIDTHPRIORITY,print_node);
	printf("depth of tree : %d\n",tree_op->tree_depth(tree));
	printf("width of tree : %d\n",tree_op->tree_width(tree));
	printf("before clear, count of tree is :%d\n",tree_op->node_count(tree));
	printf("clear tree , %d nodes were free\n",tree_op->clear(&tree));
	printf("after clear, count of tree is :%d\n",tree_op->node_count(tree));
#endif
	tree_op->destory(&tree);
#if 0
	Int32 i;
	for (i = 0; i < node_op->child_count(n1); ++i) {
		struct tree_node *node = node_op->get_child(n1,i);
		printf("child %d of n1 : %c\n",i,node->data);
	}
	Int32 j;
	for (j = 0; j < node_op->child_count(n2); ++j) {
		struct tree_node *node = node_op->get_child(n2,j);
		printf("child %d of n2 : %c\n",j,node->data);
	}
	printf("removed : %c\n",node_op->remove_child(n1,3)->data);
	printf("first : %c\n",node_op->get_first_child(n1)->data);
	printf("last : %c\n",node_op->get_last_child(n1)->data);
	printf("index : 3 : %c\n",node_op->get_child(n1,3)->data);
	printf("index of n2 : %d\n",node_op->get_child_index(n1,n2));
	printf("l sibling of n3 : %c\n",node_op->get_left_sibling(n3)->data);
	printf("r sibling of n3 : %c\n",node_op->get_right_sibling(n3)->data);
	printf("root of  n4 : %c\n",node_op->get_root(n4)->data);
#endif
	return 0;
}
