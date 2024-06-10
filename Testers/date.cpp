#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Funcion para introducir fecha
void Date(int d, int m, int y){
    int max_day;
    if (m<=12){
		if (m%2 != 0){
	    	max_day = 31;
            while (d>max_day){
                d--;
            }
            if (d==0){
                d + 1;
            }
            else if (d<0){
                d * -1;
                while (d>max_day){
                d--;
                }
            }
		}
		else if (m==2){
			if (y%4 == 0){
				d = 29;
				cout<<d;
		} 	else {
				d = 28;
				cout<<d;
			}
		}
		else {
			d = 30;
			cout<<d;
		}
	}
	else if (m<1){
		if(m==0){
            m + 1;
        }
        else if(m<0){
            m * -1;
            if (m>12){
		        if (m%2 != 0){
	    	    d = 31;
	            cout<<d;
		        }
		        else if (m==2){
			        if (y%4 == 0){
				        d = 29;
				        cout<<d;
		            } 	else {
				        d = 28;
				        cout<<d;
			        }
		        }
		        else {
			        d = 30;
			        cout<<d;
		        }
	        }
        }
	}
	else {
		cout<<"There's no more than 12 mounths.";
	}
}
int main(){
    int d, m, y;
    cin>>d>>m>>y;
    Date(d,m,y);

    return 0;
}