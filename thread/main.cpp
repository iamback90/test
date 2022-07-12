#include <iostream>
#include <thread>
#include <mutex>
 
std::once_flag flag1;

void Run() {
  std::cout << "Run" << std::endl;
}
void simple_do_once()
{
    // std::call_once(flag1, [](){ std::cout << "Simple example: called once\n"; });
    std::call_once(flag1, [](){ std::thread t = std::thread(Run); });
}
 
int main()
{
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
}
