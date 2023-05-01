#include "Cjt_sesiones.hh"
using namespace std;

Cjt_sesiones::Cjt_sesiones(){
}

void Cjt_sesiones::inicializar(){
    int ns;
    cin >> ns;
    string id_sesion;
    for(int i = 0; i < ns; ++i) {
        cin >> id_sesion;
        Sesion s;
        s.leer_sesion();
        cjt_sesiones.insert(make_pair(id_sesion, s));
    }
}

void Cjt_sesiones::anadir_sesion(const string& n,const Sesion& s){
    cjt_sesiones.insert(make_pair(n, s));
}

int Cjt_sesiones::size() const {
    return cjt_sesiones.size();
}

bool Cjt_sesiones::existe_sesion(const string& n) const{
    return cjt_sesiones.find(n) != cjt_sesiones.end();
}

void Cjt_sesiones::listar_sesiones() const {
    map<string, Sesion>::const_iterator it = cjt_sesiones.begin();
    map<string, Sesion>::const_iterator end = cjt_sesiones.end();
    while (it != end) {
        cout << it->first << ' ' << it->second.get_numero_problemas() << ' ';
        it->second.escribir_s();
        ++it;
    }
}

void Cjt_sesiones::escribir_sesion(const string& n) const{
    map<string, Sesion>::const_iterator it = cjt_sesiones.find(n);
    cout << n << ' ' << it->second.get_numero_problemas() << ' ';
    it->second.escribir_s();
    
}


void Cjt_sesiones::envio(const string& p, const string& s, Problemas_usr& env, Problemas_usr& res) const{
    map<string, Sesion>::const_iterator it = cjt_sesiones.find(s);
    it->second.envio(p,env, res);
}

void Cjt_sesiones::actualizar_enviables(string& s, Problemas_usr& env, Problemas_usr& res) const{
    map<string, Sesion>::const_iterator it = cjt_sesiones.find(s);
    it->second.actualizar_problemas(env, res);
}

string Cjt_sesiones::id_posicio_j(const string& s, const int& j) const{
    map<string, Sesion>::const_iterator it = cjt_sesiones.find(s);
    return it->second.id_posicio_j(j);
}

int Cjt_sesiones::get_numero_problemas(const string& s) const{
    map<string, Sesion>::const_iterator it = cjt_sesiones.find(s);
    return it->second.get_numero_problemas();
}