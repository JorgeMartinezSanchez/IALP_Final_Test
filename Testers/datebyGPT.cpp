#include <iostream>
#include <string>
using namespace std;

string ifDayNegative(int nd_year, int nd_month, int nd_day, int nd_max_day);
string daySet(int year, int month, int day, int max_day);
string ifMonthNegative(int neg_year, int neg_month, int neg_day, int neg_max_day, int leap);
string monthSet(int yearM, int monthM, int dayM, int max_dayM, int leapM);
string Date(int d, int m, int y);

string ifDayNegative(int nd_year, int nd_month, int nd_day, int nd_max_day){
    nd_day = nd_max_day + nd_day + 1;  // Adjust for negative days
    return to_string(nd_year) + "-" + to_string(nd_month) + "-" + to_string(nd_day);
}

string daySet(int year, int month, int day, int max_day){ // Function to adjust the day
    if(day < 0){
        return ifDayNegative(year, month, day, max_day);
    }
    while (day > max_day){
        day--;
    }
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
}

string ifMonthNegative(int neg_year, int neg_month, int neg_day, int neg_max_day, int leap){
    neg_month = 12 + (neg_month % 12);  // Convert negative month to positive equivalent
    if (neg_month == 2) {
        neg_max_day = leap;
    } else if (neg_month == 4 || neg_month == 6 || neg_month == 9 || neg_month == 11) {
        neg_max_day = 30;
    } else {
        neg_max_day = 31;
    }
    return daySet(neg_year, neg_month, neg_day, neg_max_day);
}

string monthSet(int yearM, int monthM, int dayM, int max_dayM, int leapM){
    if(monthM < 0){
        return ifMonthNegative(yearM, monthM, dayM, max_dayM, leapM);
    }
    while (monthM > 12){
        monthM--;
    }
    if (monthM == 2) {
        max_dayM = leapM;
    } else if (monthM == 4 || monthM == 6 || monthM == 9 || monthM == 11) {
        max_dayM = 30;
    } else {
        max_dayM = 31;
    }
    return daySet(yearM, monthM, dayM, max_dayM);
}

//******************************************************************************************************************
string Date(int d, int m, int y){ // Main function
    int max_day = 0;
    int leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    if (y < 0){
        y = -y;
        leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    }
    return monthSet(y, m, d, max_day, leap);
}

int main(){
    cout<<"Introduce a date (YYYY/MM/DD)"<<endl;
    int d, m, y;
    cout<<"Day: "; cin>>d;
    cout<<"Month: "; cin>>m;
    cout<<"Year: "; cin>>y;
    cout<<"Add event in: "<<Date(d,m,y)<<": "<<endl;

    return 0;
}
