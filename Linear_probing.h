#include<string.h>
#include<string>
#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include"Employee_record.h"

class LinearList{
private: 
  Employee_record *element;    // 1D dynamic array
  int len;
  int table_size;
public:
  LinearList(int  MaxSize);
  LinearList(const LinearList& temp);
  ~LinearList();
  bool  isEmpty();
  int  length();
  int  search(std::string id);
  void  delete_element(std::string id,Employee_record &a);
  void  insert(Employee_record  &a);
  void print();
  void rehash();
	void update_file();
};

#endif
