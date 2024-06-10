#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    while (n>30){
        n--;
    }
    if(n<0){
        n = -n;
        while (n>30){
            n--;
        }
    }
    cout<<n;

    return 0;
}