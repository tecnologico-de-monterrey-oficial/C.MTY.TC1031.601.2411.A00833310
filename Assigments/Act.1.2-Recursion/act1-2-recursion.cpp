#include <iostream>
using namespace std;

int sumaIterativa(int n) {
    int suma = 0;
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    return suma;
}

int sumaRecursiva(int n) {
    return (n > 1) ? n + sumaRecursiva(n - 1) : 1;
}

int sumaFormula(int n) {
    return n * (n + 1) / 2;
}

int fibonacciIterativa(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int f1 = 1, f2 = 1;
        for (int i = 3; i <= n; i++) {
            int aux = f1;
            f1 = f2;
            f2 = aux + f2;
        }
        return f2;
    }
}

int fibonacciRecursiva(int n) {
    return (n > 2) ? fibonacciRecursiva(n - 1) + fibonacciRecursiva(n - 2) : 1;
}

float bacteriasIterativa(int dias) {
    float bacterias = 1.0;
    for (int i = 1; i <= dias; i++) {
        bacterias *= (1 + (3.78 - 2.34));
    }
    return bacterias;
}

float bacteriasRecursiva(int dias) {
    return (dias > 0) ? bacteriasRecursiva(dias - 1) * (1 + (3.78 - 2.34)) : 1;
}

float inversionIterativa(int meses, float balance) {
    for (int i = 1; i < meses; i++) {
        balance *= (1 + 18.75 / 100);
    }
    return balance;
}

float inversionRecursiva(int meses, float balance) {
    return (meses > 1) ? inversionRecursiva(meses - 1, balance) * (1 + 18.75 / 100) : balance;
}

int main() {

    int n = 10;
    int meses = 10;
    float balance = 1000000.0;
    cout << "Suma iterativa: " << sumaIterativa(n) << endl;
    cout << "Suma recursiva: " << sumaRecursiva(n) << endl;
    cout << "Suma fórmula: " << sumaFormula(n) << endl;
    cout << "Fibonacci Iterativa: " << fibonacciIterativa(n) << endl;
    cout << "Fibonacci Recursiva: " << fibonacciRecursiva(n) << endl;
    cout << "Bacterias Iterativa: " << bacteriasIterativa(n) << endl;
    cout << "Bacterias Recursiva: " << bacteriasRecursiva(n) << endl;
    cout << "Inversión Iterativa: " << inversionIterativa(meses, balance) << endl;
    cout << "Inversión Recursiva: " << inversionRecursiva(meses, balance) << endl;

    return 0;
}
