#include <stdio.h>

void Foo() {
  int i = 1;
  int j = 2;
  printf("%s %s i + j = %d\n", __FILE__, __FUNCTION__, i + j);
}
