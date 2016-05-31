#ifndef BST_NODE_H
#define BST_NODE_H

#include"Employee_record.h"

class bst_node
{
	friend class avl;
	friend class bst;
	
	protected:
	Employee_record data;	
	bst_node *left;
	bst_node *right;
	bst_node *parent;

};

#endif
