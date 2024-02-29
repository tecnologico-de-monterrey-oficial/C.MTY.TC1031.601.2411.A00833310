#include <iostream>
#include <vector>

using namespace std;

// Función iterativa para la suma de enteros impares en un vector
int sumaImparesIterativa(const vector<int>& vec) {
    int suma = 0;
    for (int num : vec) {
        if (num % 2 != 0) {
            suma += num;
        }
    }
    return suma;
}

// Función recursiva para la suma de enteros impares en un vector
int sumaImparesRecursiva(const vector<int>& vec, int index) {
    if (index < 0) {
        return 0;
    }

    int sumaAnterior = sumaImparesRecursiva(vec, index - 1);
    if (vec[index] % 2 != 0) {
        return sumaAnterior + vec[index];
    } else {
        return sumaAnterior;
    }
}

int main() {
    // Ejemplo de uso con un vector de enteros positivos
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Llamada a la función iterativa
    int sumaIterativa = sumaImparesIterativa(numeros);
    cout << "Suma de impares (iterativa): " << sumaIterativa << endl;

    // Llamada a la función recursiva
    int sumaRecursiva = sumaImparesRecursiva(numeros, numeros.size() - 1);
    cout << "Suma de impares (recursiva): " << sumaRecursiva << endl;

    return 0;
}
