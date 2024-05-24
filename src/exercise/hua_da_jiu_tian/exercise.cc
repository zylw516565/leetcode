#include <iostream>

//带虚函数的类大小
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

//override 关键字的作用
//*********************************************
struct Base
{
   virtual void doSomething(int i)
   {
     std::cout << "This is from Base with " << i << std::endl;
   }
};

struct Derivied : Base
{
   virtual void doSomething(int i) override
   {
     std::cout << "This is from Derived with " << i << std::endl;
   }
};

void letDoSomething(Base& base) {
   base.doSomething(419);
}

//final 关键字的作用
//*********************************************
struct Base4
{
virtual void doSomething(int i)
   {
     std::cout << "This is from Base with " << i << std::endl;
   }

private:
   virtual int dontChangeMe() const {return 3;}
};

struct ChildOfBase4 : public Base4
{
virtual void doSomething(int i) override
   {
     std::cout << "This is from Derived with " << i << std::endl;
   }

private:
   int dontChangeMe() const override { return 419; }
};

class BadChildOfChild : public ChildOfBase4 {
  public:
   int dontChangeMe() const override { return 61; }
 };

// struct ChildOfBase4Final : public Base4
// {
// private:
//    int dontChangeMe() const final { return 419; }
// };

// class BadChildOfChildFinal : public ChildOfBase4Final {
//   public:
//    int dontChangeMe() const override { return 61; }  //ERROR
// };

 class DontDeriveFromMe final {
   // ...
 };

//错误: 不能继承final修饰的类
//error: cannot derive from 'final' base 'DontDeriveFromMe
//  class Failure : public DontDeriveFromMe { //ERROR
//    // ...
//  };


//访问控制 //protected
//*********************************************
class Base2
{
public:
  Base2(/* args */) {}
  ~Base2() {}

protected:
  int age_ = 0;
private:
  int time_ = 0;
};

class Derivied2 : Base2
{
public:
  Derivied2(/* args */) {}
  ~Derivied2() {}

  int getAge() {return age_;}
  // int getTime() {return time_;}

  friend void clobber(Derivied2&);
  // friend void clobber(Base2&);
private:
  int j;
};

void clobber(Derivied2& d) { d.j = d.age_ = 0;}
// void clobber(Base2& b) { b.age_ = 0;}

//公有, 保护, 私有继承
//*********************************************
class Base3
{
public:
  int pub_mem(){}
protected:
  int prot_mem(){}
private:
  int priv_mem(){}
};

struct Pub_Derv :public Base3
{
  int f() {return pub_mem();}
  // 错误: private成员对派生类是不可访问的
  // int g() {return priv_mem();}
};

struct Prot_Derv :protected Base3
{
};

struct Priv_Derv :private Base3
{
  //private 不影响派生类的访问权限
  int f() {return pub_mem();}
};

//类中的const成员都有哪些初始化方式?
//*********************************************
class Test
{
private:
  const int age_ = 1;
  const int b;
public:
  Test(/* args */)
  :age_(2),
  b(3)
  {
    // age_ = 3; //错误
  }
  ~Test() {}

  int getAge() {return age_;}
};

//类中可以定义引用类型成员么?
//*********************************************
int g = 3;
class Test2
{
private:
  int& a = b;
  int b;
  int& c;
public:
  Test2(/* args */)
  :c(g)
  {}
  ~Test2() {}
};

int main()
{
  std::cout << "sizeof(B) = " << sizeof(B) << std::endl;

  Derivied d;
  letDoSomething(d);  //输出结果： "This is from Base with 419"

  //final 关键字的作用
  //*********************************************
  BadChildOfChild badchildofchild;
  std::cout << "badchildofchild.dontChangeMe() = " << badchildofchild.dontChangeMe() << std::endl;
  //访问控制
  Base2 base2;
  // std::cout << base2.age_ << std::endl;
  Derivied2 derivied2;
  std::cout << derivied2.getAge() << std::endl;


  //公有, 保护, 私有继承
  //*********************************************
  Pub_Derv pub;
  pub.pub_mem();
  // Prot_Derv prot;
  // prot.pub_mem(); //错误: pub_mem在派生类中是protected的
  // Priv_Derv priv;
  // priv.pub_mem(); //错误: pub_mem在派生类中是private的

  //类中的const成员都有哪些初始化方式?
  //*********************************************
  Test test;
  std::cout << "test.getAge() = " << test.getAge() << std::endl;
}