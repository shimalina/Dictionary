#ifndef BST_H
#define BST_H

#include"Employee_record.h"
#include"bst_node.h"

 class bst
 {
 
 protected:
 bst_node *root;
 int height;
 public:
 //friend void preodertraversal(bst_node *a);

 public:
 bst();
 ~bst();
 bst(const bst &bst);
 void insert(Employee_record &a);
 void delete_element(std::string id,Employee_record &a);
 int search(string id);
 Employee_record find(string id);
 void traversal(int a);
 void preordertraversal(bst_node *node);
 void inordertraversal(bst_node *node);
 void postordertraversal(bst_node *node);
 int height_of_tree();
 int height_of_node(std::string id);
 int height_of_subtree(bst_node* node);
 int no_of_nodes();
 void successor(bst_node *node);
 void update_file(bst_node *node);
 //void predecessor(bst_node *node);
 };


#endif
