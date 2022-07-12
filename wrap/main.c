#include <stdio.h>

extern void Test();

void __wrap_Test() {
  printf("%s in %s\n", __FUNCTION__, __FILE__);
  __real_Test();
}

int main(int argc, const char* argv[]) {
  Test();
  return 0;
}
