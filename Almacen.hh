/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/


#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_


#include "Sala.hh"
#include "Sistema.hh"


#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include "BinTree.hh"
#endif
using namespace std;


/** @class Almacen
    @brief Representa un almacén
*/


class Almacen {
private:
    /** @brief Árbol de identificadores de sala
    */
    BinTree<int> aid;
    /** @brief Vector de salas
    */
    vector<Sala> vsal;
    
    
    //Modificadoras
    /** @brief Inmersión de distribuir.
        \pre parámetro implícito inicializado, prod existe, n >= 0
        \post Se distribuye prod según la política explicada en el enunciado empezando por la sala aid.value(). Se devuelve un entero que indica cuántas unidades no se han podido distribuir. Las unidades que no se distribuyan no se guardan en el parámetro implícito.
    */
    int i_distribuir(string prod, int n, const BinTree<int>& aid);
    
    
    //Lectura y escritura
    /** @brief Se lee la estructura del almacén en preorden.
        \pre a.empty()
        \post Se lee la estructura del parámetro implícito en preorden.
    */
    void read_bintree_int(BinTree<int>& a, int marca);
public:
    //Creadoras de objetos
    /** @brief Creadora por defecto.
        \pre <em>cierto</em>
        \post El resultado es un almacén.
    */
    Almacen();
    
    
    //Modificadoras
    /** @brief Se inicializa el almacén.
        \pre parámetro implícito no inicializado, n > 0
        \post Se inicializa el parámetro implícito.
    */
    void inicializar(int n);
    
    
    /** @brief Si el producto no existe se produce un error y se devuelve -1. Se colocan tantas unidades como quepan en la sala y se devuelve un entero que indique cuántas unidades no han cabido. Se colocarán las unidades lo antes posible, es decir, primero se rellenan los huecos a partir del hueco que vaya antes. Las unidades que no quepan no se guardan en el almacén.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size(), n > 0
        \post Si prod no existe se escribe "error" y se devuelve -1. Se colocan tantas unidades como quepan en la sala y se devuelve un entero que indique cuántas unidades no han cabido. Se colocarán las unidades lo antes posible, es decir, primero se rellenan los huecos a partir del hueco que vaya antes. Las unidades que no quepan no se guardan en el parámetro implícito.
    */
    int poner_items(int id, string prod, int n, Sistema& sist);
    
    
    /** @brief Si el producto no existe se produce un error y se devuelve -1. Se quitan tantas unidades como se pueda y se devuelve un entero que indique cuántas unidades no se han podido quitar porque no había suficientes en la sala. Se comenzará quitando las unidades que vayan antes.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size(), n > 0
        \post Si prod no existe se escribe "error" y se devuelve -1. Se quitan tantas unidades como se pueda y se devuelve un entero que indique cuántas unidades no se han podido quitar porque no había suficientes en la sala. Se comenzará quitando las unidades que vayan antes.
    */
    int quitar_items(int id, string prod, int n, Sistema& sist);
    
    
    /** @brief Si el producto no existe se produce un error y se devuelve -1. Se distribuye el producto según la política explicada en el enunciado. Se devuelve un entero que indica cuántas unidades no se han podido distribuir. Las unidades que no se distribuyan no se guardan en el almacén.
        \pre parámetro implícito inicializado, n > 0
        \post Si prod no existe se escribe "error" y se devuelve -1. Se distribuye prod según la política explicada en el enunciado. Se devuelve un entero que indica cuántas unidades no se han podido distribuir. Las unidades que no se distribuyan no se guardan en el parámetro implícito.
    */
    int distribuir(string prod, int n, Sistema& sist);
    
    
    /** @brief Se compacta la estantería de la sala.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size()
        \post Se compacta la estantería de la sala.
    */
    void compactar(int id);
    
    
    /** @brief Se reorganiza la estantería de la sala.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size()
        \post Se reorganiza la estantería de la sala.
    */
    void reorganizar(int id);
    
    
    /** @brief Si los productos que hay en la sala no caben en las nuevas dimensiones se produce un error. En caso contrario se compacta la estantería y pasa a tener las nuevas dimensiones.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size(), f > 0, c > 0
        \post Si los productos que hay en la sala no caben en las nuevas dimensiones se escribe "error". En caso contrario se compacta la estantería y pasa a tener las nuevas dimensiones.
    */
    void redimensionar(int id, int f, int c);
    
    
    //Consultoras
    /** @brief Se devuelve la sala cuyo identificador es el entero.
        \pre parámetro implícito inicializado, 0 < id <= vsal.size()
        \post Se devuelve la sala cuyo identificador es id.
    */
    Sala consultar_sal(int id) const;
};
#endif
