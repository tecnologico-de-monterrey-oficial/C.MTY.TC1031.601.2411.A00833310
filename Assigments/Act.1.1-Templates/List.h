#ifndef List_H
#define List_H



class List {
private:
    vector<int> data;
    int size;

public:
    List();
    void insert (int a);
    void print();
}

//Constructor

List::List(){
    size = 0; //Inicializo el tamaño de la lista en 0
}

//insert
void List::insert(int a) {
    //Insertamos dato en un vector dat
    data.push_back(a);
    //Incrementamos el tamaño de la lista
}

//print
void List::print() {
    for (auto el : data){
        cout << el << "-";
    
    }
    cout << endl;
}