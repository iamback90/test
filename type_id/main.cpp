#include <typeinfo>
#include <iostream>
class A {
  public:
    virtual void Test() {};
    void Func() {}
};

class B : public A {
  public:
    void Test() { std::cout << "B" << std::endl; }
    void Func1() {}
};

#define PRINT(x)  \
  std::cout << #x << " " << (x) << std::endl;

int main() {
  A *p = new B();
  /*std::cout << typeid(p) == typeid(A*) << std::endl;
  std::cout << typeid(p) == typeid(B*) << std::endl;
  std::cout << typeid(*p) == typeid(A) << std::endl;
  std::cout << typeid(*p) == typeid(B) << std::endl;*/
  PRINT(typeid(p) == typeid(A*));
  PRINT(typeid(p) == typeid(B*));
  PRINT(typeid(*p) == typeid(A));
  PRINT(typeid(*p) == typeid(B));
  PRINT(typeid(1 + 1).name());
  unsigned int i = 2;
  PRINT(typeid(i++).name());
  PRINT(i);
  PRINT(typeid(decltype(++i)).name());
  PRINT(i);

  return 0;
}
