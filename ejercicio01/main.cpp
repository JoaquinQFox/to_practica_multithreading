#include <iostream>
#include <thread>

void imprimirPares() {
    for (int i = 1; i <= 20; ++i) {
        if (i % 2 == 0) {
            std::cout << "[Hilo Pares] " << i << "\n";
        }
    }
}

void imprimirImpares() {
    for (int i = 1; i <= 20; ++i) {
        if (i % 2 != 0) {
            std::cout << "[Hilo Impares] " << i << "\n";
        }
    }
}

int main() {
    std::thread hilo1(imprimirPares);
    std::thread hilo2(imprimirImpares);

    hilo1.join();
    hilo2.join();

    std::cout << "Programa principal: Ambos hilos han terminado.\n";
    return 0;
}
