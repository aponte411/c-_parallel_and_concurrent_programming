#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
std::mutex pencil;

void shopper(){
    for(int i=0; i<1000000; i++){
        pencil.lock(); // keep critical code sections small
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
