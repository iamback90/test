#include <type_traits>
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {
  // std::string a = "11";
  int a = 11;
  typename std::enable_if<std::is_integral<decltype(a)>::value, float>::type ff;
  std::cout << typeid(decltype(ff)).name() << std::endl;
  return 0;
}
