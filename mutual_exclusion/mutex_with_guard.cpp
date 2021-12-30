#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

// Global key value store
std::map<std::string, std::string> web_pages;
std::mutex web_pages_mutex;

void save_page(const std::string& url){
    // Simulate long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "Fake content from web page";
    // lock
    std::lock_guard<std::mutex> web_pages_guard(web_pages_mutex);
    // Write results to key value store
    web_pages[url] = result;
}

int main(){
    std::thread thread1(save_page, "http://foo");
    std::thread thread2(save_page, "http://bar");
    thread1.join();
    thread2.join();
    // Print results
    for (const auto& web_page: web_pages){
        std::cout << "URL: " << web_page.first << "\n";
        std::cout << "Result: " << web_page.second << "\n";
    }
}
