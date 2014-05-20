#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

int main(){
  myString hello("hello");
  myString hello2("hello");
  if(hello==hello2){
    cout<<"good"<<endl;
  }
  string my="how are you";
  myString world("world");
  if(hello!=world){
    cout<<"good"<<endl;
  }
  if(!(hello!="hello")){
    cout<<"good"<<endl;
  }
  myString helloworld;
  cout<<hello.Size()<<endl;
  helloworld=hello+world;
  helloworld.print();
  helloworld="mygod";
  helloworld.print();
  helloworld=helloworld;
  helloworld.print();
  cout<<hello.Compare(world)<<endl;
  cout<<hello.Compare("hello")<<endl;
  return 0;
}
