/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/*
>>>>>>>>>> Advanced Data Structure And Algorithms <<<<<<<<<<<<<<<
>>>>>>>>>>                                        <<<<<<<<<<<<<<<
>>>>>>>>>>                                        <<<<<<<<<<<<<<<
>>>>>>>>>> 	    Priyanka Mahawar              <<<<<<<<<<<<<<<
>>>>>>>>>>               B13131                   <<<<<<<<<<<<<<<
		    Assignment -> 3,4          

*/
/* File -> employee2.txt */
        /* Linear Probing , Chaining , Double hashing, Binary Search Tree, AVL tree */


#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include"Chain.h"

using namespace std;


Chain::Chain(void)
{ // Constructor for the linked linear list
	 first = NULL;
	 last=NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------

Chain::Chain(const Chain &temp)
{
  if(temp.last==0) first=last=0;
  ChainNode *p1=0,*p2=0;
  first=new ChainNode;
  memcpy(&(first->data),&(temp.first->data),sizeof(Employee_record));
  
  p1=first;
  p2=temp.first->link;

  while(p2)
    {
      p1->link=new ChainNode;
      p1=p1->link;
      p1->data=p2->data;
      p2=p2->link;
    }
  last=p1;
  p1->link=0;
  len=temp.len;
}

//------------------------------------------------------------------------------------------------------------------------------------------

Chain::~Chain(void)
{ // Distructor for the linked linear list. Delete all the nodes in chain
	 ChainNode *next;  // Next node
	 while(first){
			next = first -> link;
			delete  first;
			first = next;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------

void Chain::insert(Employee_record &a)
{ // Insert x after kth element.

   ChainNode *p =new ChainNode;
  
   p->data.insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
   len++;
   // cout<<"hhjv"<<'\n';
  if(last==NULL) 
    {
      p->link=last;
      last=p;
      first=p;
      // last->link=NULL;
      return;
      //  return *this;
    }
  // cout<<"hhjv"<<'\n';
  
  // memcpy(&(first->data),&a,sizeof(Employee_record));
  last->link=p;
  last=last->link;
  p->link=NULL;
  // cout<<len<<"   Insert of Chain"<<'\n';
}

//------------------------------------------------------------------------------------------------------------------------------------------

void Chain::print()
{
  ChainNode *current=first;
  int i=1;
  while(current)
    {
      cout<<"Employee "<<i<<'\n';
      current->data.print_record(); 
      current=current->link;
      i++;
    }
 
}



void Chain::update_file(int i)
{
	ChainNode *node=first;
 
	if(i==0) 
	{
	std::ofstream fp("employee.txt",ios::trunc); 
	
	while(node)
    	{
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
	node=node->link;
	}		
	fp.close();
	}

	else 
	{
	std::ofstream fp("employee.txt",ios::app); 
		while(node)
    	{
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
	node=node->link;
	}		
	fp.close();
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------

void Chain::append(Chain* x)
{
  if(x->first)
    {
      // std::cout<<"hello\n";
   last->link=x->first;
   last=x->last;}
}

//------------------------------------------------------------------------------------------------------------------------------------------

bool Chain::empty()
{
  if(first)
    return false;
  else
    return true;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int Chain::length()
 {
   return len;
   /* ChainNode *current=first;
     int i=0;
     while(current)
       {
	  i++;
	 current=current->link;
	 }*/
     
 }

//------------------------------------------------------------------------------------------------------------------------------------------

/*int  Chain::find(string  id)
{
 if (k < 1)   return   false;

 ChainNode  *current = first;
 for (int  i = 1; i < k; i++)
   {
     current = current -> link;
   }
 a= current -> data;
 return   true;
 }*/

//-----------------------------------------------------------------------------------------------------------------------------------------

int  Chain::search(string id)
{
  ChainNode  *current = first; 
  int  index = 1;
  while  (current  && id.compare(current->data.employee_ID)!=0)
    {
      current = current -> link;
      index++;
    }
  if  (current)
    {
      // current->data.print_record();	
      return   index;
    }
  return  -1;
  }


//-----------------------------------------------------------------------------------------------------------------------------------------

void Chain::delete_element( int  k, Employee_record  &a)
{
  ChainNode  *current = first;
  for (int  i=1;  i < k-1;  i++)
    {
      current = current -> link;
    }
  ChainNode  *p =current;
 
  if(k==1)
    {
      cout<<"here"<<'\n';
      first=current->link;
      a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);
      delete current;
      cout<<"next to here"<<'\n';
      return;
    }
  p = current->link ;
  a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);
  current->link=p->link;
  delete p;
 
  len--;
  // cout<<len<<'\n';
}


void Chain::find(int k,Employee_record &a)
{
  ChainNode  *p = first; 
  int  i = 1;
  while  (p  && i<k)
    {
      p = p -> link;
      i++;
    }
  if  (p)
    {	
      a.insert(p->data.employee_ID,p->data.Name,p->data.Email,p->data.Address,p->data.Position,p->data.salary,p->data.mobile_num);
    }  
}





