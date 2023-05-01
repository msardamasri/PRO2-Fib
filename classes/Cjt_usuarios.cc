#include "Cjt_usuarios.hh"
using namespace std;

Cjt_usuarios::Cjt_usuarios(){
}

void Cjt_usuarios::inicializar(){
    int nu;
    cin >> nu;
    string id_usuario;
    for (int i = 0; i < nu; ++i) {
        cin >> id_usuario;
        anadir_usuario(id_usuario);
    }
}

void Cjt_usuarios::nuevo_envio(const string& u, const string& p){
    map<string, Usuario>::iterator it = this -> cjt_usuarios.find(u);
    it->second.funcact(p);
}

void Cjt_usuarios::actualizar_resueltos_enviables(const string& u, const string& p, Cjt_cursos& cc, Cjt_sesiones& cs){
    map<string, Usuario>::iterator it = cjt_usuarios.find(u);
    it->second.funcact(p);
    it->second.modificar_resueltos(p);
    int num_curs = it->second.get_inscripcion_curso();
    string s = cc.get_ids(num_curs, p);
    it->second.envio(p,cs,s);
    if (it->second.comprovacion_terminado()) {
        cc.borrar_inscrito(num_curs);
        cc.anadir_completado(num_curs);
        it->second.modificar_curso(0);
    }
}

void Cjt_usuarios::inscribir_curso(const string& u, const int& n){
    map<string, Usuario>::iterator it = this -> cjt_usuarios.find(u);
    it->second.modificar_curso(n);
}

void Cjt_usuarios::borrar_usuario(const string& u){
    map<string, Usuario>::iterator it = this -> cjt_usuarios.find(u);
    cjt_usuarios.erase(it);
}

void Cjt_usuarios::anadir_usuario(const string& u){
    Usuario usr;
    cjt_usuarios.insert(make_pair(u, usr));
}

int Cjt_usuarios::size() const {
    return this -> cjt_usuarios.size();
}

bool Cjt_usuarios::existe_usuario(const string& u) const{
    return this -> cjt_usuarios.find(u) != this -> cjt_usuarios.end();
}

int Cjt_usuarios::inscripcion_curso(const string& u) const{
    map<string, Usuario>::const_iterator it = this -> cjt_usuarios.find(u);
    return it->second.get_inscripcion_curso();
}

void Cjt_usuarios::listar_usuarios() const {
    map<string, Usuario>::const_iterator it = this -> cjt_usuarios.begin();
    map<string, Usuario>::const_iterator end = this -> cjt_usuarios.end();
    while (it != end) {
        cout << it -> first  << "(" << it->second.get_envios() << ',' << it->second.get_resueltos() << ',' << it->second.get_intentados() << ',' << it->second.get_inscripcion_curso() << ')' << endl;
        ++it;
    }
}

void Cjt_usuarios::escribir_usuario(const string& u) const{
    map<string, Usuario>::const_iterator it = this -> cjt_usuarios.find(u);
    cout << u  << "(" << it->second.get_envios() << ',' << it->second.get_resueltos() << ',' << it->second.get_intentados() << ',' << it->second.get_inscripcion_curso() << ')' << endl;
}

void Cjt_usuarios::imprimir_enviables(const string& u) const{
    map<string, Usuario>::const_iterator it = this -> cjt_usuarios.find(u);
    it->second.imprimir_enviables();
}

void Cjt_usuarios::imprimir_resueltos(const string& u) const{
    map<string, Usuario>::const_iterator it = this -> cjt_usuarios.find(u);
    it->second.imprimir_resueltos();
}

void Cjt_usuarios::actualizar_enviables(const string& u, Cjt_cursos& cc, const Cjt_sesiones& cs){
    map<string, Usuario>::iterator it = this -> cjt_usuarios.find(u);
    it->second.actualizar_enviables(cc, cs);
}