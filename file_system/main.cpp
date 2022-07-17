#include <iostream>
#include <experimental/filesystem>

int main(int argc, const char *argv[]) {
  auto myfolder = "..";
  if (std::experimental::filesystem::exists(myfolder)) {
    std::cout << myfolder << " exists" << std::endl;
  } else {
    std::cout << myfolder << " not exist" << std::endl;
    return 1;
  }
  for (auto e : std::experimental::filesystem::recursive_directory_iterator(myfolder)) {
    std::cout << e.path() << std::endl;
  }
  return 0;
}
