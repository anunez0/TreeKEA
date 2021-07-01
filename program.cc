/** @mainpage TreeKEA
    En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar un almacén. Se introducen las clases <em>Almacen</em>, <em>Sala</em> y <em>Sistema</em>.
*/


/** @file program.cc
    @brief Programa principal para el ejercicio <em>TreeKEA</em>
*/


#include "Almacen.hh"
#include "Sala.hh"
#include "Sistema.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;


/** @brief Programa principal para el ejercicio <em>TreeKEA</em>
*/


int main() {
    Almacen alm;
    Sistema sist;
    int n, id, f, c, i, j;
    string op, prod;
    cin >> n;
    alm.inicializar(n);
    cin >> op;
    while (op != "fin") {
        if (op == "poner_prod") {
            cin >> prod;
            cout << op << ' ' << prod << endl;
            sist.poner_prod(prod);
        } else if (op == "quitar_prod") {
            cin >> prod;
            cout << op << ' ' << prod << endl;
            sist.quitar_prod(prod);
        } else if (op == "poner_items") {
            cin >> id >> prod >> n;
            cout << op << ' ' << id << ' ' << prod << ' ' << n << endl;
            n = alm.poner_items(id, prod, n, sist);
            if (n != -1) cout << "  " << n << endl;
        } else if (op == "quitar_items") {
            cin >> id >> prod >> n;
            cout << op << ' ' << id << ' ' << prod << ' ' << n << endl;
            n = alm.quitar_items(id, prod, n, sist);
            if (n != -1) cout << "  " << n << endl;
        } else if (op == "distribuir") {
            cin >> prod >> n;
            cout << op << ' ' << prod << ' ' << n << endl;
            n = alm.distribuir(prod, n, sist);
            if (n != -1) cout << "  " << n << endl;
        } else if (op == "compactar") {
            cin >> id;
            cout << op << ' ' << id << endl;
            alm.compactar(id);
        } else if (op == "reorganizar") {
            cin >> id;
            cout << op << ' ' << id << endl;
            alm.reorganizar(id);
        } else if (op == "redimensionar") {
            cin >> id >> f >> c;
            cout << op << ' ' << id << ' ' << f << ' ' << c << endl;
            alm.redimensionar(id, f, c);
        } else if (op == "inventario") {
            cout << op << endl;
            sist.inventario();
        } else if (op == "escribir") {
            cin >> id;
            cout << op << ' ' << id << endl;
            alm.consultar_sal(id).escribir();
        } else if (op == "consultar_pos") {
            cin >> id >> i >> j;
            cout << op << ' ' << id << ' ' << i << ' ' << j << endl;
            prod = alm.consultar_sal(id).consultar_pos(i, j);
            cout << "  " << prod << endl;
        } else if (op == "consultar_prod") {
            cin >> prod;
            cout << op << ' ' << prod << endl;
            n = sist.consultar_prod(prod);
            if (n != -1) cout << "  " << n << endl;
        }
        cin >> op;
    }
    cout << op << endl;
}
