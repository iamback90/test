#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>

// extern "C" void func(int sig) {
void func(int sig) {
  std::cout << "sig: " << sig << " occurs" << std::endl;
  std::signal(SIGINT, SIG_DFL);
}

int main() {
  using namespace std::chrono_literals;
  // std::signal(SIGINT, SIG_IGN);
  // std::signal(SIGINT, SIG_DFL);
  std::signal(SIGINT, func);
  for (int i = 0; i < 8; i++) {
    std::cout << i << " times" << std::endl;
    std::this_thread::sleep_for(2000ms);
  }
  return 0;
}
