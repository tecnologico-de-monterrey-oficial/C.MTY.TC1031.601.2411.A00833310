#pragma once
#include <string>

struct Log {
    string month;
    string year;
    string day;
    string time;
    string ip;
    string message;
    string key;
    Log(string month, string year, string day, string time, string ip, string message);
    string getMonth(string month);
    bool operator<(Log log);
};


Log::Log(string month, string year, string day, string time, string ip, string message) {
    this->month = month;
    this->year = year;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = year+getMonth(month)+day+time;
}


string Log::getMonth(month) {
    if (month == "Jan"){
        return "01"
    }
    
    if (month == "Feb"){
        return "02"
    }

    if (month == "Mar"){
        return "03"
    }

    if (month == "Apr"){
        return "04"
    }

    if (month == "May"){
        return "05"
    }

    if (month == "Jun"){
        return "06"
    }

    if (month == "Jul"){
        return "07"
    }

    if (month == "Aug"){
        return "08"
    }

    if (month == "Sep"){
        return "09"
    }

    if (month == "Oct"){
        return "10"
    }

    if (month == "Nov"){
        return "11"
    }

    if (month == "Dec"){
        return "12"
    }

    return "00";
}


bool Log::operator<(Log log) {
    return this->key > log.key;
}