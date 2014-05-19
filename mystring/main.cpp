#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

int main(){
  myString hello("hello");
  myString world("world");
  myString helloworld;
  cout<<hello.Size()<<endl;
  helloworld=hello+world;
  helloworld.print();
  helloworld="mygod";
  helloworld.print();
  helloworld=helloworld;
  helloworld.print();
  return 0;
}
