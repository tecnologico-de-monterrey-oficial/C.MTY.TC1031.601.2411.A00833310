#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#include "Log.h"

int main(){
    ifstream logFile;
    logFile.open("log601-1.txt");
    //logFile.open("logTest.txt");
    vector<Log>logs;

    string month;
    string year;
    string day;
    string time;
    string ip;
    string message;
    string line;
    while (getline(logFile,line)) {
       // cout << line << endl;
       stringstream ss(line);
       ss >> month >> day >> year >> time >> ip >> message;
       string msg;
       while (ss >> msg){
        message = message + " " + msg;
       }
       cout << month << "" << message << endl;
    }

    while(logFile >> month>>day>>year>>time>>ip>>message){
        cout<<"month: "<<month<<endl;
    }


    Log log(month, day, year, time, ip, message);
    cout << log.month << endl;
    logs.push_back(log);
}

for (auto log : logs) {
    cout << long.key << endl;
}

if (logs[0].key < logs[1].key) {
    cout << "es menor" << endl;
} else {
    cout << "es mayor" << endl;
}

    //Cierra el archivo de texto
    //logFile.close();