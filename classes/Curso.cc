#include "Curso.hh"
using namespace std;

Curso::Curso() {
    usuarios_completados = 0;
    usuarios_inscritos = 0;
}

void Curso::leer_curso(const Cjt_sesiones& cs) {
    int ns;
    cin >> ns;
    string id_sesion;
    for (int i = 0; i < ns; ++i) {
        cin >> id_sesion;
        this -> curso.push_back(id_sesion);
        int size = cs.get_numero_problemas(id_sesion);
        for (int j = 0; j < size; ++j) {
            string id_problema = cs.id_posicio_j(id_sesion,j);
            this -> problemas_sesiones.insert(make_pair(id_problema, id_sesion));
        }
    }
}

void Curso::leer_curso_n(const Cjt_sesiones& cs, bool& interseccion) {
    int ns;
    cin >> ns;
    int i = 0, n = 0;
    string id_sesion;
    while (not interseccion and i < ns) {
        cin >> id_sesion;
        this -> curso.push_back(id_sesion);
        int size = cs.get_numero_problemas(id_sesion);
        n += size;
        int j = 0;
        while (not interseccion and j < size){
            string id_problema = cs.id_posicio_j(id_sesion,j);
            this -> problemas_sesiones.insert(make_pair(id_problema, id_sesion));
            ++j;
        }
        if (problemas_sesiones.size() < n) interseccion = true;
        --ns;
    }
    for (int k = 0; k < ns; ++k){
        cin >> id_sesion;
    }
}

void Curso::anadir_completado() {
    this -> usuarios_completados += 1;
}

int Curso::size() const{
    return this->curso.size();
}

void Curso::escribir_c()const{
    int size = curso.size()-1;
    cout << ' ' << this -> usuarios_completados << ' ' << this -> usuarios_inscritos << ' ' << size+1 << " (";
    for (int i = 0; i < size; ++i) {
        cout << this -> curso[i] << ' ';
    }
    cout << curso[size] << ')' << endl;
}

int Curso::get_usuarios_completados() const{
    return this -> usuarios_completados;
}

int Curso::get_usuarios_inscritos() const{
    return this -> usuarios_inscritos;
}

void Curso::borrar_insc() {
    this -> usuarios_inscritos -= 1;
}

void Curso::sumar_inscrito() {
    this -> usuarios_inscritos += 1;
}

string Curso::get_sesionid(const int& n) const{
    return this -> curso[n];
}

string Curso::get_sesionpsid(const string& p) const{
    map<string, string>::const_iterator it = this -> problemas_sesiones.find(p);
    return it->second;
}

void Curso::get_vsesiones(vector<string> & v){
    v = curso;
}

bool Curso::pertenece_problema(const string& p) const{
    map<string, string>::const_iterator it = this -> problemas_sesiones.find(p);
    return it != this -> problemas_sesiones.end();
}

void Curso::act_env(const Cjt_sesiones& cs,Problemas_usr& env, Problemas_usr& res){
    int size = curso.size();
    for (int i = 0; i < size; ++i) {
        cs.actualizar_enviables(curso[i],env, res);        
    }
}