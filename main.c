#include <stdio.h>
#include "tree_define.h"
#include "tree.h"
#include "tree_base.h"
#include "tree_node.h"
#include "tree_node_base.h"
#include "tree_operation.h"

int main(int argc, char** argv) {
	struct tree_node_operations *node_op = treenode_get_operation();
	if (!node_op)
		return -1;

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

	node_op->append_child(n1,n2);
	node_op->append_child(n1,n3);
	node_op->append_child(n1,n4);
	node_op->insert_child(n1,3,n5);
	node_op->insert_child(n1,4,n6);

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

	return 0;
}
