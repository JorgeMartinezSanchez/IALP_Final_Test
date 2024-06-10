#include <iostream>
#include <string>
using namespace std;

string Fun1(){
    return "Hello world";
}

string Fun2(){
    return Fun1();
}

int main(){
    cout<<Fun2();

    return 0;
}