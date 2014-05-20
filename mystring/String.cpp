#include <iostream>
#include <cstring>
#include "mystring.h"
#include "utility.h"
using namespace std;

myString::myString(){
  this->length=0;
  this->ptr=NULL;
}
myString::myString(char *str){
  int len,i;
  if(str==NULL){
    allocaStr(1,this->ptr);
    this->ptr[0]='\0';
    this->setSize(0);
  }
  else{
    len=strlen(str);
    allocaStr(len+1,this->ptr);
    for(i=0;i<len;i++){
      this->ptr[i]=str[i];
    }
    this->ptr[len]='\0';
    this->setSize(len);
  }
}
void myString::print(){
  if(this->Size()) cout<<this->ptr<<endl;
}
int myString::Size()const{
  return this->length;
}
void myString::setSize(int len){
  if(len>0){
    this->length=len;
  }
}
myString::myString(const myString &other){
  ptr=new char[other.Size()+1];
  strcpy(ptr,other.ptr);
  this->setSize(other.Size());
}
  /* tips: operator + overloaded must return new instance
    can't return reference;

  */
myString myString::operator+(const myString &right){
  int i,len;
  char *str;
  allocaStr(this->Size()+right.Size()+1,str);
  strncpy(str,this->ptr,this->Size());
  strncpy(str+this->Size(),right.ptr,right.Size());
  str[this->Size()+right.Size()]='\0';;
  return myString(str);
}
myString& myString::operator=(const myString &right){
  if(&right==this){
    return (*this);
  }
  delete this->ptr;
  allocaStr(right.Size()+1,this->ptr);
  strcpy(this->ptr,right.ptr);
  this->setSize(right.Size());
  return (*this);
}
void myString::allocaStr(const int len,char *&str)const{
  str=new char[len];
}
myString::~myString(){
  delete this->ptr;
}
bool myString::operator==(const myString& right){
  if(this==&right){
    return true;
  }
  else{
    if(!strcmp(this->ptr,right.ptr)){
      return true;
    }
    else{
      return false;
    }
  }
}
bool myString::operator!=(const myString& right){
  if(!strcmp(this->ptr,right.ptr)){
    return false;
  }
  else{
    return true;
  }
}
bool myString::operator==(const char *right){
  if(right!=NULL){
    if(!strcmp(this->ptr,right)){
      return true;
    }
    else{
      return false;
    }
  }
}
bool myString::operator!=(const char *right){
  if(right!=NULL){
    if(!strcmp(this->ptr,right)){
      return false;
    }
    else{
      return true;
    }
  }
}
int myString::Compare(const char *right){
  int len,i,maxLen,minLen;
  if(right==NULL){
    if(this->Size()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    len=strlen(right);
    minLen=minVal(len,this->Size());
    maxLen=maxVal(len,this->Size());
    for(i=0;i<minLen;i++){
      if(this->ptr[i]<right[i]) return -1;
      else{
        if(this->ptr[i]>right[i]) return 1;
      }
    }
    if(minLen==maxLen){
      return 0;
    }
    else{
      if(minLen==len){
        return 1;
      }
      else{
        return 0;
      }
    }
  }
}
int myString::Compare(const myString &right){
  if(&right==this){
    return true;
  }
  else{
    return this->Compare(right.ptr);
  }
}

