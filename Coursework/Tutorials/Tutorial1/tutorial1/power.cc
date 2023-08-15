#include <iostream>

using namespace std;


void power(int a, int b, int &c){
  int total = a;
  if(b == 1){
    c = 1;
    return;
  }
  for(int x = 1; x < b; ++x){
    total = total*a;
  }
  c = total;
}
