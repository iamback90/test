#include <dlfcn.h>
#include <string>
#include <iostream>
// #include "foreign.h"
// #include "test.h"

extern "C" {
void Foreign();
}

void Foreign() {
  std::cout << __FUNCTION__ << " in " << __FILE__ << " : " << __LINE__ << std::endl;
}

int main(int argc, const char*argv[]) {
    std::string path = argv[1];
    std::string soname = path + "/libtest.so";
    std::cout << soname << std::endl;
    void *handle_ = dlopen(soname.c_str(), RTLD_NOW | RTLD_GLOBAL);
    if (handle_ == NULL) {
        const char* err = dlerror();
        std::cout << err << std::endl;
        return 2;
    } else {
        typedef void (*FuncType)();
        FuncType RegisterClassManual = (FuncType)dlsym(handle_, "Foo");
        if (RegisterClassManual != NULL) {
          RegisterClassManual();
        } else {
          const char* err = dlerror();
          std::cout << err << std::endl;
          return 1;
        }
    }
   //  Foo();
   // TestInForeign();
    Foreign();
}
