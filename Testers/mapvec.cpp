#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void showMap(const map<string, vector<int>>& myMap);
void showKeys(const vector<string>& keys);

int main() {
    map<string, vector<int>> myMap;

    // Insertar valores en el map
    myMap["uno"] = {10, 20, 30};
    myMap["dos"] = {40, 50, 60};
    myMap["tres"] = {70, 80, 90};

    // Obtener y ordenar las claves
    vector<string> keys;
    for (const auto &pair : myMap) {
        keys.push_back(pair.first);
    }

    // Mostrar el map antes de eliminar
    showMap(myMap);

    int keyIndex;
    int indexToRemove;
    char c;

    do {
        // Mostrar las claves por índice
        cout << "Claves disponibles:" << endl;
        showKeys(keys);

        // Solicitar el índice de la clave y el índice del valor al usuario
        cout << "Ingrese el indice de la clave: ";
        cin >> keyIndex;
        cout << "Ingrese el indice del valor a eliminar: ";
        cin >> indexToRemove;

        // Verificar si el índice de la clave es válido
        if (keyIndex >= 0 && keyIndex < keys.size()) {
            string key = keys[keyIndex];
            auto it = myMap.find(key);

            // Verificar si el índice del valor es válido
            if (it != myMap.end() && indexToRemove >= 0 && indexToRemove < it->second.size()) {
                // Clave e índice son válidos, proceder con la eliminación
                auto &vec = it->second;
                vec.erase(vec.begin() + indexToRemove);

                // Si el vector asociado a la clave está vacío, eliminar la clave del map
                if (vec.empty()) {
                    myMap.erase(it);
                    keys.erase(keys.begin() + keyIndex); // Actualizar la lista de claves
                }

                cout << endl;
                showMap(myMap);
                cout << endl;

                // Verificar si el map está vacío
                if (myMap.empty()) {
                    cout << "Todos los valores han sido eliminados. El programa se cerrara." << endl;
                    break;
                }

                // Preguntar si desea continuar borrando
                do {
                    cout << "¿Desea continuar borrando? (y/n): ";
                    cin >> c;
                } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
            } else {
                // Entrada inválida, mostrar mensaje de error
                cout << "Indice del valor no valido. Intentelo de nuevo." << endl;
            }
        } else {
            // Entrada inválida, mostrar mensaje de error
            cout << "Indice de la clave no válido. Intentelo de nuevo." << endl;
        }
    } while (c == 'y' || c == 'Y');

    return 0;
}

void showMap(const map<string, vector<int>>& myMap) {
    cout << "Contenido del map:" << endl;
    for (const auto &pair : myMap) {
        cout << pair.first << ": ";
        for (const auto &val : pair.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void showKeys(const vector<string>& keys) {
    for (size_t i = 0; i < keys.size(); ++i) {
        cout << i << ": " << keys[i] << endl;
    }
}