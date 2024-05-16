#include <iostream>

class B
{
private:
  int a;
  int b;
public:
  B(/* args */) {}
  ~B() {}
  // virtual ~B() {}
};

 struct Base
 {
   virtual void doSomething(int i)  {
     std::cout << "This is from Base with " << i << std::endl;
   }
 };

struct Derivied : Base {
   virtual void doSomething(int i) override {
     std::cout << "This is from Derived with " << i << std::endl;
   }
 };

void letDoSomething(Base& base) {
   base.doSomething(419);
 }

int main()
{
  Derivied d;
  letDoSomething(d);  //输出结果： "This is from Base with 419"

  std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
}