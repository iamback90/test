#include <stdio.h>
#include <libunwind.h>

void print_bt() {
  void *array[10];
  int s = 10;
  int ret = unw_backtrace(array, s);
  printf("ret = %d\n", ret);
  for (int i = 0; i < ret; ++i) {
    printf("%s\n", (char*)array[i]);
  }

}
void d() { printf("%s\n", __FUNCTION__); print_bt(); }
void c() { d(); }
void b() { c(); }
void a() { b(); }

int main(int argc, const char*argv[]) {
  a();
  return 0;
}
