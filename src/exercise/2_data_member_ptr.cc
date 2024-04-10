#include <iostream>

struct X
{
  int a;
  int b;
};

#define VALUE_OF_PTR(p)     (*(long*)&p)

int main()
{
  int X::*p = 0;
  std::cout << VALUE_OF_PTR(p) << std::endl;
  p = &X::a;
  std::cout << VALUE_OF_PTR(p) << std::endl;
  p = &X::b;
  std::cout << VALUE_OF_PTR(p) << std::endl;
  return 0;
}