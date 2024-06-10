#include <iostream>
#include <map>
using namespace std;
int main(){
    map<int, char> myMap = {
      {7, 'a'},
      {5, 'e'},
      {4, 'q'}
    };

    for (auto i=myMap.begin(); i != myMap.end(); ++i){
        cout<<(*i).first<<endl;
    }

    return 0;
}