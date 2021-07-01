/** @file Sistema.cc
    @brief Código de la clase Sistema
*/


#include "Sistema.hh"


Sistema::Sistema() {
}


void Sistema::poner_prod(string prod) {
    if (sist.find(prod) != sist.end()) cout << "  error" << endl;
    else sist[prod];
}


void Sistema::quitar_prod(string prod) {
    if (sist.find(prod) == sist.end() or sist[prod] > 0) cout << "  error" << endl;
    else sist.erase(prod);
}


void Sistema::sumar_prod(string prod, int n) {
    sist[prod] += n;
}


int Sistema::consultar_prod(string prod) const {
    map<string, int>::const_iterator it = sist.find(prod);
    if (it == sist.end()) {
        cout << "  error" << endl;
        return -1;
    }
    return it->second;
}


void Sistema::inventario() const {
    for (map<string, int>::const_iterator it = sist.begin(); it != sist.end(); ++it) cout << "  " << it->first << ' ' << it->second << endl;
}
