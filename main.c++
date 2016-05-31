#include <iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include"Chain.h"
#include"hashtable.h"
#include"Employee_record.h"
#include"Linear_probing.h"
#include"Double_hash.h"
#include"avl.h"


using namespace std;



 main()
 {

   int i=0,c=1,choice=0;
  Employee_record a,b;
  string id="a123",id1="a546";

  char name[]="Toyaz Sai Madhav",email[]="ktsmadhav@gmail.com",address[]="501",position[]="Student";

  int salary=3000000;long int mobileno=9816923879;
  

  a.insert(id,name,email,address,position,salary,mobileno);
  b.insert(id1,name,email,address,position,salary,mobileno);
  /*hashtable h(11);
  h.insert(a);h.insert(b);h.print();
  LinearList h1(11);
  h1.insert(a);h1.insert(b);h1.print();
  double_hash h2(11);
  h2.insert(a);h2.insert(b);h2.print();*/

//*****************************************************************************************************************************************
  cout<<"Enter your choice of dictionary implementation "<<'\n'<<"[1] Hashing "<<'\n'<<"[2] Binary Search tree"<<'\n'<<"[3] AVL Tree"<<'\n';
  cin>>choice;
	
//*****************************************************************************************************************************************
  int size , maxsize;
  if(choice==1)
    {
 

  cout<<"Enter the max size of hash table"<<'\n';
  cin>>maxsize;
    }
  
   cout<<"Enter the  no. of employees to be registered"<<'\n';
   cin>>size;
   if(choice==1)
     {
   cout<<"Enter your choice of collison resolution "<<'\n'<<"[1] Chaining" <<'\n'<<"[2] Linear Probing"<<'\n'<<"[3] Double hashing"<<'\n';
   cout<<"By Default chaining is used"<<'\n';
   cin>>c;
     }
   hashtable h1(maxsize);
   LinearList h2(maxsize);
   double_hash h3(maxsize); 
   bst bT;avl T;
     
    ofstream fp("employee.txt",ios::app);
   cout<<"enter the  details of all employee one by one"<<'\n';
   for(i=0;i<size;i++)
     {
      
       cout<<"Enter the employee id"<<'\t';
       cin>>id;
       fp<<id;
       fp<<'\n';
       cout<<"Enter the name"<<'\t';
       cin>>name;
       fp<<name;
       fp<<'\n';

       cout<<"Enter the email"<<'\t';
       cin>>email;
       fp<<email;
       fp<<'\n';
       
       cout<<"Enter the address"<<'\t';
       cin>>address;
       fp<<address;
       fp<<'\n';
       
       cout<<"Enter the position"<<'\t';
       cin>> position;
       fp<< position;
       fp<<'\n';
       
       cout<<"Enter the salary"<<'\t';
       cin>>salary;
       fp<<salary;
       fp<<'\n';

       cout<<"Enter the mobile_no"<<'\t';
       cin>>mobileno;
       fp<<mobileno;
       fp<<'\n';
       fp<<'\n';

     }
   fp.close();

   ifstream fp1; 
   fp1.open("employee.txt",ios::app);

   if(choice==2) c=4;
   else if(choice==3) c=5;
   
    
   char ch='n';int check=0,search;
   
   for(i=0;i<size;i++)
     {
       while(fp1>>id>>name>>email>>address>>position>>salary>>mobileno)
	 {
	   a.insert(id,name,email,address,position,salary,mobileno);
	   if(c==1)   h1.insert(a);
	   else if(c==2)   h2.insert(a);
	   
	   else if(c==3)   h3.insert(a);
	   else if(c==4)   bT.insert(a);
	   else if(c==5)   T.insert(a);
	   // cout<<"next"<<'\n';
	   // fp1>>ch;
	 }
     }
   fp1.close();

   cout<<'\t'<<'\t'<<"  Your DICTIONARY is shown below"<<'\n';
        if(c==1)   h1.print();
        else if(c==2)   h2.print();
	else if(c==3)   h3.print();
	else if(c==4) 
	  {
	    cout<<"Choose traversal"<<'\n'<<"[1] Preorder"<<'\n'<<"[2] Inorder"<<'\n'<<"[3] Postorder"<<'\n';
	    cin>>i;
	    bT.traversal(i);
	  }
	else if(c==5)  
	  {
	    cout<<"Choose traversal"<<'\n'<<"[1] Preorder"<<'\n'<<"[2] Inorder"<<'\n'<<"[3] Postorder"<<'\n';
	    cin>>i;
	    T.traversal(i);
	  }
       while(1)
	 {
	   cout<<"Want to perform further operations [y/n]"<<'\n';
	   cin>>ch;
	   if(ch=='y')
	     {
	       cout<<"Enter"<<'\n'<<" [1] for Searching"<<'\n'<<" [2] for Deleting"<<'\n' <<"[3] for Adding"<<'\n'<<"[4] for Display"<<'\n';
	       cin>>check;
	       if(check==1)
		 {
		   cout<<"Enter Employee id to be searched"<<'\n';
		   cin>>id;
		   if(c==1)  search=h1.search(id);
		   else if(c==2)  search=h2.search(id);
		   else if(c==3)  search=h3.search(id);
		   else if(c==4)  search=bT.search(id);
		   else if(c==5) search =T.search(id);
		   if(search==-1) cout<<"Unsucessfull search.Employee not found"<<'\n';
		   else cout<<"Successfull search. Position/Level is "<<search<<'\n';
		 }
	       if(check==2)
		 {
		   //int ab=0;
		   cout<<"Enter Employee id to be deleted"<<'\n';
		   cin>>id;
		   if(c==1)  search=h1.search(id);
		   else if(c==2)  search=h2.search(id);
		   else if(c==3)  search=h3.search(id);
		   else if(c==4)  search=bT.search(id);
		   else if(c==5) search =T.search(id);
	       
		   if(search==-1) cout<<"Unkown Employee.Please check id once."<<'\n';
		   else 
		     {
		       if(c==1)    h1.delete_element(id,a);
		       else if(c==2)    h2.delete_element(id,a);
		       else if(c==3)    h3.delete_element(id,a);
		       else if(c==4)  bT.delete_element(id,a);
		       else if(c==5) T.delete_element(id,a);
		       cout<<"Deleted employee details are given below"<<'\n';
		       a.print_record();
		     }
		 }
	        if(check==3)
		  {
		    ofstream fp2("employee.txt",ios::app);
		    cout<<"Enter the details of employee to be added"<<'\n';
		     cout<<"Enter the employee id"<<'\t';
		     cin>>id;
		     fp2<<id;
		     fp2<<'\n';
		     cout<<"Enter the name"<<'\t';
		     cin>>name;
		     fp2<<name;
		     fp2<<'\n';
		     
		     cout<<"Enter the email"<<'\t';
		     cin>>email;
		     fp2<<email;
		     fp2<<'\n';
		     
		     cout<<"Enter the address"<<'\t';
		     cin>>address;
		     fp<<address;
		     fp<<'\n';
       
		     cout<<"Enter the position"<<'\t';
		     cin>> position;
		     fp2<< position;
		     fp2<<'\n';
       
		     cout<<"Enter the salary"<<'\t';
		     cin>>salary;
		     fp2<<salary;
		     fp2<<'\n';
		     
		     cout<<"Enter the mobile_no"<<'\t';
		     cin>>mobileno;
		     fp2<<mobileno;
		     fp2<<'\n';
		     fp2<<'\n';
		     
		     fp2.close();
		     
		     a.insert(id,name,email,address,position,salary,mobileno);
		     if(c==1)   h1.insert(a);
		     else if(c==2)   h2.insert(a);
		     else if(c==3)   h3.insert(a);
		     else if(c==4)   bT.insert(a);
		     else if(c==5)   T.insert(a);
		  }
		 if(check==4)
		   {
		     if(c==1)   h1.print();
		     else if(c==2)   h2.print();
		     else if(c==3)   h3.print();
		     else if(c==4) 
		       {
			 cout<<"Choose traversal"<<'\n'<<"[1] Preorder"<<'\n'<<"[2] Inorder"<<'\n'<<"[3] Postorder"<<'\n';
			 cin>>i;
			 bT.traversal(i);
		       }
		     else if(c==5)  
		       {
			 cout<<"Choose traversal"<<'\n'<<"[1] Preorder"<<'\n'<<"[2] Inorder"<<'\n'<<"[3] Postorder"<<'\n';
			 cin>>i;
			 T.traversal(i);
		       }
		   }
		 
	     }
	   else break; 
	 } 
      
 }
/* if(choice==2||choice==3)
    {
      bst T;avl T1;
      for(i=0;i<size;i++)
     {
       while(fp1>>id>>name>>email>>address>>position>>salary>>mobileno)
	 {
	   a.insert(id,name,email,address,position,salary,mobileno);
	   if(choice==2)   T.insert(a);
	   else if(choice==3)   T1.insert(a);
	   
	 }
     }
      
     }*/



