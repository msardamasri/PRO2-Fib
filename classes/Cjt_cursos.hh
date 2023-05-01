/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos. 

    Puede contener cursos.
*/
class Cjt_cursos
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de cursos.
      \pre <em>cierto</em>
      \post El resultado es un conjunto de cursos (vector) vacio.
  */
    Cjt_cursos();

    //Modificadoras

    /** @brief Inicializadora de valores 

      \pre El parámetro implícito (cjt_cursos) esta creado
      \post El resultado es un conjunto de cursos inicializado con sus correspondentes cursos ordenados por su identificador-1
  */

    void inicializar(const Cjt_sesiones& cs);

    /** @brief Leer un curso. 

      \pre Las sesiones del nuevo curso existen.
      \post El resultado es un curso sin interseccion de problemas entre sus sesiones.
  */

    bool leer_nuevo_curso(const Cjt_sesiones& cjt_sesiones);

    /** @brief Anadir uno a usuarios completados de un curso.

      \pre El curso esta dentro de conjunto.
      \post Llama a un curso con id = "n" para que sume uno a usuarios completados.
  */

    void anadir_completado(const int & n);

    /** @brief Modificadora de un curso.

      \pre Tamaño del conjunto 0 < c-1 <= size del conjunto, para no acceder a una posicion errobea.
      \post Sustituye en la posicion c-1 un curso por otro modificado previamente.
  */

    void modificar_curso(const Curso& curso,const int& c);

    /** @brief Añade un curso al conjunto.
    
      \pre El parámetro implícito (cjt_cursos) está creado.
      \post El parámetro implícito contiene su carga original más un curso con "c".
  */

    void anadir_curso(const Curso& c);

    /** @brief Añade uno al numero de usuarios inscritos en un curso.
    
      \pre El curso con id = "s" esta en el conjunto.
      \post El curso contiene el numero de usuarios inscritos +1 en el curso con id = "s".
  */

    void sumar_usuario_inscrito(const int& s);

    /** @brief Resta uno al numero de usuarios inscritos en un curso.
    
      \pre El curso esta en el conjunto.
      \post El curso contiene el numero de usuarios inscritos -1 en el curso con id = "c".
  */

    void borrar_inscrito(const int& c);

    /** @brief Actualiza el conjunto de problemas enviables.

      \pre El curso con id = "c" existe.
      \post El resultado es la actualizacion de los problemas enviables de un usuario.
  */

    void act_env(const int& c, const Cjt_sesiones& cs,Problemas_usr& env, Problemas_usr& res);

    // Consultoras

    /** @brief Consulta el id de una sesion.
    
      \pre El curso esta en el conjunto.
      \post Retorna el identificador de la sesion.
  */

    string get_ids(const int& c, const string& p);

    /** @brief Consulta si un problema pertenece a un curso.

      \pre <em>cierto</em>.
      \post El resultado es un booleano que indica el problema con id = "p" pertenece al curso con id  = "c".
  */

    bool pertenece_problema(const string& p, const int& c) const;

    /** @brief Consulta el tamaño del conjunto.

      \pre El conjunto de cursos esta inicializado.
      \post El resultado indica el tamaño del vector del conjunto de cursos.
  */

    int size() const;

    /** @brief Consultora si existe un curso dentro del conjunto de cursos.

      \pre <em>cierto</em>.
      \post El resultado es un booleano que indica si el parametro con id = "s" está dentro del conjunto .
  */

    bool existe_curso(const int& s) const;
   
    // Escritura

    /** @brief Operación de escritura

      \pre El curso esta en el conjunto.
      \post Escribe el numero de usuarios inscritos en el curso con id = "s" por el canal estándar de salida.
  */

    void imprimir_inscritos(const int& s) const;

    /** @brief Operación de escritura.

      \pre El curso esta en el conjunto.
      \post Escribe la sesion en la cual esta el problema con id = "p" en el curso con id = "c" por el canal estándar de salida.
  */

    void imprimir_sesion_problema(const int& c,const string& p) const;

  /** @brief Operación de listdo

      \pre El conjunto tiene cursos.
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida. 
  */

    void listar_cursos() const;

    /** @brief Operación de escritura.

      \pre El curso esta en el conjunto.
      \post Escribe el contenido del parámetro con id = "s" por el canal estándar de salida.
  */

    void escribir_curso(const int& s) const;

private:

    /**  @brief La clase Cjt_cursos contiene un vector con los cursos.
  */

    vector<Curso> cjt_cursos;
};
#endif