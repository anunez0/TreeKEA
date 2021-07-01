/** @file Sistema.hh
    @brief Especificación de la clase Sistema
*/


#ifndef _SISTEMA_HH_
#define _SISTEMA_HH_


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;


/** @class Sistema
    @brief Representa un sistema
*/


class Sistema {
private:
    /** @brief Sistema de productos con sus unidades en el almacén
    */
    map<string, int> sist;
public:
    //Creadoras de objetos
    /** @brief Creadora por defecto.
        \pre <em>cierto</em>
        \post El resultado es un sistema.
    */
    Sistema();
    
    
    //Modificadoras
    /** @brief Si el producto ya existía se produce un error, si no el producto se da de alta en el sistema con cero unidades.
        \pre <em>cierto</em>
        \post Si prod ya existía se escribe "error", si no prod se da de alta en el parámetro implícito con cero unidades.
    */
    void poner_prod(string prod);
    
    
    /** @brief Si el producto no existe, o ya existe y quedan unidades se produce un error, si no el producto se da de baja en el sistema.
        \pre <em>cierto</em>
        \post Si prod no existe, o ya existe y quedan unidades se escribe "error", si no prod se da de baja en el parámetro implícito.
    */
    void quitar_prod(string prod);
    
    
    /** @brief Se suma el entero a las unidades del producto.
        \pre prod existe
        \post Se suma n a las unidades de prod.
    */
    void sumar_prod(string prod, int n);
    
    
    //Consultoras
    /** @brief Si el producto no existe, se produce un error y se devuelve -1. Si existe se devuelve cuántas unidades hay en total en el almacén.
        \pre <em>cierto</em>
        \post Si prod no existe, se escribe "error" y se devuelve -1. Si existe se devuelve cuántas unidades hay en total en el almacén.
    */
    int consultar_prod(string prod) const;
    
    
    //Lectura y escritura
    /** @brief Para cada producto en el sistema se escribe su identificador y la cantidad total en el almacén, ordenado por identificador de producto.
        \pre <em>cierto</em>
        \post Para cada producto en el parámetro implícito se escribe su identificador y la cantidad total en el almacén, ordenado por identificador de producto.
    */
    void inventario() const;
};
#endif
