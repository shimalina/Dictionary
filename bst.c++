#include<iostream>
#include"bst.h"
//#include"avl.h"
#include<string>
#include<string.h>
#include<fstream>


using namespace std;


bst::bst()
{
  root=0;
  height=-1;
}

 bst::~bst()
{
  delete root;
   root=0;
}

bst::bst(const bst &bst)
{
  
}


void bst::insert(Employee_record &a)
 {
   bst_node *current=root,*current_py,*p;
   p=new bst_node;int count=0;
   p->left=p->right=0;
   p->data.insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
   if(root==0)    
     {
       root=p;height++;root->parent=0;
     }
   else
     {
       while(current)
	 {
	   if(current->data.get_employee_ID().compare(a.get_employee_ID())<0&&current->right)
	     {
	       current=current->right;count++;
	     }
	   else if(current->data.get_employee_ID().compare(a.get_employee_ID())>0&&current->left)
	     { 
	       current=current->left;count++;
	     }
	   else break;
	 }
       if(current->data.get_employee_ID().compare(a.get_employee_ID())<0) 
	 {
	   current->right=p;
	 }
       else 
	 {
	   current->left=p;
	 }
       p->parent=current;
       if(count+1>height) height=count+1;
      
     }
 }


int bst::search(string id)
 {
   bst_node *current=root;int count=0;
    while(current&&id.compare(current->data.get_employee_ID())!=0)
     {
       if(current->data.get_employee_ID().compare(id)<0&&current->right)
	 {
	   current=current->right;count++;
	 }
       else if(current->data.get_employee_ID().compare(id)>0&&current->left)
	 { 
	   current=current->left;count++;
	 }
       else break;
     }
    if(id.compare(current->data.get_employee_ID())==0) return count;
   else return -1;
 }


 Employee_record bst::find(string id)
{
bst_node *current=root,*p;int count=0;Employee_record a;
    while(current&&id.compare(current->data.get_employee_ID())!=0)
     {
       if(current->data.get_employee_ID().compare(id)<0&&current->right)
	 {
	   current=current->right;count++;
	 }
       else if(current->data.get_employee_ID().compare(id)>0&&current->left)
	 { 
	   current=current->left;count++;
	 }
       else break;
     }
    if(id.compare(current->data.get_employee_ID())==0) 
	{
		p=current;
		a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);
		return a;
	}
  // else return NULL;
}






void bst::delete_element(string id,Employee_record &a)
 {
   bst_node *current=root,*p;

 //searching node to be deleted
    while(current&&id.compare(current->data.get_employee_ID())!=0)
     {
       if(current->data.get_employee_ID().compare(id)<0&&current->right)
	 {
	   current=current->right;
	 }
       else if(current->data.get_employee_ID().compare(id)>0&&current->left)           
	 { 
	   current=current->left;
	 }
       else break;
     }

   //verifying whether given key exists or not and doing further operation
    if(id.compare(current->data.get_employee_ID())==0)                          
      {
	p=current;
	a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);
	if(!current->left  &&!current->right)
	  {
	    if(current==root) root=0;
	    else
	      {
		if(current->data.get_employee_ID().compare(current->parent->data.get_employee_ID())>0)
		  current->parent->right=0;
		else 	current->parent->left =0;   
		p=current->parent;
		delete current;
	      }
	  }
	else if(current->left &&current->right)
	  {
	    int ch=0;
	     //finding successor
	    p=current;
	    p=p->right;
	    while(p&&p->left) {p=p->left;ch=1;}             
	   
	    //successors right child updating as successors parent left child
	    if(ch==1)
	      {
		if(p->right) p->parent->left=p->right;     
		else   p->parent->left=0;
		p->right=current->right;
		p->right->parent=p;
	      }
	   
	    
	    //placing successor in place of node to be deleted
	   
	     p->left=current->left;               // left child of current as p corresponding children
	     p->left->parent=p;

	     p->parent=current->parent;           //p's parent as current's parent

	     //current parent child as p
	     if(current!=root)
	       {
		 if(current->data.get_employee_ID().compare(current->parent->data.get_employee_ID())>0) current->parent->right=p;
		 else current->parent->left=p;
	       }
	  
	    if(current==root) root=p;                  //updating root  in case root is to be deleted

	    current->left=current->right=current->parent=0;
	    delete current;
	
	   
	   
	  }
	else
	  {
	      	if(current->right) 
		  {
		   
		    p=current->right;
		    p->parent=current->parent;
		  }
		else if(current->left ) 
		  {
		    p=current->left;
		    p->parent=current->parent;
		  }
		if(current==root)  root=p;
		else
		  {
		    if(current->data.get_employee_ID().compare(current->parent->data.get_employee_ID())>0)
		      current->parent->right=p;
		    else 	current->parent->left =p; 
		  }
		delete current;
	  }
	traversal(4);
      }
 }




void bst:: update_file(bst_node *node)
{
  if(!node) return;
  if(node==root) 
    {
      std::ofstream fp("employee.txt",ios::trunc);  
      fp<<node->data.employee_ID;
      fp<<'\n';
      fp<<node->data.Name;
       fp<<'\n';
      fp<<node->data.Email;
       fp<<'\n';
      fp<<node->data.Address;
       fp<<'\n';
      fp<<node->data.Position;
       fp<<'\n';
      fp<<node->data.salary;
       fp<<'\n';
      fp<<node->data.mobile_num;
      fp<<'\n';
      fp<<'\n';
      fp.close();
     
    }
  else
    {
  std::ofstream fp("employee.txt",ios::app);
   fp<<node->data.employee_ID;
    fp<<'\n';
   fp<<node->data.Name;
    fp<<'\n';
   fp<<node->data.Email;
    fp<<'\n';
   fp<<node->data.Address;
    fp<<'\n';
   fp<<node->data.Position;
    fp<<'\n';
   fp<<node->data.salary;
    fp<<'\n';
   fp<<node->data.mobile_num;
   fp<<'\n';
   fp<<'\n';
   fp.close();
    }
  update_file(node->left);
  update_file(node->right);
   
}




void bst::preordertraversal(bst_node *node)
{
  if(node==0) return;
  node->data.print_record();
  preordertraversal(node->left);
  preordertraversal(node->right);
}


void bst::inordertraversal(bst_node *node)
{
  if(node==0) return;
  inordertraversal(node->left);
  node->data.print_record();
  inordertraversal(node->right);
}


void bst::postordertraversal(bst_node *node)
{
  if(node==0) return;
  postordertraversal(node->left);
  postordertraversal(node->right);
  node->data.print_record();
}


void bst::traversal(int a)
 {
   if(a==1) preordertraversal(root);
   else if(a==2) inordertraversal(root);
   else if(a==3) postordertraversal(root);
   else if(a==4) update_file(root);
 }
//
//
int bst::height_of_tree()
{
  return height;
}


int bst::height_of_node(string id)
{
  bst_node *current=root;int count=0;
  while(current&&id.compare(current->data.get_employee_ID())!=0)
    {
      if(current->data.get_employee_ID().compare(id)<0&&current->right)
	{
	  current=current->right;count++;
	}
      else if(current->data.get_employee_ID().compare(id)>0&&current->left)
	{ 
	  current=current->left;count++;
	 }
      else break;
    }
  if(id.compare(current->data.get_employee_ID())==0) {cout<<count;return count;}
  else return -1;
}


int bst::height_of_subtree(bst_node* node)
{
  if(!node) return -1;
  int  h_l=0,h_r=0;
  cout<<"IN"<<'\n';
  h_l=height_of_subtree(node->left)+1;
  h_r=height_of_subtree(node->right)+1;
  if(h_l>h_r) return h_l;
  else return h_r;
}



// int no_of_nodes();
void bst::successor(bst_node *node)
{
  // search(id);
  bst_node *p=node;
  if(p->right)
    {
      p=p->right;
      while(p&&p->left) p=p->left;
    }
  else
    {
      if(p->parent->data.get_employee_ID().compare(p->data.get_employee_ID())>0)  p=p->parent;
      else
	{
	  p=p->parent;
	  while(p->parent->data.get_employee_ID().compare(p->data.get_employee_ID())<0) p=p->parent;
	}
    }
  // return p;
}





