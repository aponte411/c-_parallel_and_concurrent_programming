#include <thread>
#include <atomic>
#include <chrono>

std::atomic<unsigned int> garlic_count(0);

void shopper(){
    for(int i=0;i<10; i++) garlic_count++;
}

int main(){
    std::thread t1(shopper);
    std::thread t2(shopper);
    t1.join();
    t2.join();
    printf("We shoud buy %u garlic.\n", garlic_count.load());
}
