
#include <iostream>
#include <thread>

using namespace std;

class Sumador {
private:
    int n; 

public:
    Sumador(int limite) {
        n = limite;
    }
    void operator()() {

        int suma = 0;

        for (int i = 1; i <= n; i++) {
            suma = suma + i;
        }

        cout << "Suma hasta " << n
             << " = " << suma << endl;
    }
};

int main() {

    Sumador s1(10);
    Sumador s2(100);
    Sumador s3(1000);

    thread hilo1(s1);
    thread hilo2(s2);
    thread hilo3(s3);

    hilo1.join();
    hilo2.join();
    hilo3.join();

    return 0;
}
