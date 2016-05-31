
#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include"hashtable.h"
//#include"hash_func.h"

using namespace std;


int hash_code(std::string a)
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


int compression_map(int k,int m)
{
  return k%m;
}


int doublehash_offset(int k,int m)
{
  int subsize;
  if(m%2==0) subsize=m/2;
  subsize=(m+1)/2;
  int offset=subsize-k%subsize;
  return offset;
}




hashtable::hashtable(int size)
{
  bucket = (Chain *)malloc(size*sizeof(Chain));
  for(int i=0;i<size;i++)
    {
      Chain bucket[i];
    }
  table_size=size;
  collision=false;
  load_factor=0;
}

//------------------------------------------------------------------------------------------------------------------------------------------
hashtable::~hashtable()
{
  ChainNode *next,*p;
  for(int i=0;i<table_size;i++)
    {
      // p=bucket[i]->first;
      bucket[i].~Chain();
      /*while(p)
	{
	  next=p->link;
	  delete current;
	  p=next;
	  }*/
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void hashtable::rehash()
{
  cout<<'\t'<<"REHASH"<<'\n';
  int len=0,key,index;Employee_record a;
  Chain *re_bucket=new Chain[2*table_size];
  for(int i=0;i<table_size;i++)
    {
      cout<<"before length"<<'\n';
      len=bucket[i].length();
      cout<<"after length"<<'\n';
      if(bucket[i].empty()==0) continue;
      
      for(int j=0;j<len;j++)
	{
	  cout<<"2nd for start"<<'\n';
	  bucket[i].find(1,a);
	  cout<<"2nd for middle"<<'\n';
	  key= hash_code(a.get_employee_ID());
	  index=compression_map(key,2*table_size); 
	  cout<<"2nd for end before"<<'\n';
	  re_bucket[index].insert(a);
	  cout<<"2nd for end"<<'\n';
	}
    }
  bucket=re_bucket;
  table_size=2*table_size;
  cout<<'\t'<<"REHASH END"<<'\n';
}



//-----------------------------------------------------------------------------------------------------------------------------------------
void hashtable::insert(Employee_record &a)
{
  // cout<<"1"<<'\n';
  std::string id=a.get_employee_ID(); 
  //cout<<id<<'\n';
  int key= hash_code(id);
  //cout<<'2'<<'\n';
  int index=compression_map(key,table_size);
  //cout<<"HASH INSERT"<<key<<" "<<index<<'\n';
  int len=bucket[index].length();
  if(len/table_size>=0.5) rehash();
  bucket[index].insert(a);
}

int hashtable::search(std::string id)
{
   int key= hash_code(id);
   int index=compression_map(key,table_size);
   int c= bucket[index].search(id);
   return c;
}

void hashtable::delete_element(std::string id,Employee_record &a)
{
  int key= hash_code(id);
  int index=compression_map(key,table_size);
  int c= bucket[index].search(id);
  if(c==0) 
    {
      std::cout<<"Unkown employee_id.Check the id once";
      return;
    }
  // cout<<"Search over "<<c<<'\n';
  // cout<<bucket[index].length()<<'\n';
  bucket[index].delete_element(c,a);
	update_file();
}
//-----------------------------------------------------------------------------------------------------------------------------------------

void hashtable::print()
{
  for(int i=0;i<table_size;i++)
    {
      bucket[i].print();
    }
}

void hashtable::update_file()
{
	for(int i=0;i<table_size;i++)
    {
      bucket[i].update_file(i);
    }
}


