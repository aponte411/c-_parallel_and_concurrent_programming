#include <thread>
#include <chrono>

void chef_olivia(){
    printf("Olivia started & is waiting for sausage to thaw..\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Olivia is done cutting the sausage\n");
}

int main(){
    printf("Baron requests olivias help\n");
    std::thread olivia(chef_olivia);
    printf("Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Baron continues cooking soup\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    printf("Baron patiently waits for olivia to finish and join..\n");
    olivia.join();
    printf("Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Baron and Olivia are both done!\n");
}
