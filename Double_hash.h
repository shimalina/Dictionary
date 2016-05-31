

#include<string.h>
#include<string>
#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include"Employee_record.h"


class double_hash
{

 
private: 
 Employee_record *element;    // 1D dynamic array
  int len;
  int table_size;
  
public:
double_hash(int  MaxSize);
  double_hash(const double_hash& temp);
  ~double_hash();
  bool  isEmpty();
  int  length();
  int  search(string id);
  void  delete_element(string id,Employee_record &a);
  void  insert(Employee_record  &a);
  void print();
  void rehash();
	void update_file();

};

#endif
