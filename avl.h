#ifndef AVL_H
#define AVL_H


#include"Employee_record.h"
#include"bst.h"

//class bst;

class avl:public bst
{
 /* protected:
 	bst_node *root;
	int height;*/
  public:
 	avl();
 	//~avl();
 	avl(const avl &avl);
 	void insert(Employee_record &a);
 	void delete_element(std::string id,Employee_record &a);
	int balance_factor(bst_node *node);
	void right_rotation(bst_node *node);
	void left_rotation(bst_node *node);
	void traversal(int a);
 	void preordertraversal(bst_node *node);
	void inordertraversal(bst_node *node);
	void postordertraversal(bst_node *node);
	void update_file(bst_node *node);	
 };

#endif	
