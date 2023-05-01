#include "Cjt_problemas.hh"
using namespace std;

Cjt_problemas::Cjt_problemas(){
    struct Problema {
      int total_envios = 0;
      int resueltos = 0;
      double ratio = 1;
    };
}

void Cjt_problemas::inicializar(){
    int np;
    cin >> np;
    string id_problema;
    for(int i = 0; i < np; ++i) {
        cin >> id_problema;
        anadir_problema(id_problema);
    }
}

void Cjt_problemas::anadir_problema(const string& s){
    Problema p;
    p.resueltos = 0;
    p.total_envios = 0;
    p.ratio = 1;
    this -> cjt_problemas.insert(make_pair(s, p));
}

void Cjt_problemas::actualizar_envios(const string& p){
    map<string, Problema>::iterator it = this -> cjt_problemas.find(p);
    it->second.total_envios += 1;
}

void Cjt_problemas::actualizar_envios_correcto(const string& p){
    map<string, Problema>::iterator it = this -> cjt_problemas.find(p);
    it->second.total_envios += 1;
    it->second.resueltos += 1;
}

int Cjt_problemas::size() const {
    return this -> cjt_problemas.size();
}

bool Cjt_problemas::existe_problema(const string& p) const{
    return this -> cjt_problemas.find(p) != this -> cjt_problemas.end();
}

bool Cjt_problemas::cmp(const pair<string, Problema>& p1, const pair<string, Problema>& p2){
    if(p1.second.ratio != p2.second.ratio) return p1.second.ratio < p2.second.ratio;
    else return p1.first < p2.first;
}

void Cjt_problemas::vectoritzar(const map<string, Problema>& m, vector<pair<string, Problema>>& v){
    map<string, Problema>::const_iterator it = m.begin();
    map<string, Problema>::const_iterator end = m.end();
    v = vector<pair<string, Problema>>(m.size());
    int i = 0;
    while(it != end) {
        v[i].first = it->first;
        v[i].second = it -> second;
        ++i;
        ++it;
    }
}

void Cjt_problemas::listar_problemas()const{
    vector<pair<string, Problema>> v;
    vectoritzar(this -> cjt_problemas, v);
    sort(v.begin(), v.end(), cmp);
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        cout << v[i].first << "(" << v[i].second.total_envios << ',' << v[i].second.resueltos << ',' << calcular_ratio(v[i].second) << ')' << endl;
    }
}

void Cjt_problemas::escribir_problema(const string &p) const{
    map<string, Problema>::const_iterator it = this -> cjt_problemas.find(p);
    cout << it->first << "(" << it->second.total_envios << ',' << it->second.resueltos << ',' << calcular_ratio(it->second) << ')' << endl;
}

double Cjt_problemas::calcular_ratio(const Problema& p) const{
    return (p.total_envios + 1) / (double(p.resueltos) + 1);
}

void Cjt_problemas::calcular_ratio_listar(){
    map<string, Problema>::iterator bg = cjt_problemas.begin();
    map<string, Problema>::const_iterator end = cjt_problemas.end();  
    while(bg != end) {
        bg -> second.ratio = calcular_ratio(bg->second);
        ++bg;
    }
}