/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "usuario_problemas.hh"
#include "Cjt_cursos.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class  Usuario
    @brief Representa un usuario. 

    Puede contener informacion sobre el usuario.
*/
class Usuario
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un usuario.
      \pre <em>cierto</em>
      \post El resultado es un usuario vacio.
  */

    Usuario();

    //Modificadoras

    /** @brief Modifica el curso al ques esta incrito el usuario.
    
      \pre <em>cierto</em>.
      \post La variable "curso_inscrito" = "n".
  */

    void modificar_curso(const int& n);

    /** @brief Actualiza el conjunto de problemas enviables del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es la llamada a otra funcion para actualizar el conjunto de problemas enviables con todas las sesiones, las quales pertenecen al curso al que esta inscrito el usuario.
  */

    void actualizar_enviables(Cjt_cursos& cc, const Cjt_sesiones& cs);

    /** @brief Actualiza el numero de envios del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es la carga original de la variable "envios" + 1.
  */

    void sumar_envio();

    /** @brief Actualiza el numero de intentos del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es la carga original de la variable "intentados" + 1.
  */

    void sumar_intentados();

    /** @brief Actualiza el numero de problemas resueltos del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es la carga original de la variable "resueltos" + 1.
  */

    void sumar_resueltos();

    /** @brief Actualiza el numero de intentod de un problema enviable.
    
      \pre El problema con id = "p" esta dentro del conjunto de problemas enviables.
      \post El resultado es la llamada a la clase usuario_problemas para actualizar la carga original de intentos del problema + 1.
  */

    void sumar_intentos_penviables(const string& p);

    /** @brief Actualiza los parametros de un usuario al hacer un envio.
    
      \pre <em>cierto</em>.
      \post El resultado es la carga original de la variable "envios" + 1, la carga original del problema con id = "p" del conjunto de problemas enviables + 1 en sus intentos y si no se ha intentado el problema antes se suma uno al numero de problemas intentados por el usuario.
  */

    void funcact(const string& p);

    /** @brief Actualiza el conjunto de problemas resueltos del usuario.
    
      \pre El problema con id = "p" esta dentro del conjunto de problemas enviables.
      \post El resultado es la eliminación de un problema del conjunto de enviables y se añade al conjunto de problemas resueltos del usuario.
  */

    void modificar_resueltos(const string& p);

    /** @brief Actualiza el conjunto de problemas enviables del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es la llamada a otra funcion para actualizar el conjunto de problemas enviables de una sesion a la qual pertenece el prblema que el usuario ha enviado.
  */

    void envio(const string& p,Cjt_sesiones& cs, string& s);

    //Consultoras

    /** @brief Comprueva si se el usuario ha terminado el curso.
    
      \pre <em>cierto</em>.
      \post El resultado es un booleano que indica si el usuario ha acabado el curso actual.
  */

    bool comprovacion_terminado();

    /** @brief Consulta los intento de un problema enviable.
    
      \pre <em>cierto</em>.
      \post El resultado son los intentos que lleva el usuario del problema con id = "p".
  */

    int get_enviables_intentos(const string& p);

    /** @brief Consulta los envios del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es el numero de envios del usuario.
  */

    int get_envios() const;

    /** @brief Consulta los problemas resueltos del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es el numero de problemas resueltos del usuario.
  */

    int get_resueltos() const;

    /** @brief Consulta el curso inscrito del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es el curso al que el usuario esta inscrito, si no esta inscrito en ningun curso ertorna 0.
  */

    int get_inscripcion_curso() const;

    /** @brief Consulta los problemas intentados del usuario.
    
      \pre <em>cierto</em>.
      \post El resultado es el numero de problemas intentados del usuario.
  */

    int get_intentados() const;

    //Escritura

    /** @brief Operación de escritura de problemas enviables del usuario.

      \pre <em>cierto</em>.
      \post Escribe el contenido todos los problemas enviables del usuario por el canal estandard de salida.
  */

    void imprimir_enviables() const;

    /** @brief Operación de escritura de problemas resueltos del usuario.

      \pre <em>cierto</em>.
      \post Escribe el contenido todos los problemas resueltos del usuario por el canal estandard de salida.
  */

    void imprimir_resueltos() const;

private:

    /**  @brief La clase Usuario contiene dos copnjuntos de problemas (enviables y resueltos), el total de envios realizados, los problemas resueltos, intentados y el curso al que esta inscrito (0 si no esta inscrito en un curso). 
*/

    int envios;
    int resueltos;
    int intentados;
    int curso_inscrito;
    Problemas_usr problemas_enviables;
    Problemas_usr problemas_resueltos;
};
#endif