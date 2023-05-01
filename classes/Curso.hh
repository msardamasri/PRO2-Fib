/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Curso
    @brief Representa un curso. 

    Puede contener sesiones.
*/
class Curso
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un curso.
      \pre <em>cierto</em>
      \post El resultado es un curso (vector) vacio.
  */

    Curso();

    //Modificadoras

    /** @brief Añadir uno a usuarios completados.

      \pre Existe el curso.
      \post El resultado es  el parametro original "usuarios completados" + 1.
  */

    void anadir_completado();

    /** @brief Leer un curso. 

      \pre Existe el curso.
      \post El resultado es un curso (vector) con los strings de las sesiones y un map de strings con los identificadores de problemas y sesiones.
  */

    void leer_curso(const Cjt_sesiones& cs);

    /** @brief Leer un nuevo curso. 

      \pre Existe el curso.
      \post El resultado es un curso (vector) con los strings de las sesiones y un map de strings con los identificadores de problemas y sesiones, se pasa un booleano por referencia que indica si hay interseccion de problemas entre las sesiones. 
  */

    void leer_curso_n(const Cjt_sesiones& cs, bool& interseccion);

    /** @brief Borra uno a los usuarios inscritos. 

      \pre Existe el curso.
      \post El resultado es el parametro original "usuarios inscritos" - 1.
  */

    void borrar_insc();

    /** @brief Suma uno a los usuarios inscritos. 

      \pre Existe el curso.
      \post El resultado es el parametro original "usuarios inscritos" + 1.
  */

    void sumar_inscrito();

    /** @brief Atualizar los problemas enviables. 

      \pre <em>cierto</em>.
      \post Para cada sesion del curso llama al conjunto de sesiones pasandoles los problemas resueltos y enviables de cada usuario para que sean actualizados.
  */
    
    void act_env(const Cjt_sesiones& cs,Problemas_usr& env, Problemas_usr& res);

    // Consultoras

    /** @brief Consultora si hay problemas repetidos entres las sesiones.

      \pre <em>cierto</em>.
      \post El resultado indica si hay problemas con repetidos en diferentes sesiones del mismo curso.
  */

    bool interseccion_problemas_n(const int& n) const;

    /** @brief Consultora de los usuarios completados. 

      \pre <em>cierto</em>.
      \post El resultado es el numero de usuarios completados del curso.
  */

    int get_usuarios_completados() const;

    /** @brief Consultora de los usuarios inscritos. 

      \pre <em>cierto</em>.
      \post El resultado es el numero de usuarios inscirtos en el curso.
  */

    int get_usuarios_inscritos() const;

    /** @brief Consulta el vector de las sesiones. 

      \pre El curso no esta vacio.
      \post El resultado es el vector con la sesiones pasado por referencia.
  */

    void get_vsesiones(vector<string> & v);

    /** @brief Consulta el tamaño del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica el tamaño del conjunto con un entero.
  */

    int size() const;

    /** @brief Consulta el id de una sesion. 

      \pre El curso tiene como mínimo n + 1 elementos.
      \post El resultado es el id de una sesion en la posicion n.
  */

    string get_sesionid(const int& n) const;

    /** @brief Consulta el id de una sesion. 

      \pre El curso tiene una sesion con un problema con id = "p".
      \post El resultado es el id de una sesion la qual contiene el problema con id = "p".
  */

    string get_sesionpsid(const string& p) const;

    /** @brief Consulta si el problema con id = "p" esta dentro del curso. 

      \pre <em>cierto</em>.
      \post El resultado indica si el problema con id = "p" esta dentro del curso.
  */

    bool pertenece_problema(const string& p) const;

    //Escritura

    /** @brief Escribir un curso. 

      \pre <em>cierto</em>.
      \post Escribe el contenido de un curso por el canal estandard de salida.
  */

    void escribir_c() const;

private:

    /**  @brief La clase Curso contiene un vector con las sesiones, un map con todos los problemas y sesiones (id_p - id_s), y dos variables enteras, una para los usuarios completados y otra para los inscritos.
  */

    vector<string> curso;

    int usuarios_completados;
    int usuarios_inscritos;

    map <string, string> problemas_sesiones;
};
#endif