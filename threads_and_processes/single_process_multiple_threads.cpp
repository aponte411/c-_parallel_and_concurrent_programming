#include <thread>
#include <chrono>
#include <unistd.h>

void cpu_waster(){
    printf("CPU Waster process ID %d\n", getpid());
    printf("CPU Waster thread ID %d\n", std::this_thread::get_id());
    while(true) continue;
}


int main(){
    printf("Main process ID %d\n", getpid());
    printf("Main thread ID %d\n", std::this_thread::get_id());
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);

    while(true) std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}
