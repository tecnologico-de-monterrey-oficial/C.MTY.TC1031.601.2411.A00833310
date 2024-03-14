#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

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


//Insertion Sort
template <class T>
void insertionSort(vector<T> &list, int &swaps, int &comparisons) {
    int n = list.size();

    for (int i = 1; i < n; i++) {
        T key = list[i];
        int j = i - 1;

        // Incrementamos las comparaciones
        comparisons++;

        while (j >= 0 && list[j] > key) {
            // Move elements greater than key to one position ahead
            list[j + 1] = list[j];
            // Incrementamos los intercambios
            swaps++;
            j--;
        }

        // Place the key in its correct position
        list[j + 1] = key;
    }
}


//Selection Sort
template <class T>
void selectionSort(vector<T> &list, int &swaps, int &comparisons) {
    // Iteramos todos los elelementos hasta el penúltimo
    for (int i=0; i<list.size()-1; i++) {
        // Creamos una variable que va a guardar el valor de índice con el menor valor
        int minIndex = i;
        // Iteramos desde i+1 hasta el final de la lista
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos las comparaciones
            comparisons++;
            // comparamos el valor mínimo con el valor de j
            if(list[j] < list[minIndex]) {
                // Cambiamos el valor del índice menor
                minIndex = j;
            }
        }
        // Validamos si tenemos que intercambiar los datos
        // Intercambiamos el valor de i con el valor de minIndex
        swap(list, i, minIndex);
        if (i != minIndex) {
            // Incrementamos los intercambios 
            swaps++;
        }
    }
}


// Merge
template <class T>
void merge(vector<T> &list, int l, int m, int r) {
    // Los vamos a unir
    // Creamos una lista temporal "left"
    vector<T> left;
    // Creamos una lista temporal "right"
    vector<T> right;
    // Lista temporal left
    // iteramos desde left hasta mid
    for (int i=l; i<=m; i++) {
        // agregamos cada elemento a la lista left
        left.push_back(list[i]);
    }
    // Lista temporal right
    // iteramos desde mid+1 hasta right
    for (int j=m+1; j<=r; j++) {
        // agregamos cada elemento a la lista right
        right.push_back(list[j]);
    }
    
    // Creamos índices temporales
    // Creamos un índice temporal que apunte a la posición de la lista original listIndex igual a left
    int listIndex = l;
    // Creamos un índice temporal para la lista izquieda igual a 0
    int leftIndex = 0;
    // Creamos un índice temporal para la lista derecha igual a 0
    int rightIndex = 0;

    // Proceso de comparación
    // Iteramos mientras leftIndex sea menor al tamaño de la lista left y rightIndex sea menor al tamaño de la lista right
    while (leftIndex < left.size() && rightIndex < right.size()) {
        // Comparamos el valor de la lista izquierda en la posición leftIndex con el valor de de la lista derecha en la posición rightIndex
        if (left[leftIndex] < right[rightIndex]) {
            // el valor del lado izquierdo es menor al valor de lado derecho
            // le asignamos a la lista en la posición listIndex el valor de la lista izquierda en la posición leftIndex
            list[listIndex] = left[leftIndex];
            // Incrementamos el valor de leftIndex
            leftIndex++;
        } else {
            // el valor del lado derecho es menor al valor de lado izquierdo
            // le asignamos a la lista en la posición listIndex el valor de la lista derecha en la posición rightIndex
            list[listIndex] = right[rightIndex];
            // Incrementamos el valor de rightIndex
            rightIndex++;
        }
        // Incrementamos el valor de listIndex
        listIndex++;
    }
    // Termina el while

    // Vacíar la lista que tenga elementos en la lista original
    // Iteramos mientras leftIndex sea menor al tamaño de la lista left
    while (leftIndex < left.size()) {
        // le asignamos a la lista en la posición listIndex el valor de la lista izquierda en la posición leftIndex
        list[listIndex] = left[leftIndex];
        // Incrementamos el valor de leftIndex
        leftIndex++;
        // Incrementamos el valor de listIndex
        listIndex++;
    }
    // Termina el while
    // Iteramos mientras rightIndex sea menor al tamaño de la lista right
    while (rightIndex < right.size()) {
        // le asignamos a la lista en la posición listIndex el valor de la lista derecha en la posición rightIndex
        list[listIndex] = right[rightIndex];
        // Incrementamos el valor de rightIndex
        rightIndex++;
        // Incrementamos el valor de listIndex
        listIndex++;
    }
    // Termina el while

}


// Merge Sort - Función recursiva
template <class T>
void mergeSort(vector<T> &list, int left, int right) {
    // Encontrar el punto de en medio
    int mid = (left + right) / 2;
    // Condición de control
    if (left < right) {
        // Mando llamar a la misma función con los valores desde izquierda hasta el medio
        mergeSort(list, left, mid);
        // Mando llamar a la misma función con los valores desde en medio + 1 hasta la derecha
        mergeSort(list, mid+1, right);
    }
    // Voy a llamar a una función que va a unir las dos listas
    merge(list,left,mid,right);
}


// Partition function for Quick Sort
template <class T>
int partition(vector<T> &arr, int low, int high, int &swaps, int &comparisons) {
    T pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // Increment comparisons
        comparisons++;
        if (arr[j] < pivot) {
            // Increment swaps
            swaps++;
            i++;
            swap(arr, i, j);
        }
    }

    // Increment swaps
    swaps++;
    swap(arr, i + 1, high);
    return (i + 1);
}

// Quick Sort function
template <class T>
void quickSort(vector<T> &arr, int low, int high, int &swaps, int &comparisons) {
    if (low < high) {
        // Find pivot such that elements smaller than pivot are on the left, and elements greater are on the right
        int pivotIndex = partition(arr, low, high, swaps, comparisons);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIndex - 1, swaps, comparisons);
        quickSort(arr, pivotIndex + 1, high, swaps, comparisons);
    }
}

//Counting Sort
template <class T>
void countingSort(vector<T> &list) {
    // Encontrar el valor máximo en la lista
    T maxVal = *max_element(list.begin(), list.end());

    // Crear un arreglo de conteo con tamaño igual al valor máximo encontrado
    vector<int> count(maxVal + 1, 0);

    // Contar la frecuencia de cada elemento en la lista
    for (T element : list) {
        count[element]++;
    }

    // Recrear la lista en orden ascendente utilizando el arreglo de conteo
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            list[index++] = i;
            count[i]--;
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


    //Insertion Sort
    swaps = 0;
    comparisons = 0;
    cout << "\nInsertion sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    insertionSort(list, swaps, comparisons);
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;

    //Selection Sort
    comparisons = 0;
    swaps = 0;
    list = list;
    cout << "Selection sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    // ordenamos la lista con Swap Sort
    selectionSort(list, swaps, comparisons);
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;

    //Merge Sort
    swaps = 0;
    comparisons = 0;
    createList(list, 7);
    cout << "\nMerge sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    
    // Sort the list using Merge Sort
    mergeSort(list, 0, list.size() - 1);
    
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;


    //Quick Sort
    swaps = 0;
    comparisons = 0;
    createList(list, 7);
    cout << "\nQuick sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    
    // Sort the list using Quick Sort
    quickSort(list, 0, list.size() - 1, swaps, comparisons);
    
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << "Comparaciones: " << comparisons << " intercambios: " << swaps << endl;

    // Counting Sort
    createList(list, 7);
    cout << "Counting Sort" << endl;
    cout << "Lista inicial" << endl;
    printList(list);
    startTime(begin);
    countingSort(list);
    getTime(begin, end);
    cout << "Lista ordenada" << endl;
    printList(list);
    cout << endl;

    return 0;
}
