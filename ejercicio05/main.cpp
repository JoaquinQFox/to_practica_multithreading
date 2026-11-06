#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

std::queue<int> cola;
std::mutex mtx;
bool terminado = false;

// Ffnción para el productor
void productor() {
    for (int i = 1; i <= 10; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            cola.push(i);
            std::cout << "[Productor] Produjo: " << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    // indicamos que ya no habrá más producción
    std::lock_guard<std::mutex> lock(mtx);
    terminado = true;
}

// función para el consumidor
void consumidor() {
    while (true) {
        int valor = -1;
        bool hayDato = false;

        {
            std::lock_guard<std::mutex> lock(mtx);
            if (!cola.empty()) {
                valor = cola.front();
                cola.pop();
                hayDato = true;
            } else if (terminado) {
                // si la cola está vacía y el productor terminó, salimos del ciclo
                break;
            }
        }

        if (hayDato) {
            std::cout << "  [Consumidor] Consumio: " << valor << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    // hilos
    std::thread hiloProductor(productor);
    std::thread hiloConsumidor(consumidor);

    // esperamos a que ambos hilos terminen
    hiloProductor.join();
    hiloConsumidor.join();

    std::cout << "Programa finalizado correctamente." << std::endl;
    return 0;
}
