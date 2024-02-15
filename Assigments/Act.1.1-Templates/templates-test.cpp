#include <iostream>

using namespace std;

int suma(int a, int b){
    return a + b;
}

float sumFloat(float a, float b){
    return a + b;
}

string concat(string a, string b){
    return a + b;
}


template <typename T>
T sum(T a, T b) {
    return a + b;
}



int main(){

    int a = 5;
    int b = 10;
    float x = 5.8;
    float y = 10.5;
    string s1 = "a"
    string s2 = "b"
    cout << "La suma de a + b = " << c << endl;


}