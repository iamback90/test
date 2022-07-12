#include <iostream>
#include <utility>

void Foo(int&& i) {
  std::cout << "int&&" << std::endl;
}

void Foo(int& i) {
  std::cout << "int&" << std::endl;
}


typedef int& lref;
typedef int&& rref;

int main() {
  int n;
  lref &ref0 = n;
  Foo(ref0);
  lref &&ref1 = n;
  Foo(ref1);
  rref &ref2 = n;
  Foo(ref2);
  rref &&ref3 = 3;
  std::cout << "typename: " << typeid(decltype(ref3)).name() << std::endl;
  Foo(std::forward<decltype(ref3)>(ref3));
  return 0;
}
