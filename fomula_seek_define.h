#ifndef _FOMULA_SEEKER_DEFINE_H
#define _FOMULA_SEEKER_DEFINE_H

#include <stdlib.h>

#define MAX_TREE_CHILD_NODE 1024;

typedef enum {
	OPERA_PLUS = 0,
	OPERA_SUBTRACT,
	OPERA_MULTIPLE,
	OPERA_DIVIDE,
	OPERA_INVALID
} SeekerOperator;

typedef enum {
	TNODE_TYPE_ROOT = 0,
	TNODE_TYPE_NUM,
	TNODE_TYPE_OPERATOR,
	TNODE_TYPE_UNKNOWN
} TreeNodeType;

#endif // _FOMULA_SEEKER_DEFINE_H