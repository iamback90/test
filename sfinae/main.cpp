#include <iostream>

#include <type_trait>

template<typename T>
class TypeTrait {
 public:
  constexpr bool HasMemerFunc(typename decltype(T::Func1)*) {
    return true;
  }
  constexpr bool HasMemerFunc(...) {
    return false;
  }
  constexpr bool has;
};

bool TypeTrait<T>::has = 
