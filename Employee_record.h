//#include"Chain.h"
#include<iostream>
#include<string.h>

using namespace std;
//*****************************************************************************************************************************************
#ifndef EMPLOYEE_RECORD_H
#define EMPLOYEE_RECORD_H

//#include"Chain.h"

class Employee_record
{
friend class Chain;
friend class hashtable;
friend class LinearList;
friend class double_hash;
friend class bst;
friend class avl;
  
private:
  int salary;long int mobile_num;
  std::string  employee_ID;
  char Name[30],Email[30],Position[20],Address[50];
public:
  std::string get_employee_ID()
  {
    return employee_ID;
  }
  void print_record()
  {
    std::cout<<"employee_ID  :"<<employee_ID<<'\n';
    std::cout<<"Name  :"<<Name<<'\n';
    std::cout<<"Address  :"<<Address<<'\n';
    std::cout<<"Email  :"<<Email<<'\n';
    std::cout<<"Position  :"<<Position<<'\n';
    std::cout<<"Salary :"<<salary<<'\n';
    std::cout<<"mobile_num   :"<<mobile_num<<'\n';
  }
  void insert(std::string id,char name[],char email[],char position[],char address[],int Salary,long int Mobile_num)
  {
    employee_ID.assign(id);
    strcpy(Name,name);
    strcpy(Email,email);
    strcpy(Position,position);
    strcpy(Address,address);
    salary=Salary;
    mobile_num=Mobile_num;
  }
  /* void copy(const Employee_record &a)
  {
    b
    }*/
};


#endif
