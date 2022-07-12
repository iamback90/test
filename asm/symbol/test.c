extern int g;
extern void ExternFunc(int i, int j, int k);
int g_int = 11;
static int static_int = 22;

void Test() {}

void Foo() {
  int i = g + g_int + static_int;
  ExternFunc(g, g_int, i);
  Test();
}
