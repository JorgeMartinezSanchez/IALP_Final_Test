//ALUMNO: JORGE MARTÍNEZ SÁNCHEZ
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "dateset.h"
using namespace std;

void printMap(const map<string, vector<string>>& myMap);
void addEvent(map<string, vector<string>>& myMap, string Date, string Event);
void showDatesKeys(const vector<string>& keys);

int main(){
    //variables con las que se ejecutará el programa
    map<string, vector<string>> list;
    char clause;
    int d, m, y;
    string event;
    do{
        //Menú principal
        cout<<"\nWhat do you want to do?"<<endl;
        cout<<"a) Add event"<<endl;
        cout<<"b) Delete event"<<endl;
        cout<<"c) Search event on a specific date"<<endl;
        cout<<"d) Print all events"<<endl;
        cout<<"e) Exit"<<endl;
        cin>>clause;
        cin.ignore();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (clause=='a' || clause=='A'){
            do {
                //Agregar Fecha
                cout<<endl;
                cout<<"Introduce a date (YYYY/MM/DD)"<<endl;
                cout<<"Day: "; cin>>d;
                cout<<"Month: "; cin>>m;
                cout<<"Year: "; cin>>y;
                cin.ignore();
                cout<<"\n-----------------------------------------"<<endl;

                //Agregar Evento
                cout<<"Add event in "<<Date(d,m,y)<<": "; getline(cin, event);
                addEvent(list, Date(d,m,y), event);
                cout<<endl;
                cout<<"Event added to "<<Date(d,m,y)<<" succesfully"<<endl;
                cout<<endl;

                do{
                    cout<<"Would you like to add another event? (y/n):"<<endl;
                    cin>>clause;
                    cin.ignore();
                }while(clause!='Y' && clause!='y' && clause!='N' && clause!='n'); //No parará el bucle hasta que digas no

            }while (clause=='Y' || clause=='y');
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (clause=='b' || clause=='B'){ //Opción B del menú principal
            if (list.empty()){ //Determinar si esta vacia la lista
                cout<<"\nThere's no event in this list.\n";
            }
            else {
                do{ // Menú principal de la opción B
                    //*******************************************************************************************
                    char clauseB;
                    cout<<"\nWhat you want to delete?"<<endl;
                    cout<<"a) Delete one event"<<endl;
                    cout<<"b) Delete all events from an specific date"<<endl;
                    cout<<"c) Clear the list"<<endl;
                    cout<<"d) Back"<<endl;
                    cin>>clauseB;
                    if (clauseB=='A' || clauseB=='a'){ //Inciso a del B
                        //Obter las fechas
                        vector<string> Dates;
                        for (const auto& pair : list){
                            Dates.push_back(pair.first);
                        }
                        cout<<endl;
                        printMap(list);
                        cout<<endl;
                        int DateIndex, delEvIndex;
                        char clauseBa;
                        do{
                            cout<<"\nDates aviable:"<<endl;
                            showDatesKeys(Dates);
                            cout<<"\nEnter date index: "; cin>>DateIndex;
                            cout<<"Enter event index: "; cin>>delEvIndex;
                            //Hallar el indice de la fecha en el rango de "list"
                            if (DateIndex>=0 && DateIndex<Dates.size()){
                                string key=Dates[DateIndex];
                                //auto it es igual al key elegido
                                auto it = list.find(key);
                                //Hallar el indice del elemento del vector (osea el evento)
                                if(it!=list.end() && delEvIndex>=0 && delEvIndex<it->second.size()){
                                    vector<string>& vec = it->second;
                                    vec.erase(vec.begin() + delEvIndex);
                                    //Si el vector de eventos está vació, se elimina el key
                                    if(vec.empty()){
                                        list.erase(it);
                                        Dates.erase(Dates.begin() + DateIndex);
                                    }
                                    cout<<"\nEvent deleted succesfully"<<endl;
                                    if(list.empty()){
                                        cout<<"\nThere's no events to delete anymore."<<endl;
                                        break;
                                    }
                                    do{
                                        cout<<"Do you wish to keep deleting events? (y/n)"<<endl;
                                        cin>>clauseBa;
                                    }while(clauseBa!='y' && clauseBa!='Y' && clauseBa!='n' && clauseBa!='N');
                                } else {
                                    cout<<"\nInvalid value index output."<<endl;
                                }
                            } else {
                                cout<<"\nInvalid key index output."<<endl;
                            }
                        }while(clauseBa=='y' || clauseBa=='Y');
                    }
                    //**************************************************************************************
                    else if (clauseB=='B' || clauseB=='b'){ //Inciso b del B
                        vector<string> Dates;
                        for (const auto& pair : list){
                            Dates.push_back(pair.first);
                        }
                        cout<<endl;
                        showDatesKeys(Dates);
                        cout<<endl;
                        int DateIndex;
                        char clauseBb;
                        do{
                            cout<<"Select date by its index: "; cin>>DateIndex;
                            if(DateIndex>=0 && DateIndex<Dates.size()){
                                string key = Dates[DateIndex];
                                auto it = list.find(key);
                                //Borrar el key
                                list.erase(it);
                                if(list.empty()){
                                    cout<<"\nThere's no events to delete anymore."<<endl;
                                    break;
                                }
                                do{
                                    cout<<"Do you wish keep deleting events? (y/n)"<<endl;
                                    cin>>clauseBb;
                                }while(clauseBb!='y' && clauseBb!='Y' && clauseBb!='n' && clauseBb!='N');
                            } else {
                                cout<<"\nInvalid key index output."<<endl;
                            }
                        }while(clauseBb=='y' || clauseBb=='Y');
                    }
                    else if (clauseB=='C' || clauseB=='c'){ //Inciso c del B
                        list.clear();
                        cout<<"\nSuccesfully Cleared\n";
                        break;
                    }
                    else if (clauseB=='D' || clauseB=='d'){
                        break;
                    }
                    else{
                        cout<<"\nNot an option. ";
                    }
                } while(true);
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (clause=='c' || clause=='C'){
            int dC, mC, yC;
            cout<<"\nIntroduce the date"<<endl;
            cout<<"Day: "; cin>>dC;
            cout<<"Month: "; cin>>mC;
            cout<<"Year: "; cin>>yC;
            string searchingD = Date(dC, mC, yC);
            auto it = list.find(searchingD);
            if (it != list.end()){
                cout<<endl;
                cout<<it->first<<": ";
                for(size_t i=0; i<it->second.size(); i++){
                    cout<<"["<<it->second[i]<<"] ";
                }
                cout<<endl;
            } else {
                cout<<"\nDate not found."<<endl;
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (clause=='d' || clause=='D'){
            if (!list.empty()){
                cout<<endl;
                printMap(list);
                cout<<endl;
            }
            else {
                cout<<"\nThere's no event in this list.\n";
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (clause=='e' || clause=='E'){
            break; //Se sale del programa
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else{ //No elige ninguno de los incisos propuestos
            cout<<"\nNot an option.";
        }
    } while (true);

    return 0;
}

void addEvent(map<string, vector<string>>& myMap, string Date, string Event) {
    myMap[Date].push_back(Event);
}

void printMap(const map<string, vector<string>>& myMap) {
    for (const auto& element : myMap) {
        cout<<element.first<<": ";
        for (const string& value : element.second) {
            cout<<"["<<value<<"] ";
        }
        cout<<endl;
    }
}

void showDatesKeys(const vector<string>& keys) {
    for (size_t i=0; i<keys.size(); ++i) {
        cout<<i<<": "<<keys[i]<< endl;
    }
}