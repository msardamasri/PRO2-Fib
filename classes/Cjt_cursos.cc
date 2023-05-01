#include "Cjt_cursos.hh"
using namespace std;

Cjt_cursos::Cjt_cursos(){
}

void Cjt_cursos::inicializar(const Cjt_sesiones& cs){
    int nc;
    cin >> nc;
    for (int i = 0; i < nc; ++i) {
        Curso c;
        c.leer_curso(cs);
        anadir_curso(c);
    }
}

bool Cjt_cursos::leer_nuevo_curso(const Cjt_sesiones& cjt_sesiones) {
    Curso nuevo;
    bool interseccion = false;
    nuevo.leer_curso_n(cjt_sesiones, interseccion);
    if (not interseccion) {
        anadir_curso(nuevo);
        return true;
    }
    return false;
}

void Cjt_cursos::anadir_completado(const int & n){
    cjt_cursos[n-1].anadir_completado();
}

string Cjt_cursos::get_ids(const int& c, const string& p){
    return cjt_cursos[c-1].get_sesionpsid(p);
}

void Cjt_cursos::modificar_curso(const Curso& curso,const int& c) {
    this -> cjt_cursos[c-1] = curso;
}

void Cjt_cursos::anadir_curso(const Curso& c){
    this -> cjt_cursos.push_back(c);
    
}

void Cjt_cursos::sumar_usuario_inscrito(const int& s){
    this -> cjt_cursos[s-1].sumar_inscrito();
}

void Cjt_cursos::borrar_inscrito(const int& c){
    this -> cjt_cursos[c-1].borrar_insc();
}

bool Cjt_cursos::pertenece_problema(const string& p,const int& c) const{
    return this -> cjt_cursos[c-1].pertenece_problema(p);
}

int Cjt_cursos::size() const {
    return this -> cjt_cursos.size();
}

bool Cjt_cursos::existe_curso(const int& s) const{
    return 0 < s  and  s <= this -> cjt_cursos.size();
}  

void Cjt_cursos::imprimir_inscritos(const int& s) const{
    cout << this -> cjt_cursos[s-1].get_usuarios_inscritos() << endl;
}

void Cjt_cursos::imprimir_sesion_problema(const int& c, const string& p) const{
    cout << this -> cjt_cursos[c-1].get_sesionpsid(p) << endl;
}

void Cjt_cursos::listar_cursos() const {
    int size = this -> cjt_cursos.size();
    for (int i = 1; i <= size; ++i) {
        escribir_curso(i);
    }
}

void Cjt_cursos::escribir_curso(const int& s) const{
    cout << s;
    this -> cjt_cursos[s-1].escribir_c();
}

void Cjt_cursos::act_env(const int& c, const Cjt_sesiones& cs,Problemas_usr& env, Problemas_usr& res){
    this -> cjt_cursos[c-1].act_env(cs,env,res);
}