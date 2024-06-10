#include <iostream>
using namespace std;

int main() {
    char c;
    do {
        cout<<"Choose a or b"<<endl;
        cin>>c;
        if (c=='a') {
            cout<<"You selected \"a\"";
            break;
        }
        else if (c=='b') {
            cout<<"You selected \"b\"";
            break;
        }
        else {
            cout<<"Incorrect. ";
        }
    } while (true);

    return 0;
}
