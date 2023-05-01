/** @file Cjt_sesiones.hh
    @brief Especificación de la clase Cjt_sesiones
*/

#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_sesiones
    @brief Representa un conjunto de sesiones. 

    Puede contener sesiones. Puede usarse para hacer un curso.
*/
class Cjt_sesiones
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de sesiones.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de sesiones (map) vacio.
  */
    Cjt_sesiones();

    //Modificadoras

    /** @brief Inicializadora de valores 

      \pre <em>cierto</em>
      \post El resultado es un conjunto de sesiones (map) inicializado con sus correspondentes valores.
  */

    void inicializar();

    /** @brief Añade una sesion al conjunto.
    
      \pre El parámetro implícito (cjt_sesiones) está inicializado.
      \post El parámetro implícito contiene su carga original más s. 
  */

    void anadir_sesion(const string& n, const Sesion& s);

    /** @brief Actualiza el conjunto de problemas enviables.

      \pre La sesion s existe.
      \post El resultado es la actualizacion de los problemas enviables de un usuario a partir de todas las sesiones del conjunto.
  */

    void actualizar_enviables(string& s, Problemas_usr& env, Problemas_usr& res) const;

    /** @brief Actualiza el conjunto de problemas enviables.

      \pre La sesion s existe y contiene el problema p.
      \post El resultado es la actualizacion de los problemas enviables de un usuario a partir de una sesion del conjunto.
  */

    void envio(const string& p, const string& s, Problemas_usr& env, Problemas_usr& res) const;

    // Consultoras
    
    /** @brief Consulta el tamaño del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica el tamaño del conjunto con un entero.
  */

    int size() const;
    
    /** @brief Consultora si existe la sesion dentro del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica si el parámetro implícito está dentro del conjunto. 
  */

    bool existe_sesion(const string& n) const;

    /** @brief Consulta un problema dentro de una sesion.

      \pre La sesion s existe.
      \post El resultado es la id de un problema dentro de la sesion en la posicion jessima. 
  */

    string id_posicio_j(const string& s, const int& j) const;

    /** @brief Consulta el numero de problemas dentro de una sesion.

      \pre La sesion s existe.
      \post El resultado es el numero de problemas de la sesion s. 
  */

    int get_numero_problemas(const string& s) const;

    // Escritura

  /** @brief Operación de listdo

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida. 
  */

    void listar_sesiones() const;

    /** @brief Operación de escritura

      \pre La sesion con id = "s" existe.
      \post Escribe el contenido del parámetro con id = "s" por el canal estándar de salida. 
  */

    void escribir_sesion(const string& s)const;


private:

    /**  @brief La clase Cjt_sesiones contiene un conjunto de Sesiones con la estructura de un map (id - Sesion).
  */
    map<string, Sesion> cjt_sesiones;
};
#endif