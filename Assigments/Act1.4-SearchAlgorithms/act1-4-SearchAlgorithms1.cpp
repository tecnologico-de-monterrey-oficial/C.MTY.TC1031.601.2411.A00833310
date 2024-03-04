#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void sequentialSearch(const vector<int>& list, int data, int& comparisons) {
    for (int i = 0; i < list.size(); ++i) {
        ++comparisons;
        if (list[i] == data) {
            break;
        }
    }
}

void binarySearch(const vector<int>& list, int data, int& comparisons) {
    int left = 0;
    int right = list.size() - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        ++comparisons;
        
        if (list[mid] == data) {
            break;
        } else if (data < list[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

int main() {
    srand(time(0));

    vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(rand() % 1000000 + 1);
    }

    sort(numbers.begin(), numbers.end());

    int data;
    while (true) {
        cout << "Teclea un número entre 1 y 1,000,000 (0 para salir): ";
        cin >> data;

        if (data == 0) {
            break;
        }

        int sequentialComparisons = 0;
        auto startSequential = chrono::high_resolution_clock::now();
        sequentialSearch(numbers, data, sequentialComparisons);
        auto endSequential = chrono::high_resolution_clock::now();

        int binaryComparisons = 0;
        auto startBinary = chrono::high_resolution_clock::now();
        binarySearch(numbers, data, binaryComparisons);
        auto endBinary = chrono::high_resolution_clock::now();

        cout << "Número " << data << " encontrado en la búsqueda secuencial. Comparaciones: " << sequentialComparisons << ". Tiempo: " << chrono::duration<double>(endSequential - startSequential).count() << " segundos." << endl;
        cout << "Número " << data << " encontrado en la búsqueda binaria. Comparaciones: " << binaryComparisons << ". Tiempo: " << chrono::duration<double>(endBinary - startBinary).count() << " segundos." << endl;
    }

    return 0;
}
