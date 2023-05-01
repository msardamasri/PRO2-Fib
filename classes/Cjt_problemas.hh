/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas
*/

#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#endif

/** @class Cjt_problemas
    @brief Representa un conjunto de problemas. 

    Puede contener problemas. Puede usarse para hacer una sesion.
*/
class Cjt_problemas
{  
public:

    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de problemas.
      \pre <em>cierto</em>.
      \post El resultado es un conjunto de problemas (map) vacio.
  */

    Cjt_problemas();

    //Modificadoras

    /** @brief Inicializadora de valores. 

      \pre <em>cierto</em>.
      \post El resultado es un conjunto de problemas (map) inicializado con sus correspondentes valores.
  */

    void inicializar();

    /** @brief Añade un problema al conjunto
    
      \pre El parámetro implícito (cjt_problemas) está inicializado.
      \post El parámetro implícito contiene su carga original más s.
  */

    void anadir_problema(const string& s);

    /** @brief Actualiza los envios de un problema.
    
      \pre El problema con id "p" esta dentro del conjunto de problemas.
      \post El resultado es la carga original de la variable "total_envios" + 1.
  */

    void actualizar_envios(const string& p);

    /** @brief Actualiza los envios de un problema y los problemas resueltos.
    
      \pre El problema con id "p" esta dentro del conjunto de problemas.
      \post El resultado es la carga original de la variable "total_envios" + 1 y la carga original de la variable "resueltos" + 1.
  */

    void actualizar_envios_correcto(const string& p);

    /** @brief Calcula el ratio de los problemas del conjunto.
    
      \pre <em>cierto</em>.
      \post El rsultado es la actualizacion del ratio de cada problema en su parametro "ratio".
  */

    void calcular_ratio_listar();

    // Consultoras

    /** @brief Consulta el tamaño del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica el tamaño del conjunto con un entero.
  */

    int size() const;

    /** @brief Consultora si existe el problema dentro del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica si el parámetro implícito está dentro del conjunto. 
  */

    bool existe_problema(const string& p) const;

    /** @brief Consultora si existe el problema dentro del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica si el parámetro implícito está dentro del conjunto. 
  */

    // Escritura

  /** @brief Operación de listdo

      \pre <em>cierto</em>
      \post Escribe el listado contenido del parámetro implícito ordenado por el "ratio2 (t + 1)/(e + 1), por el canal estándar de salida. 
  */

    void listar_problemas()const;

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Escribe el contenido del parámetro con id == "s" por el canal estándar de salida.
  */

    void escribir_problema(const string& p) const;

private:

  /**  @brief La clase Cjt_problemas contiene un struct <em>Problema</em> con los parametros del ratio, envios y rsueltos. Tambien tiene un conjunto de problemas con la estructura de un map (id - Problema).
*/
    //struct problema
    struct Problema {
      int total_envios;
      int resueltos;
      double ratio;
    };

    //map de struct de problemas i strings(id_p)
    map<string, Problema> cjt_problemas;

    /** @brief Passar un map a vector. 

      \pre <em>cierto</em>.
      \post El resultado vector de pairs igual a m.
  */

    static void vectoritzar(const map<string, Problema>& m, vector<pair <string, Problema>>& v);

    /** @brief Operacion de comparacion. 

      \pre <em>cierto</em>.
      \post La funcion es completar la funcion sort de un vector ordenando por el ratio mayor.
  */

    static bool cmp(const pair<string, Problema>& p1, const pair<string, Problema>& p2);

    /** @brief Calcular el ratio. 

      \pre <em>cierto</em>.
      \post El resultado el ratio de un problema (envios / resueltos) en una variable de tipo double.
  */

    double calcular_ratio(const Problema& p) const;

};
#endif