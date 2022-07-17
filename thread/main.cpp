#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <unistd.h>
 
std::once_flag flag1;
std::mutex m;

void Run() {
  for (int i = 0; i < 6; ++i) {
    // sleep(1);
    std::lock_guard<std::mutex> lg(m);
    std::cout << "Run " << i << std::endl;
  }
}
void simple_do_once(const std::string &name)
{
    m.lock();
    std::cout << name << std::endl;
    m.unlock();
    // std::call_once(flag1, [](){ std::cout << "Simple example: called once\n"; });
    std::call_once(flag1,
                   []() {
		     std::thread t = std::thread(Run);
		     t.join();
		   }
		  );
}
 
int main()
{
    std::thread st1(simple_do_once, "thread 1");
    // st1.join();
    std::thread st2(simple_do_once, "thread 2");
    std::thread st3(simple_do_once, "thread 3");
    std::thread st4(simple_do_once, "thread 4");
    st1.join();
    st2.join();
    st3.join();
    st4.join();

    std::thread t1(Run);
    std::thread t2(Run);
    std::thread t3(Run);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
