#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include"Linear_probing.h"
//#include"hash_func.h"

using namespace std;

int hash_code1(std::string a)
{
  int x=37,i=0,len=0,c=0;
  
  while(a[i]) {len++;i++;}
  
  int b[len];
  for(i=0;i<len;i++)
    {
      b[i]=(int)a[i];
    }
  for(i=0;i<len;i++)
    {
      c=c*x+b[i];
    }
  
  return c;
}


int compression_map1(int k,int m)
{
  return k%m;
}


int doublehash_offset1(int k,int m)
{
  int subsize;
  if(m%2==0) subsize=m/2;
  subsize=(m+1)/2;
  int offset=subsize-k%subsize;
  return offset;
}

void LinearList::update_file()
{
	int index=0;std::string check="Unenrolled",check1="deleted";
	  std::ofstream fp("employee.txt",ios::trunc); 
	for( index=0;index<table_size;index++)
    {
      if((element[index].employee_ID).compare(check)!=0&&(element[index].employee_ID).compare(check1)!=0)
		{
			   
    	  fp<<element[index].employee_ID;
      	fp<<'\n';
      	fp<<element[index].Name;
      	 fp<<'\n';
      fp<<element[index].Email;
       fp<<'\n';
      fp<<element[index].Address;
       fp<<'\n';
      fp<<element[index].Position;
       fp<<'\n';
      fp<<element[index].salary;
       fp<<'\n';
      fp<<element[index].mobile_num;
      fp<<'\n';
      fp<<'\n';
     
		}
}
	 fp.close();
}

LinearList::LinearList(int MaxSize)
{ // Constructor for the sequential linear list
  element = new  Employee_record[MaxSize];  
  table_size=MaxSize;
  len = 0;
  string a ="Unenrolled";
  for(int i=0 ;i<MaxSize;i++)
    {
      element[i].employee_ID.assign(a);
    }
}


LinearList::LinearList(const LinearList& temp) 
{ // Copy constructor
	table_size=temp.table_size;
	element=new Employee_record[table_size];
	len=temp.len;
	memcpy(element, temp.element, table_size); 
}


 LinearList::~LinearList()
{ // Distructor for the sequential linear list
	 delete [] element;
}

bool  LinearList::isEmpty()
{ // Function that checks whether the list is empty
	 return   len == 0;}

int  LinearList::length()
{ // Function that returns the length of the list
	 return   len;
}




int  LinearList::search(string id)
{ // Search for x and return the position if found, else return 0.
  int k=hash_code1(id);
  int index=compression_map1(k,table_size);
  string check="Unenrolled",check1="deleted";
  int count=0;
  while((element[index].employee_ID).compare(id)!=0&&(element[index].employee_ID).compare(check)!=0)
    {
      index++;
      count++;
      index=index%table_size;
    }
  if(index==table_size||element[index].employee_ID.compare(check)==0||element[index].employee_ID.compare(check1)==0) return -1;
  return index;
}

void  LinearList::delete_element (string id,Employee_record &a)
{
  int k=hash_code1(id);
  int index=compression_map1(k,table_size);
  string check="Unenrolled";
  int count=0;
  while((element[index].employee_ID).compare(id)!=0&&count<table_size&&element[index].employee_ID.compare(check)!=0)
    {
      count++;
      index++;
      index=index%table_size;
    }
  if(count==table_size||element[index].employee_ID.compare(check)==0) 
    {
      cout<<"Unenrolled employee.Check id once" ;
      return;
    }
  a.insert(element[index].employee_ID,element[index].Name,element[index].Email,element[index].Address,element[index].Position,element[index].salary,element[index].mobile_num);
  check="deleted";
  //a.insert(element)
  element[index].employee_ID.assign(check);
  len = len-1; 

  update_file();
}


void LinearList::rehash()
{
 
  const int size=2*table_size;
  Employee_record *re_element=new Employee_record[size];
  string id,check="Unenrolled",check1="deleted";
  // Employee_record a;
  print();
  cout<<'\t'<<"REHASH"<<'\n';
  for(int i=0;i<size;i++)
    {
      re_element[i].employee_ID.assign(check);
    }
  for(int i=0;i<table_size;i++)
    {
      //  cout<<"for  1"<<'\t';
      id.assign( element[i].get_employee_ID());
      // cout<<"for  2"<<'\t';
      if(id.compare(check)==0||id.compare(check1)==0) continue;
      //  cout<<"for  3"<<'\t';
      int k=hash_code1(id);  
      // cout<<"for  4"<<'\t';
      int index=compression_map1(k,size);
      // cout<<"for  5"<<'\t';
      // cout<<index<<'\n';
      if((re_element[index].employee_ID).compare(check)==0) 
	{
	  re_element[index].insert(element[i].employee_ID,element[i].Name,element[i].Email,element[i].Address,element[i].Position,element[i].salary,element[i].mobile_num);
	  // len++; 
	  //cout<<index<<'\n';
	  re_element[index].print_record();
	}
      else
	{
	  int count=0;
	  while((re_element[index].employee_ID).compare(check)!=0&&count<size)
	    {
	      count++;
	      index++;
	      index=index%size;
	    }
	  re_element[index].insert(element[i].employee_ID,element[i].Name,element[i].Email,element[i].Address,element[i].Position,element[i].salary,element[i].mobile_num);
	  // len++;
	  //cout<<index<<"\t"<<count<<'\n';
	  re_element[index].print_record();
	}
    }
  // cout<<"end before   ";
  element=re_element;
  // cout<<"end";
  table_size=2*table_size;
  print();
}


void  LinearList::insert(Employee_record &a)
{ // Insert x after kth element. 
  if(len>=table_size) rehash();

  int k=hash_code1(a.get_employee_ID());  
  int index=compression_map1(k,table_size);
  //cout<<"insert"<<index<<'\t';
  string check="Unenrolled",check1="deleted";

  if((element[index].employee_ID).compare(check)==0||(element[index].employee_ID).compare(check1)==0) 
    {
      element[index].insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
     
      len++; 
     
     // cout<<"insert normal  "<<index<<"length  "<<len<<'\n';
      }
  else
    {
      int count=0;
      while((element[index].employee_ID).compare(check)!=0&&count<table_size)
	{
	  count++;
	  index++;
	  index=index%table_size;
	}
      element[index].insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
      len++;
     // cout<<"insert probing "<<index<<"\t"<<count<<'\n';
    }
  //return   *this;
}





void LinearList::print()
{
  int i=0;
  string check="Unenrolled",check1="deleted";
  for( i=0;i<table_size;i++)
    {
      if((element[i].employee_ID).compare(check)!=0&&(element[i].employee_ID).compare(check1)!=0)
	{
	  cout<<"Employee "<<i<<'\n';
	  element[i].print_record() ;
	  // cout<<'\n';
	}
    }
  cout<<"length of list"<<i<<'\n';
}

//*****************************************************************************************************************************************

