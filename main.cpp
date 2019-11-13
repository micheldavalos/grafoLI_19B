#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
/*    pair<size_t, size_t> punto(0, 1);
//    punto.first = 0;
//    punto.second = 1;

//    cout << "Punto: (" << punto.first << ", "
//         << punto.second << ")" << endl;
*/
/*    vector<pair<size_t, size_t>> puntos;
    string op;

    while (true) {
        cout << "1) Agregar Punto" << endl;
        cout << "2) Mostrar Puntos" << endl;
        cout << "3) Ordenar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            size_t x, y;

            cout << "x: ";
            cin >> x;

            cout << "y: ";
            cin >> y; cin.ignore();

            pair<size_t, size_t> punto(x, y);

            puntos.push_back(punto);
        }
        else if (op == "2") {
            if (puntos.size() > 0) {
                cout << "[";
                for(const auto &punto: puntos) {
                    cout << "(" << punto.first
                         << ", " << punto.second
                         << "), ";
                }
                cout << "\b\b]" << endl;

            }
            else {
                cout << "Está vacío" << endl;
            }
        }
        else if (op == "3") {
            sort(puntos.begin(), puntos.end(),
                 []
                 (const pair<size_t, size_t> &p1,
                  const pair<size_t, size_t> &p2)
                 {
                return p1.first < p2.first;
                 });
        }
        else if (op == "0") {
            break;
        }

    } */

/*    map<string, vector<string> > grafo;

    grafo["A"] = {"B", "C", "Z"};
    grafo["B"] = {"A", "C"};
    grafo["C"] = {"A", "B"};
    grafo["Z"] = {"A"};

    for (auto it = grafo.begin();
         it != grafo.end(); it++) {
        cout << (*it).first << " -> ";
        cout << "[";
        for(const auto &nodo: (*it).second) {
            cout << nodo << ", ";
        }
        cout << "\b\b]" << endl;
    }*/

    map<string, vector<string>> grafo;
    string op;

    while (true) {
        cout << "1) Agregar Arista" << endl;
        cout << "2) Mostrar Grafo" << endl;
        cout << "3) Eliminar arista" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            string origen, destino;

            cout << "Origen: ";
            getline(cin, origen);

            cout << "Destino: ";
            getline(cin, destino);

            if (grafo.count(origen)) {
                vector<string> &adyacente =
                        grafo[origen];
                adyacente.push_back(destino);
            }
            else {
                grafo[origen] = {destino};
            }

            if (grafo.count(destino)) {
                auto &adyacente = grafo[destino];
                adyacente.push_back(origen);

                //grafo[destino].push_back(destino);
            }
            else {
                grafo[destino] = {origen};
            }
        }
        else if (op == "2") {
            if (grafo.size() == 0) {
                cout << "Grafo vacío" << endl;
            }
            else {
                for (auto it = grafo.begin();
                     it != grafo.end(); it++) {
                    cout << (*it).first << " -> ";
                    cout << "[";
                    for(const auto &nodo: (*it).second) {
                        cout << nodo << ", ";
                    }
                    cout << "\b\b]" << endl;
                }
            }
        }
        else if (op == "3") {
            string origen, destino;

            cout << "Origen: ";
            getline(cin, origen);

            cout << "Destino: ";
            getline(cin, destino);

            if (grafo.count(origen) &&
                    grafo.count(destino)) {
                auto &ady_origen = grafo[origen];
                auto &ady_destino = grafo[destino];

                auto it1 = find(ady_origen.begin(),
                     ady_origen.end(), destino);

                auto it2 = find(ady_destino.begin(),
                                ady_destino.end(),
                                origen);

                if (it1 != ady_origen.end() &&
                        it2 != ady_destino.end()) {
                    ady_origen.erase(it1);
                    ady_destino.erase(it2);

                    if (grafo[origen].size() == 0) {
                        grafo.erase(origen);
                    }
                    if (grafo[destino].size() == 0) {
                        grafo.erase(destino);
                    }
                }
                else {
                    cout << "No existe la arista" <<
                            origen << "->" << destino <<
                            endl;
                }

            } else {
                cout << "No existe la arista" << endl;
            }

        }
        else if (op == "0") {
            break;
        }






    }


    return 0;
}
