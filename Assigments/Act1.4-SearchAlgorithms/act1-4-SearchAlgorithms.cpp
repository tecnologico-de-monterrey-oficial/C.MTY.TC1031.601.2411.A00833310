#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}


// Búsqueda Secuencial
// Regresa la posición del valor a buscar y si no lo encuentra regresa -1
template <class T>
int sequentialSearch(vector<T> list,T data) {
    // Iteramos toda la lilsta
    for (int i=0; i<list.size(); i++) {
        // Comparamos el elemento i con el dato a buscar
        if (list[i] == data) {
            // Regresamos la posición i 
            return i;
        }
    }
    // No se encuentra el elemento
    return -1;
}

template <class T>
int binarySearch(vector<T> list, T data) {
    // creamos la variable con el limite inferior
    int left = 0;
    // creamos la variable con el límite superior
    int right = list.size() - 1;
    // Iteramos la lista hasta encontrar el valor o mientras left <= right
    while (left <= right) {
        // Encontramos el valor de en medio entre left y right
        int mid = (left + right) / 2;
        // Comparamos el valor a buscar con el valor de la lista en mid
        if (list[mid] == data) {
            // ya lo encontramos, regresamos mid
            return mid;
        } else {
            // no es igual
            // Validamos si nos movemos a la izquierda o la derecha
            if (data < list[mid]) {
                // el valor buscado es menor que el valor de la lista en mid
                // actualizamos el límite superior 
                right = mid - 1;
            } else {
                // el valor buscado es mayor que el valor de la lista en mid
                left = mid + 1;
            }
        }
    }
    // No lo encontramos y regresamos -1
    return -1;

}

void printList(vector<int> list) {
    for (int i=0; i<list.size(); i++) {
        cout << i << "-" << list[i] << endl;    
    }
}
void createList(vector<int> &list, int max) {
    for (int i=0; i<max; i++) {
        // genera un número random de 1 a 1,000,000
        int number = rand() % 1000000 + 1;
        // inserta el número generado en la lista
        list.push_back(number);
    }
}


int main() {
    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;


    vector<int> list;
    createList(list, 10000);
    // cout << "Lista en el main" << endl;
    // printList(list);
    int data;
    cout << "Teclea un valor de 1 al 1,000,000" << endl;
    cin >> data;

    startTime(begin);
    int index = sequentialSearch(list, data);
    getTime(begin, end);
    if (index >= 0) {
        cout << "El " << data << " se encuentra en la posición: " << index << endl;
    } else {
        cout << "El " << data << " no se encuentra en la lista" << endl;
    }
    // Ordenamos la lista
    sort(list.begin(), list.end());
    // printList(list);
    startTime(begin);
    index = binarySearch(list, data);
    getTime(begin, end);
    if (index >= 0) {
        cout << "El " << data << " se encuentra en la posición: " << index << endl;
    } else {
        cout << "El " << data << " no se encuentra en la lista" << endl;
    }
    
    
    return 0;
}