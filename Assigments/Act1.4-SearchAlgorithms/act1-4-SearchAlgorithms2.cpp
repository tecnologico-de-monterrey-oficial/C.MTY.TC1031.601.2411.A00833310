#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Función para encontrar el carácter único y contar comparaciones en búsqueda secuencial
std::pair<char, int> findUniqueSequential(const std::string& str) {
    int comparisons = 0;
    char uniqueChar = '\0';

    for (int i = 0; i < str.length(); i++) {
        comparisons++;
        if (i == 0 || str[i] != str[i - 1]) {
            uniqueChar = str[i];
            break;
        }
    }

    return std::make_pair(uniqueChar, comparisons);
}

// Función para encontrar el carácter único y contar comparaciones en búsqueda binaria
std::pair<char, int> findUniqueBinary(const std::string& str) {
    int comparisons = 0;
    char uniqueChar = '\0';

    int low = 0;
    int high = str.length() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if ((mid == 0 || str[mid] != str[mid - 1]) && (mid == str.length() - 1 || str[mid] != str[mid + 1])) {
            uniqueChar = str[mid];
            break;
        } else if (str[mid] == str[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid - 2;
        }
    }

    return std::make_pair(uniqueChar, comparisons);
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignorar el salto de línea después de n

    for (int i = 0; i < n; i++) {
        std::string str;
        std::getline(std::cin, str);

        // Búsqueda secuencial
        auto resultSequential = findUniqueSequential(str);
        std::cout << resultSequential.first << " " << resultSequential.second << " ";

        // Búsqueda binaria
        auto resultBinary = findUniqueBinary(str);
        std::cout << resultBinary.first << " " << resultBinary.second << std::endl;
    }

    return 0;
}
