
#include <thread>
#include <chrono>

void kitchen_cleaner(){
    while(true){
        printf("Olivia cleaned the kitchen.\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(){
    // Begin execution, pending OS scheduling
    std::thread olivia(kitchen_cleaner);
    // Runs the thread in the background detached from the main thread.
    // This is a daemon thread. It is also non-joinable
    olivia.detach();
    // olivia is now running continuously in the background
    for (int i=0; i<3; i++){
        printf("Baron is coooking..\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    printf("Baron is done!\n");
    // No need to run olivia.join() since we detached it from the main thread.
    // Once the main thread is done (Baron cooking) the background thread will exit as well.
    // The daemon thread will be abruptly terminated when the main thread finishes.
}
