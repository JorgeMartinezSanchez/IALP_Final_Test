//ALUMNO: JORGE MARTÍNEZ SÁNCHEZ
#pragma once
#include <iostream>
#include <string>
using namespace std;

string ifDayNegative(int nd_year, int nd_month, int nd_day, int nd_max_day);
string daySet(int year, int month, int day, int max_day);
string ifMonthNegative(int neg_year, int neg_month, int neg_day, int neg_max_day);
string monthSet(int yearM, int monthM, int dayM, int max_dayM);
string Date(int d, int m, int y);

string ifDayNegative(int nd_year, int nd_month, int nd_day, int nd_max_day){
    nd_day = -nd_day;
    while (nd_day>nd_max_day){
        nd_day--;
    }
    return to_string(nd_year) + "-" + to_string(nd_month) + "-" + to_string(nd_day);
}

string daySet(int year, int month, int day, int max_day){ //Función para introducir día
    while (day>max_day){
        day--;
    }
    if (day==0){
        day += 1;
    }
    else if(day<0){
        return ifDayNegative(year, month, day, max_day);
    }
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}

string ifMonthNegative(int neg_year, int neg_month, int neg_day, int neg_max_day, int neg_leap){
    neg_month = -neg_month;
    while(neg_month>12){
        neg_month--;
    }
    if(neg_month<0){
        if (neg_month % 2 != 0){
            neg_month = -neg_month; // Turn odd month positive
            while (neg_month>12){
                neg_month--;
            }
        }
    }
    if (neg_month%2 != 0 || neg_month==8 || neg_month==12){
        neg_max_day = 31; 
    }
    else if (neg_month%2 != 0){
        neg_month = -neg_month;
        neg_max_day = 31;
    }
    else if (neg_month==2){
        neg_max_day = neg_leap;
    }
    else {
        neg_max_day = 30;
    }
    return daySet(neg_year, neg_month, neg_day, neg_max_day); 
}

string monthSet(int yearM, int monthM, int dayM, int max_dayM, int leapM){
    while(monthM>12){
        monthM--;
    }
    if(monthM<0){
        if (monthM % 2 != 0){
            monthM = -monthM; // Turn odd month positive
            while (monthM>12){
                monthM--;
            }
        }
    }
    if (monthM%2 != 0 || monthM==8 || monthM==12){
        max_dayM = 31;
    }
    else if(monthM==0){
        monthM += 1;
        max_dayM = 31;
    }
    else if(monthM<0){
        return ifMonthNegative(yearM, monthM, dayM, max_dayM, leapM);
    }
    else if (monthM==2){
        max_dayM = leapM;
    }
    else {
        max_dayM = 30;
    }
    return daySet(yearM, monthM, dayM, max_dayM);
}

//******************************************************************************************************************
string Date(int d, int m, int y){ //Función principal
    int max_day = 0;
    int leap = (y%4==0) ? 29 : 28;
    if (y<0){
        y = -y;
        leap = (y%4==0) ? 29 : 28;
    }
    return monthSet(y, m, d, max_day, leap);
}