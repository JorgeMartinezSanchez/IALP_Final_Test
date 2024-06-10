#include <iostream>
#include <string>
using namespace std;

string ifDayNegative(int nd_year, int nd_month, int nd_day, int nd_max_day);
string daySet(int year, int month, int day, int max_day);
string ifMonthNegative(int neg_year, int neg_month, int neg_day, int neg_max_day, int neg_leap);
string monthSet(int yearM, int monthM, int dayM, int max_dayM, int leapM);
string Date(int d, int m, int y);

int main(){
    cout<<"Introduce a date (YYYY/MM/DD)"<<endl;
    int d, m, y;
    cout<<"Day: "; cin>>d;
    cout<<"Month: "; cin>>m;
    cout<<"Year: "; cin>>y;
    cout<<"Add event in: "<<Date(d,m,y)<<": "<<endl;

    return 0;
}

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
    if (neg_month%2 != 0 || neg_month==8 || neg_month==12){
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