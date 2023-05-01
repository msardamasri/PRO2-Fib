/** @file usuario_problemas.hh
    @brief Especificación de la clase usuario_problemas
*/

#ifndef _USUARIO_PROBLEMAS_HH_
#define _USUARIO_PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#endif

/** @class usuario_problemas
    @brief Representa un conjunto de problemas. 

    Puede contener problemas.
*/

class Problemas_usr
{
public:

    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de problemas de un usuario.
      \pre <em>cierto</em>.
      \post El resultado es un conjunto de problemas y sus intentos (map) vacio.
  */

    Problemas_usr();

    //Modificadoras

    /** @brief Añadir un problema al conjunto.

      \pre <em>cierto</em>.
      \post El resultado es el parmetro implicito + s y 0 intentos.
  */

    void anadir_problema(const string& s);

    /** @brief Añadir un pair al conjunto.

      \pre <em>cierto</em>.
      \post El resultado es el parmetro implicito par.
  */

    void anadir_pair(const pair<string, int>& par);

    /** @brief Suma uno a los intentos de un problema. 

      \pre El problema con id = "p" esta dentro del conjunto.
      \post El resultado son los intentos iniciales + 1.
  */

    void sumar_intento(const string& p);

     /** @brief Elimina un problema del conjunto. 

      \pre El problema con id = "p" esta dentro del conjunto.
      \post El resultado son los problemas iniciales menos el problema con id = "p".
  */

    void borrar_problema(const string& p);

    //Consultoras

    /** @brief Consultora si el conjunto esta vacio.

      \pre <em>cierto</em>.
      \post El resultado indica si el conjunto esta vacio. 
  */

    bool vacio();

    /** @brief Consultora si existe el problema dentro del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica si el parámetro implícito con id = "p" está dentro del conjunto. 
  */

    bool existe_problema(const string& p) const;

    /** @brief Consultora de un pair.

      \pre El problema con id = "p" esta dentro del conjunto.
      \post Pasa por referencia el pair del problema con id = "p". 
  */

    void get_pair(const string& p, pair<string, int>& par)const;

    /** @brief Consulta el tamaño del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica el tamaño del conjunto con un entero.
  */

    int get_tam();

    /** @brief Consulta los intentos de un problema.

      \pre El problema con id = "p" esta dentro del conjunto.
      \post El resultado es el numero de veces que se ha intentado ese problema.
  */

    int get_intentos(const string& p);

    //Escritura

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro con id == "p" por el canal estándar de salida.
  */

    void escribir_problema(const string& p) const;

    /** @brief Operación de listdo

      \pre <em>cierto</em>
      \post Escribe el listado contenido del parámetro implícito por el canal estándar de salida. 
  */

    void listar() const;

private:

    /**  @brief La clase usuario_problemas contiene una variable size y un conjunto de problemas con la estructura de un map (id_problema - intentos).
*/

    int tam;
    map<string, int> problemas_usr;

};
#endif