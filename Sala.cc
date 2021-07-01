/** @file Sala.cc
    @brief Código de la clase Sala
*/


#include "Sala.hh"


Sala::Sala() {
}


void Sala::inicializar(int f, int c) {
    est = vector<vector<string> >(f, vector<string>(c));
    for (int i = 0; i < est.size(); ++i) {
        for (int j = 0; j < est[0].size(); ++j) est[i][j] = "NULL";
    }
    nprod = 0;
}


int Sala::poner_items(string prod, int n) {
    for (int i = est.size() - 1; i >= 0 and nprod < est.size()*est[0].size() and n > 0; --i) {
        for (int j = 0; j < est[0].size() and nprod < est.size()*est[0].size() and n > 0; ++j) {
            if (est[i][j] == "NULL") {
                est[i][j] = prod;
                ++inv[prod];
                ++nprod;
                --n;
            }
        }
    }
    return n;
}


int Sala::quitar_items(string prod, int n) {
    for (int i = est.size() - 1; i >= 0 and inv[prod] > 0 and n > 0; --i) {
        for (int j = 0; j < est[0].size() and inv[prod] > 0 and n > 0; ++j) {
            if (est[i][j] == prod) {
                est[i][j] = "NULL";
                --inv[prod];
                --nprod;
                --n;
            }
        }
    }
    if (inv[prod] == 0) inv.erase(prod);
    return n;
}


void Sala::compactar() {
    int n = 0;
    int k = est.size() - 1;
    int l = 0;
    for (int i = est.size() - 1; i >= 0 and n < nprod; --i) {
        for (int j = 0; j < est[0].size() and n < nprod; ++j) {
            if (est[i][j] != "NULL") {
                if (i != k or j != l) {
                    est[k][l] = est[i][j];
                    est[i][j] = "NULL";
                }
                ++n;
                ++l;
                if (l == est[0].size()) {
                    --k;
                    l = 0;
                }
            }
        }
    }
}


void Sala::reorganizar() {
    int i = est.size() - 1;
    int j = 0;
    for (map<string, int>::const_iterator it = inv.begin(); it != inv.end(); ++it) {
        for (int k = 0; k < it->second; ++k) {
            est[i][j] = it->first;
            ++j;
            if (j == est[0].size()) {
                --i;
                j = 0;
            }
        }
    }
    while (i >= 0) {
        est[i][j] = "NULL";
        ++j;
        if (j == est[0].size()) {
            --i;
            j = 0;
        }
    }
}


void Sala::redimensionar(int f, int c) {
    if (f*c < nprod) cout << "  error" << endl;
    else {
        vector<vector<string> > est(f, vector<string>(c));
        int n = 0;
        int k = est.size() - 1;
        int l = 0;
        for (int i = this->est.size() - 1; i >= 0 and n < nprod; --i) {
            for (int j = 0; j < this->est[0].size() and n < nprod; ++j) {
                if (this->est[i][j] != "NULL") {
                    est[k][l] = this->est[i][j];
                    ++n;
                    ++l;
                    if (l == est[0].size()) {
                        --k;
                        l = 0;
                    }
                }
            }
        }
        while (k >= 0) {
            est[k][l] = "NULL";
            ++l;
            if (l == est[0].size()) {
                --k;
                l = 0;
            }
        }
        this->est = est;
    }
}


string Sala::consultar_pos(int i, int j) const {
    return est[i - 1][j - 1];
}


void Sala::escribir() const {
    for (int i = 0; i < est.size(); ++i) {
        cout << ' ';
        for (int j = 0; j < est[0].size(); ++j) cout << ' ' << est[i][j];
        cout << endl;
    }
    cout << "  " << nprod << endl;
    for (map<string, int>::const_iterator it = inv.begin(); it != inv.end(); ++it) cout << "  " << it->first << ' ' << it->second << endl;
}
