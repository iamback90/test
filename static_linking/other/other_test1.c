#include <stdio.h>
void Foo() {
  printf("%s in %s\n", __FUNCTION__, __FILE__);
}

void NotReferencedFuncInOtherTest1() {}
