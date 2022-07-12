#include <stdio.h>

void __attribute__((weak)) Foo() {
  printf("%s %s\n", __FILE__, __FUNCTION__);
}
