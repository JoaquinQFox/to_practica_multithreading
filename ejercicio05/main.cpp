#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

std::queue<int> cola;
std::mutex mtx;
bool terminado = false;

// función para el productor
void productor() {
    for (int i = 1; i <= 10; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            cola.push(i);
            std::cout << "[Productor] Produjo: " << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    // producción terminada
    std::lock_guard<std::mutex> lock(mtx);
    terminado = true;
}

int main() {
    return 0;
}
