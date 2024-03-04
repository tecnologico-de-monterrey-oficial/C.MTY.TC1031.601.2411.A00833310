#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin) {
    // start time
    begin = chrono::high_resolution_clock::now();
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) {
    end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista de números aleatorios
void createList(vector<int> &list, int max) {
    for (int i = 0; i < max; i++) {
        // genera un número random de 1 a 100
        int number = rand() % 100 + 1;
        // inserta el número generado en la lista
        list.push_back(number);
    }
}

// Imprime la lista
void printList(vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

// Intercambio el valor del índice A con el valor del índice B
template <class T>
void swap(vector<T> &list, int a, int b) {
    // Creamos una variable tempora
    T aux = list[a];
    // Actualizamos a
    list[a] = list[b];
    // Actualizamos b
    list[b] = aux;
}

// Swap Sort
template <class T>
void swapSort(vector<T> &list, int &swaps, int &comparisons) {
    // Iteramos todos los elementos desde el primero hasta el penultimo
    for (int i = 0; i < list.size() - 1; i++) {
        // Iteramos todos los elementos desde i+1 hasta el último elemento
        for (int j = i + 1; j < list.size(); j++) {
            // Comparamos el valor de i con el valor de j
            // Incrementamos las comparaciones
            comparisons++;
            if (list[j] < list[i]) {
                // los intercambiamos
                swap(list, i, j);
                // Incrementamos los intercambios
                swaps++;
            }
        }
    }
}


///////////////////////////////////



// Bubble Sort
template <class T>
void bubbleSort(vector<T> &list, int &swaps, int &comparisons) {
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Incrementamos las comparaciones
            comparisons++;

            if (list[j] > list[j + 1]) {
                // swap if the element found is greater
                swap(list, j, j + 1);
                // Incrementamos los intercambios
                swaps++;
                swapped = true; 
            }
        }

        // If no swaps occurred in the entire inner loop, the array is already sorted
        if (!swapped) {
            return;
        }
    }
}

int main() {
    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    vector<int> list;
    int swaps = 0;
    int comparisons = 0;

    createList(list, 7);

    // Swap sort
    cout << "Swap sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    // ordenamos la lista con Swap Sort
    swapSort(list, swaps, comparisons);
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;

    // Bubble Sort
    swaps = 0;
    comparisons = 0;
    createList(list, 7);
    cout << "\nBubble sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    // ordenamos la lista con Bubble Sort
    bubbleSort(list, swaps, comparisons);
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;

    return 0;
}
