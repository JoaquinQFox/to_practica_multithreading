#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

// recursos compartidos entre hilos
std::queue<int> cola;
std::mutex mtx;
bool terminado = false;

int main() {
    return 0;
}
