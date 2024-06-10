#include <iostream>

using namespace std;

int main (){
	
	int day;
	int mounth;
	int year;
	
	cout<<"Mounth: "; cin>>mounth;
	cout<<"Year: "; cin>>year;
	
	if (mounth<=12){
			if (mounth%2 != 0){
	        	day = 31;
		        cout<<day;
			}
			else if (mounth==2){
				if (year%4 == 0){
					day = 29;
					cout<<day;
			} 	else {
					day = 28;
					cout<<day;
				}
			}
			else {
				day = 30;
				cout<<day;
			}
	}
	else if (mounth<1){
		cout<<"There's no a 0 or negative mounths.";
	}
	else {
		cout<<"There's no more than 12 mounths.";
	}
	
	return 0;
}
