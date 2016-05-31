
#include<string.h>
#include<string>
#ifndef CHAIN_H
#define CHAIN_H


#include"Employee_record.h"
#include"Chain_Node.h"

//class ChainNode;
//class Employee_record;
class Chain{
private:
  ChainNode  *first;
  ChainNode  *last;
  int len=0;


  public: 
Chain(void);
  Chain(const Chain& temp);
  ~Chain(void);
  void insert(Employee_record &a);
  void delete_element(int k,Employee_record &a);
  void print();
  void append(Chain* x);
  bool empty();
  int  length();
  // int  find(int  k, int  &x);
  int  search(std::string  id);
  void find(int k,Employee_record &a);
	void update_file(int i);
};






//*************************************************CHAIN CLASS FUNCTIONS DEFINITION*********************************************************



#endif


