#include "Usuario.hh"
using namespace std;

Usuario::Usuario() {
    envios = 0;
    resueltos = 0;
    intentados = 0;
    curso_inscrito = 0;
}

int Usuario::get_envios()const{
    return this -> envios;
}

int Usuario::get_resueltos() const{
    return this -> resueltos;
}

int Usuario::get_intentados() const{
    return this -> intentados;
}

int Usuario::get_inscripcion_curso() const {
    return this -> curso_inscrito;
}

void Usuario::modificar_curso(const int& n){
    this -> curso_inscrito = n;
}

void Usuario::modificar_resueltos(const string& p){
    sumar_resueltos();
    pair<string, int> par;
    this -> problemas_enviables.get_pair(p, par);
    this -> problemas_enviables.borrar_problema(p);
    this -> problemas_resueltos.anadir_pair(par);
}

bool Usuario::comprovacion_terminado(){
    return problemas_enviables.vacio();
}

void Usuario::envio(const string& p, Cjt_sesiones& cs, string& s) {
    cs.envio(p,s, this -> problemas_enviables, this -> problemas_resueltos);
}

void Usuario::sumar_intentos_penviables(const string& p){
    this -> problemas_enviables.sumar_intento(p);
}

void Usuario::sumar_resueltos(){
    this -> resueltos += 1;
}

void Usuario::funcact(const string& p){
    this -> envios += 1;
    if (this -> problemas_enviables.get_intentos(p) == 0) this -> intentados += 1;
    this -> problemas_enviables.sumar_intento(p);
}

void Usuario::sumar_envio(){
    this -> envios += 1;
}

void Usuario::sumar_intentados() {
    this -> intentados += 1;
}

int Usuario::get_enviables_intentos(const string& p){
    return this -> problemas_enviables.get_intentos(p);
}

void Usuario::actualizar_enviables(Cjt_cursos& cc, const Cjt_sesiones& cs){
    cc.act_env(this->curso_inscrito, cs,this -> problemas_enviables, this -> problemas_resueltos);
    
}

void Usuario::imprimir_enviables() const{
    this -> problemas_enviables.listar();
}

void Usuario::imprimir_resueltos() const{
   this -> problemas_resueltos.listar();
}