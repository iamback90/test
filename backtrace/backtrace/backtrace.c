#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

/* Obtain a backtrace and print it to stdout. */
void print_bt (void) {
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf ("%s\n", strings[i]);

  free (strings);
}

void d() { printf("%s\n", __FUNCTION__); print_bt(); }
void c() { d(); }
void b() { c(); }
void a() { b(); }

int main(int argc, const char*argv[]) {
  a();
  return 0;
}


