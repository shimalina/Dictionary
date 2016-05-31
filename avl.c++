#include<iostream>
#include"avl.h"
#include<string>
#include<string.h>
#include<fstream>


using namespace std;


avl::avl()
  :bst()
{

}



int avl::balance_factor(bst_node *node)
{
  //if(!node) return -1;
  int h_l=0,h_r=0,bf;
  cout<<"HELLO"<<'\n';
  h_l=height_of_subtree(node->left);
  cout<<h_l;
  h_r=height_of_subtree(node->right);
  cout<<'\n'<<h_r<<'\n';
  bf=h_l-h_r;
  return bf;
}


void avl::right_rotation(bst_node *node)
{
  bst_node *y,*z=node,*p;
  y=z->left;
  if(z!=root)
    {
      p=z->parent;
      y->parent=p;
      if(p->left==z) p->left=y;
      else p->right=y;
    }
  else
    {
      y->parent=0;
      root=y;
    }
  z->parent=y;
  if(y->right) 
    {
      y->right->parent=z;
     
    }
   z->left=y->right;
  y->right=z;
  node=z;
}


void avl::left_rotation(bst_node *node)
{
   bst_node *y,*z=node,*p;
  y=z->right;
  if(z!=root)
    {
      p=z->parent;
      y->parent=p;
      if(p->left==z) p->left=y;
      else p->right=y;
    }
  else 
    {
      y->parent=0;
      root=y;
    }
  z->parent=y;
  if(y->left)
    {
      y->left->parent=z;
    
    }
  z->right=y->left;
  y->left=z;
 
}


void avl::insert(Employee_record &a)
{
  bst_node *current=root,*current_py,*p;
  p=new bst_node;int count=0;
  p->left=p->right=0;
  p->data.insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
  if(root==0)    
    {
      root=p;height++;
      root->parent=0;
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
	  //current=current->right
	}
      else 
	{
	  current->left=p;
	}
      p->parent=current;
      if(count+1>height) height=count+1;
  

  
      int bf=0;
      while(current)
	{
	 
	  
	  bf= balance_factor(current);
    
	  if(bf==2)  
	    {
	      bf=balance_factor(current->left);
	      if(bf==1) 
		{
		  right_rotation(current);
		  break;
		}
	      else if(bf==-1)
		{
		  left_rotation(current->left);
		  right_rotation(current);
		  break;
		}
	  
	    }
      
	  if(bf==-2)
	    {
	      bf=balance_factor(current->right);
	      if(bf==-1) 
		{
		  left_rotation(current);
		  break;
		}
	      else if(bf==1)
		{
		  right_rotation(current->right);
		  left_rotation(current);
		  break;
		}
	    }
	  current=current->parent;
	}
  
    }
}




void avl::delete_element(string id,Employee_record &a)
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
    //current->data.print_record();

   //verifying whether given key exists or not and doing further operation
    if(id.compare(current->data.get_employee_ID())==0)                          
      {
	p=current;
	a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);


	//--------------------------------------------------NODE HAS NO CHILD------------------------------------------------
	if(!current->left  &&!current->right)
	  {
	    if(current==root) root=0;
	    else
	      {
		if(current->data.get_employee_ID().compare(current->parent->data.get_employee_ID())>0)
		  current->parent->right=0;
		else 	current->parent->left =0; 
		p=current->parent;
		p->data.print_record();
		delete current;
	      }
	  }


	//---------------------------------------------NODE HAS TWO CHILDREN--------------------------------------------------

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
      }
	
	  
	//-------------------------------------//NODE HAS ONLY ONE CHILD---------------------------------------------------------------
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
		    p ->parent=current->parent;
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
	//---------------------------------------------BALANCING THE TREE -----------------------------------------------------------------
	int bf=0;
	while(p)
	  {
	    cout<<"1st step of avl"<<'\n';
	    
	    bf= balance_factor(p);
	    cout<<bf<<'\n';
	    if(bf==2)  
	      {
		bf=balance_factor(p->left);
		if(bf==1) 
		  {
		    right_rotation(p);
		    
		  }
		else if(bf==-1)
		  {
		    left_rotation(p->left);
		    right_rotation(p);
		  
		  }
		else  right_rotation(p);
		  
		
	      }
	
	    if(bf==-2)
	      {
		bf=balance_factor(p->right);
		if(bf==-1) 
		  {
		    left_rotation(p);
		 
		  }
		else if(bf==1)
		  {
		    right_rotation(p->right);
		    left_rotation(p);
		  }
		else left_rotation(p);
	      }
	    p=p->parent;
	  }
		traversal(4);
      
}    

void avl:: update_file(bst_node *node)
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



void avl::preordertraversal(bst_node *node)
{
  if(node==0) return;
  cout<<"Employee ID :"<<node->data.get_employee_ID()<<'\t';
  int bf=balance_factor(node);cout<<'\t'<<"Balance Factor :"<<bf<<'\n';
  preordertraversal(node->left);
  preordertraversal(node->right);
}


void avl::inordertraversal(bst_node *node)
{
  if(node==0) return;
  inordertraversal(node->left);
  cout<<"Employee ID :"<<node->data.get_employee_ID()<<'\t';
  int bf=balance_factor(node);cout<<'\t'<<"Balance Factor :"<<bf<<'\n';
  inordertraversal(node->right);
}


void avl::postordertraversal(bst_node *node)
{
  if(node==0) return;
  postordertraversal(node->left);
  postordertraversal(node->right);
  cout<<"Employee ID :"<<'\t'<<node->data.get_employee_ID()<<'\t';
  int bf=balance_factor(node);cout<<"Balance Factor :"<<bf<<'\n';
}






void avl::traversal(int a)
{
  if(a==1) preordertraversal(root);
  if(a==2) inordertraversal(root);
  if(a==3) postordertraversal(root);
  if(a==4) update_file(root); 
}



