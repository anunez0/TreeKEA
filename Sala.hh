/** @file Sala.hh
    @brief Especificación de la clase Sala
*/


#ifndef _SALA_HH_
#define _SALA_HH_


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <map>
#endif
using namespace std;


/** @class Sala
    @brief Representa una sala
*/


class Sala {
private:
    /** @brief Estantería de productos
    */
    vector<vector<string> > est;
    /** @brief Inventario de productos con sus unidades en la sala
    */
    map<string, int> inv;
    /** @brief Número de productos en la sala
    */
    int nprod;
public:
    //Creadoras de objetos
    /** @brief Creadora por defecto.
        \pre <em>cierto</em>
        \post El resultado es una sala.
    */
    Sala();
    
    
    //Modificadoras
    /** @brief Se inicializa la sala.
        \pre parámetro implícito no inicializado, f > 0, c > 0
        \post Se inicializa el parámetro implícito.
    */
    void inicializar(int f, int c);
    
    
    /** @brief Se colocan tantas unidades como quepan en la sala y se devuelve un entero que indique cuántas unidades no han cabido. Se colocarán las unidades lo antes posible, es decir, primero se rellenan los huecos a partir del hueco que vaya antes. Las unidades que no quepan no se guardan en el almacén.
        \pre parámetro implícito inicializado, prod existe, n > 0
        \post Se colocan tantas unidades como quepan en el parámetro implícito y se devuelve un entero que indique cuántas unidades no han cabido. Se colocarán las unidades lo antes posible, es decir, primero se rellenan los huecos a partir del hueco que vaya antes. Las unidades que no quepan no se guardan en el almacén.
    */
    int poner_items(string prod, int n);
    
    
    /** @brief Se quitan tantas unidades como se pueda y se devuelve un entero que indique cuántas unidades no se han podido quitar porque no había suficientes en la sala. Se comenzará quitando las unidades que vayan antes.
        \pre parámetro implícito inicializado, prod existe, n > 0
        \post Se quitan tantas unidades como se pueda y se devuelve un entero que indique cuántas unidades no se han podido quitar porque no había suficientes en el parámetro implícito. Se comenzará quitando las unidades que vayan antes.
    */
    int quitar_items(string prod, int n);
    
    
    /** @brief Se compacta la estantería de la sala.
        \pre parámetro implícito inicializado
        \post Se compacta la estantería del parámetro implícito.
    */
    void compactar();
    
    
    /** @brief Se reorganiza la estantería de la sala.
        \pre parámetro implícito inicializado
        \post Se reorganiza la estantería del parámetro implícito.
    */
    void reorganizar();
    
    
    /** @brief Si los productos que hay en la sala no caben en las nuevas dimensiones se produce un error. En caso contrario se compacta la estantería y pasa a tener las nuevas dimensiones.
        \pre parámetro implícito inicializado, f > 0, c > 0
        \post Si los productos que hay en el parámetro implícito no caben en las nuevas dimensiones se escribe "error". En caso contrario se compacta la estantería y pasa a tener las nuevas dimensiones.
    */
    void redimensionar(int f, int c);
    
    
    //Consultoras
    /** @brief Se devuelve qué producto hay en la posición correspondiente de la estantería de la sala. Si no hay producto se devuelve "NULL".
        \pre parámetro implícito inicializado, 0 < i <= est.size(), 0 < j <= est[0].size()
        \post Se devuelve qué producto hay en la posición correspondiente de la estantería del parámetro implícito. Si no hay producto se devuelve "NULL".
    */
    string consultar_pos(int i, int j) const;
    
    
    //Lectura y escritura
    /** @brief Se escribe el contenido de la estantería de arriba a abajo y de izquierda a derecha. En los huecos escribiremos "NULL" y por tanto no podrá ser un identificador válido de producto. También escribiremos cuántas unidades hay en total y por orden de identificador de producto existente en la estantería, escribiremos el identificador de producto y su cantidad.
        \pre parámetro implícito inicializado
        \post Se escribe el contenido de la estantería de arriba a abajo y de izquierda a derecha. En los huecos escribiremos "NULL" y por tanto no podrá ser un identificador válido de producto. También escribiremos cuántas unidades hay en total y por orden de identificador de producto existente en la estantería, escribiremos el identificador de producto y su cantidad.
    */
    void escribir() const;
};
#endif
