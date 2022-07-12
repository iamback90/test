#include "foreign.h"
#include <stdio.h>

void Foreign() {
  printf("%s\n", __FILE__);
}

void TestInForeign() {
  printf("%s\n",__FUNCTION__);
}
