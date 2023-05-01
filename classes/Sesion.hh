/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "usuario_problemas.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
using namespace std;
#endif

/** @class Sesion
    @brief Representa una sesion. 

    Puede contener problemas. Puede usarse para hacer un curso.
*/
class Sesion
{
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una sesion.
      \pre <em>cierto</em>
      \post El resultado es una sesion (BinTree) vacia.
  */

  Sesion();

  //Modificadoras

  /** @brief Leer una sesion. 

      \pre <em>cierto</em> no vacia
      \post El resultado es una sesion (BinTree) en preorden.
  */

  void leer_sesion();

  /** @brief Actualizar los problemas enviables.

      \pre <em>cierto</em>.
      \post Llama a la funcion de actualizacion recursiva.
  */

  void actualizar_problemas(Problemas_usr& env,const  Problemas_usr& res) const;

  /** @brief Actualizar los problemas enviables a partir de un problema.

      \pre <em>cierto</em>.
      \post Llama a la funcion de actualizacion recursiva.
  */

  void envio(const string& p, Problemas_usr& env, const Problemas_usr& res) const;
  
  //Consultoras

  /** @brief Consulta el numero de problemas de una sesion. 

      \pre <em>cierto</em>.
      \post El resultado es el numero de problemas de una sesion en un entero.
  */

  int get_numero_problemas() const;

  /** @brief Posicion "j" del vector de problemas. 

      \pre La posicion "j" esta dentro del vector de problemas.
      \post El resultado es el id del problema que esta en la posicion jessima del vector.
  */

  string id_posicio_j(const int& j) const;

  //Escritura

  /** @brief Listar los problemas de un sesion. 

      \pre <em>cierto</em>.
      \post Se llama a la funcion de imprimir problemas.
  */

  void escribir_s() const;


private:

 /**  @brief La clase Sesion contiene un BinTree y un vector con los problemas de la sesion y una variable con el numero de problemas. 
*/

  BinTree<string> sesion;
  vector<string> vsesion;
  int numero_problemas;

  /** @brief Leer una sesion. 

      \pre <em>cierto</em>.
      \post El resultado es una sesion (BinTree) en preorden, un vector con los problemas y un parametro con el numero total de problemas.
  */

  void i_leer_preorden(BinTree<string>& a);

  /** @brief Listar los problemas de un sesion. 

      \pre <em>cierto</em>.
      \post Se escriben los problemas de una sesion en postorden que se llama recursivamente por el canal estandard de salida.
  */

  static void i_imprimir_problemas(const BinTree<string>& a);

  /** @brief Actualizar los problemas enviables.

      \pre <em>cierto</em>.
      \post El resultado es la actualizacion de los problemas enviables a partir de los resueltos.
  */

  static void i_actualizar_recursivo(const BinTree<string>& a, Problemas_usr& env,const Problemas_usr& res);

  /** @brief Actualizar los problemas enviables a partir de un problema.

      \pre <em>cierto</em>.
      \post El resultado es la actualizacion de los problemas enviables a partir de los resueltos, no se actualiza recursivamente hasta llegar a un problema con id = "p".
  */

  static void i_envio_recursivo(const string& p, const BinTree<string>& a, Problemas_usr& env,const Problemas_usr& res);

};
#endif