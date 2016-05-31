#include<string.h>


#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"Employee_record.h"
#include"Chain.h"
class Employee_record;

class hashtable
{
private:
  Chain *bucket;
  bool collision;
  int load_factor;
  int table_size;
public:
 hashtable(int size);
  ~hashtable();
  hashtable(const hashtable &temp);
  void insert(Employee_record &a);
  void delete_element(std::string id,Employee_record &a);
  int search(std::string id);
  int isempty();
  int length();
  void print();
	void update_file();
  void rehash();
};


//********************************************CLASS HASHTABLE FUNCTIONS DEFINITION**********************************************************
/*
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
     
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------

void hashtable::insert(Employee_record &a)
{
  // cout<<"1"<<'\n';
  string id=a.get_employee_ID(); 
  //cout<<id<<'\n';
  int key= hash_code(id);
  //cout<<'2'<<'\n';
  int index=compression_map(key,table_size);
  //cout<<"HASH INSERT"<<key<<" "<<index<<'\n';
  bucket[index].insert(a);
}

int hashtable::search(string id)
{
   int key= hash_code(id);
   int index=compression_map(key,table_size);
   int c= bucket[index].search(id);
   return c;
}

void hashtable::delete_employee(string id,Employee_record &a)
{
  int key= hash_code(id);
  int index=compression_map(key,table_size);
  int c= bucket[index].search(id);
  if(c==0) 
    {
      cout<<"Unkown employee_id.Check the id once";
      return;
    }
  // cout<<"Search over "<<c<<'\n';
  // cout<<bucket[index].length()<<'\n';
  bucket[index].delete_element(c,a);
}
//-----------------------------------------------------------------------------------------------------------------------------------------

void hashtable::print()
{
  for(int i=0;i<table_size;i++)
    {
      bucket[i].print();
    }
}*/


#endif




