#include <iostream>

// 多继承
class Base1
{
public:
  int base1_1;
  int base1_2;

  virtual void base1_fun1() {}
  virtual void base1_fun2() {}
};

class Base2
{
public:
  int base2_1;
  int base2_2;

  virtual void base2_fun1() {}
  virtual void base2_fun2() {}
};

class Derived : public Base1, public Base2
{
public:
  int derived_1;
  int derived_2;

  virtual void base1_fun1() {}
  virtual void base2_fun1() {}

  //自定义虚函数
  virtual void derived_fun1() {}
  virtual void derived_fun2() {}
};

int main()
{
  std::cout << "sizeof(Base1)   = " << sizeof(Base1) << std::endl;
  std::cout << "sizeof(Base2)   = " << sizeof(Base2) << std::endl;
  std::cout << "sizeof(Derived) = " << sizeof(Derived) << std::endl;
  std::cout << "offsetof(Derived, derived_1) = " << offsetof(Derived, derived_1) << std::endl;
  std::cout << "offsetof(Derived, derived_2) = " << offsetof(Derived, derived_2) << std::endl;

  Derived d1;
  Derived* pd1 = &d1;
  pd1->derived_fun1();
}