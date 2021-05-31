#include<iostream>
using namespace std;
#include "templates.cpp"
int main(){
  triplet<int,float,char> r;
  r.getx(10);
  r.gety(10.2);
  r.getz('a');
  cout<<r.valueofx()<<endl;
  cout<<r.valueofy()<<endl;
  cout<<r.valueofz()<<endl;
  cout<<"hello akhil"<<endl;
  return 0;
}
