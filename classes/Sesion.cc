#include "Sesion.hh"
using namespace std;

Sesion::Sesion() {
    numero_problemas = 0;
}

void Sesion::leer_sesion() {
    i_leer_preorden(sesion);
}

void Sesion::i_leer_preorden(BinTree<string>& a) {
    string x;
    cin >> x;
    if (x != "0") {
        this -> numero_problemas += 1;
        BinTree<string> e, d;
        i_leer_preorden(e);
        i_leer_preorden(d);
        a = BinTree<string>(x,e,d);
        this -> vsesion.push_back(x);
    }
}

int Sesion::get_numero_problemas() const {
    return this -> numero_problemas;
}

void Sesion::escribir_s() const{
    i_imprimir_problemas(sesion);
    cout << endl;
}

void Sesion::i_imprimir_problemas(const BinTree<string>& a){
    if (not a.empty()) {
        cout << '(';
        i_imprimir_problemas(a.left());
        i_imprimir_problemas(a.right());
        cout << a.value() << ')';
    }
}

void Sesion::envio(const string& p, Problemas_usr& env, const Problemas_usr& res) const {
    i_envio_recursivo(p,sesion, env, res);
}

void Sesion::i_envio_recursivo(const string& p, const BinTree<string>& a, Problemas_usr& env,const Problemas_usr& res){
    if (not a.empty()){
        if(a.value() != p) {
            i_envio_recursivo(p,a.left(), env, res);
            i_envio_recursivo(p,a.right(), env, res);
        }
        else{
            i_actualizar_recursivo(a.left(), env, res);
            i_actualizar_recursivo(a.right(), env, res);
        }
    }
}


void Sesion::actualizar_problemas(Problemas_usr& env, const Problemas_usr& res) const {
    i_actualizar_recursivo(sesion, env, res);
}

void Sesion::i_actualizar_recursivo(const BinTree<string>& a, Problemas_usr& env,const Problemas_usr& res){
    if (not a.empty()){
        if(not res.existe_problema(a.value())) {
            env.anadir_problema(a.value());
        }
        else{
            i_actualizar_recursivo(a.left(), env, res);
            i_actualizar_recursivo(a.right(), env, res);
        }
    }
}

string Sesion::id_posicio_j(const int& j) const{
    return vsesion[j];
}