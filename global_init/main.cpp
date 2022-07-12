#include <iostream>

class Test {
  public:
   Test() {
     std::cout << __FUNCTION__ << std::endl;
   }
   void Foo() {}
};

static Test t;

int main() {
  std::cout << __FUNCTION__ << std::endl;
  t.Foo();
  return 0;
}
