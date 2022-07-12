#include <iostream>

#define TYPE_TRAIT(name, func)                            \
  template <typename T>                                   \
  struct name {                                           \
    template <typename Class>                             \
    static constexpr bool Test(decltype(&Class::func)*) { \
      return true;                                        \
    }                                                     \
    template <typename>                                   \
    static constexpr bool Test(...) {                     \
      return false;                                       \
    }                                                     \
    static constexpr bool value = Test<T>(nullptr);       \
  };                                                      \
  template <typename T>                                   \
  constexpr bool name<T>::value;

TYPE_TRAIT(HasFoo, Foo)

  class TestClass {
    public:
      void Foo() {}
      void Print() {}
  };

  template <typename T>
  class CheckHasFoo {
    public:
      static constexpr bool value = HasFoo<T>::value;
  };

  int main(int argc, const char* argv[]) {
    std::cout << typeid(decltype(&TestClass::Foo)*).name() << std::endl;
  //  std::cout << typeid(decltype(&std::ofstream::Foo)*).name() << std::endl;
    std::cout << "TestClass has Foo: " << CheckHasFoo<TestClass>::value << std::endl;
    std::cout << "std::ofstream has Foo: " << CheckHasFoo<std::ofstream>::value << std::endl;
    return 0;
  }
