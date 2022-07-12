#include "test.h"

#include <stdio.h>
int g = 11;
void Foo() {
  static int a = 1;
  printf("addr of a: %x\n addr of g: %x\n", &a, &g);
}
