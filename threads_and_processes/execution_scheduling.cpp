#include <thread>
#include <chrono>

bool chopping = true;

void veggie_chopper(const char* name){
    unsigned int veggie_count = 0;
    while(chopping) veggie_count++;
    printf("%s chopped %u veggies\n", name, veggie_count);
}

int main(){
    /*
        If you run this multiple times, youll see that each thread
        chops a different number of veggies. This demostrates that when the OS
        schedules the threads onto the processor, it isnt always done fairly..some
        threads get to chop more veggies than others. So your programs shouldnt
        rely on execution scheduling for correctness.
     */
    std::thread baron(veggie_chopper, "Baron");
    std::thread olivia(veggie_chopper, "Olivia");
    printf("Baron and olivia are chopping veggies..\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    baron.join();
    olivia.join();
}
