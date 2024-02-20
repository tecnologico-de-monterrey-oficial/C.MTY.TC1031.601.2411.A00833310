#ifndef List_H
#define List_H

template <typename T>
class List {
private:
    vector<T> data;
    int size;
public:
    List();
    void insert(T a); // inserta un elemento al final de la lista
    void removeLast(); // elimina el último elemento de la lista
    T getData(int index); // regresa el elemento en la posición index
    int getSize(); // regresa el tamaño de la lista
    T getMax(); // regresa el elemento más grande de la lista
    void print();
};

// constructor
template <typename T>
List<T>::List() {
    size = 0; // Inicializo el tamaño de la lista en 0
}

// insert
template <typename T>
void List<T>::insert(T a) {
    // insertamos un dato en el verctor data
    data.push_back(a);
    // incrementamos el tamaño de la lista
    size++;
}

// removeLast
template <typename T>
void List<T>::removeLast() {
    if (size > 0) {
        // La lista no está vacía
        // removemos el último elemento de la lista
        data.pop_back(); 
        size--;
    } else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

// getData
template <typename T>
T List<T>::getData(int index) {
    return data[index];
}

// getSize
template <typename T>
int List<T>::getSize() {
    return size;
}

// getMax
template<typename T>
T List<T>::getMax() {
    if (size > 0) {
        // La lista no está vacía
        // creamos una variable auxiliar igual al primer elemento, donde
        // asumimos que ese es el más grande 
        T max = data[0];
        // comparamos max con el resto de los elementos para determinar el más grande
        for (int i=1; i<size; i++) {
            // comparamos cada elemento de la lista con max
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    } else {
        // no podemos regresar un valor dado que T puede ser de cualquier tipo
        throw out_of_range("La lista está vacía");
    }
}

// print
template <typename T>
void List<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << data[i] << " ";
    }
    cout << endl;
}

#endif