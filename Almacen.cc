/** @file Almacen.cc
    @brief Código de la clase Almacen
*/


#include "Almacen.hh"


int Almacen::i_distribuir(string prod, int n, const BinTree<int>& aid) {
    if (n == 0 or aid.empty()) return n;
    n = vsal[aid.value() - 1].poner_items(prod, n);
    return i_distribuir(prod, n/2 + n%2, aid.left()) + i_distribuir(prod, n/2, aid.right());
}


void Almacen::read_bintree_int(BinTree<int>& a, int marca) {
    int x;
    cin >> x;
    if (x != marca) {
        BinTree<int> l;
        read_bintree_int(l, marca);
        BinTree<int> r;
        read_bintree_int(r, marca);
        a = BinTree<int>(x, l, r);
    }
}


Almacen::Almacen() {
}


void Almacen::inicializar(int n) {
    read_bintree_int(aid, 0);
    vsal = vector<Sala>(n);
    for (int i = 0; i < vsal.size(); ++i) {
        int f, c;
        cin >> f >> c;
        vsal[i].inicializar(f, c);
    }
}


int Almacen::poner_items(int id, string prod, int n, Sistema& sist) {
    if (sist.consultar_prod(prod) == -1) return -1;
    int x = vsal[id - 1].poner_items(prod, n);
    sist.sumar_prod(prod, n - x);
    return x;
}


int Almacen::quitar_items(int id, string prod, int n, Sistema& sist) {
    if (sist.consultar_prod(prod) == -1) return -1;
    int x = vsal[id - 1].quitar_items(prod, n);
    sist.sumar_prod(prod, x - n);
    return x;
}


int Almacen::distribuir(string prod, int n, Sistema& sist) {
    if (sist.consultar_prod(prod) == -1) return -1;
    int x = i_distribuir(prod, n, aid);
    sist.sumar_prod(prod, n - x);
    return x;
}


void Almacen::compactar(int id) {
    vsal[id - 1].compactar();
}


void Almacen::reorganizar(int id) {
    vsal[id - 1].reorganizar();
}


void Almacen::redimensionar(int id, int f, int c) {
    vsal[id - 1].redimensionar(f, c);
}


Sala Almacen::consultar_sal(int id) const {
    return vsal[id - 1];
}
