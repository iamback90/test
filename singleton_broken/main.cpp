#include <dlfcn.h>
#include <string>
#include <iostream>
#include "test.h"

int main(int argc, const char** argv) {
    std::string path = argv[1];
    std::string soname = path + "/libtest.so";
    std::cout << soname << std::endl;
    void *handle_ = dlopen(soname.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (handle_ == NULL) {
        const char* err = dlerror();
        std::cout << err << std::endl;
        return 2;
    } else {
        typedef void (*FuncType)();
        FuncType Foo = (FuncType)dlsym(handle_, "Foo");
        if (Foo != NULL) {
          Foo();
        } else {
          const char* err = dlerror();
          std::cout << err << std::endl;
          return 1;
        }
    }
    Foo();
  return 0;
}
