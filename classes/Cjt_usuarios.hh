/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios
*/

#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_

#include "Usuario.hh"
#include "Cjt_cursos.hh"
#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios. 

    Puede contener usuarios.
*/
class Cjt_usuarios
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de usuarios.
      \pre <em>cierto</em>.
      \post El resultado es un conjunto de usuarios (map) vacio.
  */
    Cjt_usuarios();

    //Modificadoras

    /** @brief Inicializadora de valores. 

      \pre <em>cierto</em>
      \post El resultado es un conjunto de sesiones (map) inicializado con sus correspondentes valores.
  */

    void inicializar();
    
    /** @brief Actualiza un usuario si hace un envio 

      \pre <em>cierto</em>,
      \post El resultado es que un usuario con id = "u" se le han actualizado los parametros correspondientes al envio (puede ser envio correcto o incorrecto).
  */

    void nuevo_envio(const string& u, const string& p);

    /** @brief Actualizar el conjunto de problemas enviables de un usuario y comprobar si ha terminado el curso. 

      \pre <em>cierto</em>.
      \post El resultado es la llamada correspondiente al usuario para que actualliza el conjunto de problemas resueltos y enviables, se mira si el usuario ha acabado el curso y en ese caso modifica los parametros correspondientes en el conjunto de cursos y en usuario.
  */

    void actualizar_resueltos_enviables(const string& u, const string& p, Cjt_cursos& cc, Cjt_sesiones& cs);
//
    /** @brief Actualizar el conjunto de problemas enviables de un usuario.

      \pre <em>cierto</em>.
      \post El resultado es la llamada correspondiente al usuario para que actualliza el conjunto de problemas resueltos y enviables.
  */

    void actualizar_enviables(const string& u, Cjt_cursos& cc, const Cjt_sesiones& cs);

    /** @brief  Inscripcion de un usuario de un curso. 

      \pre El usuario con id = "u" esta dentro del conjuto.
      \post El resultado es que un usuario con id = "u" se ha inscrito a curso con id = "n".
  */

    void inscribir_curso(const string& u,const int& n) ;

    /** @brief  Borra un usuario del conjuntos

      \pre El usuario con id = "u" esta dentro del conjuto.
      \post El resultado es que un usuario con id = "u" ha sido borrado del conjunto de usuarios.
  */

    void borrar_usuario(const string& u);

    /** @brief Añadir un usuario.

      \pre <em>cierto</em>.
      \post El parámetro implícito contiene su carga original más un usuario con id = "u".
  */

    void anadir_usuario(const string& u);

    // Consultoras

    /** @brief Consulta el tamaño del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica el tamaño del conjunto con un entero.
  */

    int size() const;

    /** @brief Consultora del curso al que esta inscirto un usuario

      \pre <em>cierto</em>.
      \post El resultado indica el curso al qual el usuario con id = "s" es ta inscirto, si no lo esta el resultado es 0.
  */

    int inscripcion_curso(const string& u) const;

    /** @brief Consultora si existe el usuario dentro del conjunto.

      \pre <em>cierto</em>.
      \post El resultado indica si el parámetro implícito está dentro del conjunto.
  */

    bool existe_usuario(const string& u)const;

    // Escritura

  /** @brief Operación de listdo.

      \pre <em>cierto</em>.
      \post Escribe el contenido del parámetro implícito por el canal estándar de salida. 
  */

    void listar_usuarios() const;

    /** @brief Operación de escritura de un usuario.

      \pre <em>cierto</em>.
      \post Escribe el contenido del parámetro con id == "s" por el canal estándar de salida 
  */

    void escribir_usuario(const string& u)const;

    /** @brief Operación de escritura de problemas enviables de un usuario.

      \pre El usuario con id = "u" esta en el conjunto.
      \post Escribe el contenido todos los problemas enviables por el usuario por el canal estandard de salida.
  */

    void imprimir_enviables(const string& u)const;

    /** @brief Operación de escritura del total de envios de un usuario.

      \pre <em>cierto</em>.
      \post Escribe el total de envios realizados por un usuario.
  */

    void imprimir_envios(const string& u)const;

    /** @brief Operación de escritura de problemas resueltos de un usuario.

      \pre El usuario con id = "u" esta en el conjunto.
      \post Escribe el contenido todos los problemas resueltos por el usuario por el canal estandard de salida.
  */

    void imprimir_resueltos(const string& u) const;   
  
private:

    /**  @brief La clase Cjt_usuario contiene un conjunto de usuario con la estructura de un map (id - Usuraio).
*/
    map<string, Usuario> cjt_usuarios;
};
#endif