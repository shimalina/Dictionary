#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include"Double_hash.h"
//#include"hash_func.h"

using namespace std;

int hash_code2(std::string a)
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


int compression_map2(int k,int m)
{
  return k%m;
}


int doublehash_offset2(int k,int m)
{
  int subsize;
  if(m%2==0) subsize=m/2;
  subsize=(m+1)/2;
  int offset=subsize-k%subsize;
  return offset;
}



void double_hash::update_file()
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



double_hash::double_hash(int  MaxSize)
{
  element = new  Employee_record[MaxSize];  
  table_size=MaxSize;
  len = 0;
  string a ="Unenrolled";
  for(int i=0 ;i<MaxSize;i++)
    {
      element[i].employee_ID.assign(a);
    }
}
double_hash::double_hash(const double_hash& temp)
{
  // Copy constructor
	table_size=temp.table_size;
	element=new Employee_record[table_size];
	len=temp.len;
	//table_size=temp.table_size;
	memcpy(element, temp.element, table_size);
}
double_hash::~double_hash()
{
  delete [] element;
}


bool double_hash::isEmpty()
{ // Function that checks whether the list is empty
	 return   len == 0;}

int  double_hash::length()
{ // Function that returns the length of the list
	 return   len;
}


void double_hash::rehash()
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
      id.assign( element[i].get_employee_ID());
      if(id.compare(check)==0||id.compare(check1)==0) continue;
      int k=hash_code2(id);  
      int index=compression_map2(k,size);
      
      if((re_element[index].employee_ID).compare(check)==0) 
	{
	  re_element[index].insert(element[i].employee_ID,element[i].Name,element[i].Email,element[i].Address,element[i].Position,element[i].salary,element[i].mobile_num);
	  
	  re_element[index].print_record();
	}
      else
	{
	  int count=0;
	  while((re_element[index].employee_ID).compare(check)!=0&&count<size)
	    {
	      count++;
	    index+=doublehash_offset2(index,size);
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
  // print();
}



void double_hash::insert(Employee_record &a)
{ 
  if(len>=table_size) rehash();
  int k=hash_code2(a.get_employee_ID());
 
  int index=compression_map2(k,table_size);
 
  string check="Unenrolled",check1="deleted";
  if((element[index].employee_ID).compare(check)==0&&(element[index].employee_ID).compare(check1)==0) 
    {
      element[index].insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
     
      len++; 
      
       cout<<index<<'\n';
    }
  else
    {
      int count=0,size=table_size;
      while((element[index].employee_ID).compare(check)!=0&&count<table_size)
	{
	  count++;
	  index+=doublehash_offset2(index,size);
	  index=index%table_size;
	}
      element[index].insert(a.employee_ID,a.Name,a.Email,a.Address,a.Position,a.salary,a.mobile_num);
      len++;
       cout<<index<<"\t"<<count<<'\n';
    }
  // return   *this;
}







int  double_hash::search(string id)
{
   int k=hash_code2(id);
  int index=compression_map2(k,table_size);
  string check="Unenrolled",check1="deleted";
  int count=0,size=table_size;
  while((element[index].employee_ID).compare(id)!=0&&(element[index].employee_ID).compare(check)!=0)
    {
     // index++;
      count++;
      index+=doublehash_offset2(index,size);
      index=index%table_size;
    }
  if(index==table_size||element[index].employee_ID.compare(check)==0&&(element[index].employee_ID).compare(check1)==0) return -1;
  return index;
}

void double_hash:: delete_element(string id,Employee_record &a)
{
   int k=hash_code2(id);
  int index=compression_map2(k,table_size);
  string check="Unenrolled";
  int count=0,size=table_size;
  while((element[index].employee_ID).compare(id)!=0&&count<table_size&&element[index].employee_ID.compare(check)!=0)
    {
      count++;
      index+=doublehash_offset2(index,size);
      index=index%table_size;
    }
  if(count==table_size||element[index].employee_ID.compare(check)==0) 
    {
      cout<<"Unenrolled employee.Check id once" ;
      return;
    }
 a.insert(element[index].employee_ID,element[index].Name,element[index].Email,element[index].Address,element[index].Position,element[index].salary,element[index].mobile_num);
  check="deleted";
  element[index].employee_ID.assign(check);
  len = len-1; 
	update_file();
}


void double_hash::print()
{
  int i=0;
  string check="Unenrolled",check1="deleted";
  for( i=0;i<table_size;i++)
    {
      if((element[i].employee_ID).compare(check)!=0&&element[i].employee_ID.compare(check1)!=0)
	{
	  cout<<"Employee "<<i<<'\n';
	  element[i].print_record() ;
	  // cout<<'\n';
	}
    }
  cout<<"length of list"<<i<<'\n';
}



