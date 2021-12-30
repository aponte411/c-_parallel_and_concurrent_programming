#include <thread>

unsigned int garlic_count = 0;

void shopper(){
    // Increment is a three cycle operation: read -> transform -> write
    for(int i=0; i<10; i++) garlic_count++;
}

int main(){
    std::thread baron(shopper);
    std::thread olivia(shopper);
    baron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
}
