extern void Foo();
// extern void __attribute__((weak)) Foo();
// void __attribute__((weak)) Foo() {
//   printf("%s\n", __FILE__);
// }

int main() {
  Foo();
  return 0;
}
