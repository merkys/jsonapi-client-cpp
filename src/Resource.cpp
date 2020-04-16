#include<iostream>
#include<cstring>
#include"Resource.h"


 Resource::Resource(const std::string attribute_name,const std::string value):
	attribute_name_(attribute_name), value_(value){
   #ifdef DEBUG
	std::cout <<"Constuctor is working..."<<std::endl;
   #endif
  }

 std::string Resource::get_attribute(const std::string attribute_name){
	return attribute_name_;
  };

 std::string Resource::set_attribute(const std::string attribute_name,const std::string value){
	this->attribute_name_ = attribute_name;
	this->value_ = value;
  };

 Resource::~Resource(){
   #ifdef DEBUG
	std::cout<<"Destructor is working..."<<std::endl;
   #endif
  }
