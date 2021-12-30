#include <thread>
#include <mutex>
#include <chrono>

unsigned int garlic_count = 0;
std::mutex pencil;

void shopper(){
    for(int i=0; i<10; i++){
        pencil.lock(); // keep critical code sections small
        printf("Shopper %d is thinking..\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        garlic_count++; // three step operation
        pencil.unlock();
    }
}

int main(){
    std::thread baron(shopper);
    std::thread olivia(shopper);
    baron.join();
    olivia.join();
    printf("We should buy %u garlic.\n",garlic_count);

}
