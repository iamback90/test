#include "test.h"
#include <stdio.h>

/*
void Foreign() {
  printf("%s\n", __FILE__);
}
*/
void Foo() {
  printf("%s: ", __FILE__);
  Foreign();
}
