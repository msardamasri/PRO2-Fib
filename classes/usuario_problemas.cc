#include "usuario_problemas.hh"
using namespace std;

Problemas_usr::Problemas_usr() {
    tam = 0;
}

bool Problemas_usr::vacio(){
    return this -> problemas_usr.empty();
}

void Problemas_usr::anadir_problema(const string& s){
    int intentos = 0;
    this -> problemas_usr.insert(make_pair(s, intentos));
    this-> tam += 1;
}

void Problemas_usr::anadir_pair(const pair<string, int>& par){
    this -> problemas_usr.insert(par);
}

void Problemas_usr::sumar_intento(const string& p){
    map<string, int>::iterator it = this -> problemas_usr.find(p);
    it->second += 1;
}

void Problemas_usr::borrar_problema(const string& p){
    map<string, int>::iterator it = this -> problemas_usr.find(p);
    this -> problemas_usr.erase(it);
}

bool Problemas_usr::existe_problema(const string& p) const{
    return this -> problemas_usr.find(p) != this -> problemas_usr.end();
}

void Problemas_usr::get_pair(const string& p, pair<string, int>& par) const{
    map<string, int>::const_iterator it = this -> problemas_usr.find(p);
    par.first = it->first;
    par.second = it->second;
}

int Problemas_usr::get_tam(){
    return tam;
}

void Problemas_usr::escribir_problema(const string& p) const{
    map<string, int>::const_iterator it = this -> problemas_usr.find(p);
    cout << it->first << "(" << it->second << ')' << endl;
}

void Problemas_usr::listar() const{
    map<string, int>::const_iterator it = this -> problemas_usr.begin();
    map<string, int>::const_iterator end = this -> problemas_usr.end();
    while  (it != end) {
        cout << it->first << "(" << it->second << ')' << endl;
        ++it;
    }
}

int Problemas_usr::get_intentos(const string& p){
    map<string, int>::iterator it = this -> problemas_usr.find(p);
    return it->second;
}