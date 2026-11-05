#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::thread hilo([]() {
        for (int i = 0; i < 5; i++) {
            std::cout << "Hola mundo!" << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    hilo.join();
    return 0;
}