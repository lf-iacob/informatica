#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Funzioni utili
string conv_bool(bool b){
  if(b==true)
    return "Vero";
  return "Falso";
}

void stampa_vector(const vector<string> &v){
  int n=v.size();
  for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
}

// Classe sfera
class sfera{
private:
  string nome;
  double x,y,z,r;
public:
  sfera(){nome=""; x=0; y=0; z=0; r=0;}
  sfera(string nm, double _x, double _y, double _z, double _r);
  static double distanza(sfera&s1, sfera&s2);
  friend ostream& operator<<(ostream&s, sfera&sf);
  double get_r();
  string get_nome();
  double volume();
};

sfera::sfera(string nm, double _x, double _y, double _z, double _r){
  nome=nm; x=_x; y=_y; z=_z; r=_r;
}

double sfera::distanza(sfera&s1, sfera&s2){
  return sqrt(pow(s1.x-s2.x,2)+pow(s1.y-s2.y,2)+pow(s1.z-s2.z,2));
}

ostream& operator<<(ostream&s, sfera&sf){
  s<<"Nome:"<<sf.nome<<"  Centro:("<<sf.x<<";"<<sf.y<<";"<<sf.z<<")  Raggio:"<<sf.r<<endl;
  return s;
}

double sfera::get_r(){
  return r;
}

string sfera::get_nome(){
  return nome;
}

double sfera::volume(){
  return (double(4)/3)*M_PI*pow(r,3);
}

// Classe insieme di sfere
class insieme_sfere{
private:
  vector<sfera> sistema;
  int m;
public:
  insieme_sfere(){m=0;}
  bool inserisci(string nm, double _x, double _y, double _z, double _r);
  void visualizza();
  double volume();
  vector<string> seleziona(double r0);
};

bool insieme_sfere::inserisci(string nm, double _x, double _y, double _z, double _r){
  sfera s(nm,_x,_y,_z,_r); double d,s_raggi;
  for(int i=0; i<m; i++){
    d=sfera::distanza(s,sistema[i]);
    s_raggi=sistema[i].get_r()+_r;
    if(d<s_raggi)
      return false;
  }
  sistema.push_back(s);
  m++;
  return true;
}

void insieme_sfere::visualizza(){
  for(int i=0; i<m; i++)
    cout<<sistema[i];
}

double insieme_sfere::volume(){
  double s=0;
  for(int i=0; i<m; i++)
    s+=sistema[i].volume();
  return s;
}
vector<string> insieme_sfere::seleziona(double r0){
  vector<string> v;
  for(int i=0; i<m; i++){
    if(sistema[i].get_r()>r0)
      v.push_back(sistema[i].get_nome());
  }
  return v;
}

// Main
int main() {
  cout<<"ESAME DI INFORMATICA"<<endl<<"Data: 8.02.2024   Matricola: 353987   Cognome: Iacob"
      <<endl<<"ESERCIZIO 3"<<endl;
  
  cout<<"INSIEME DI SFERE NELLO SPAZIO TRIDIMENSIONALE"<<endl;
  insieme_sfere spazio;

  double a,b,c,d; string e; bool ris; vector<string> v;
  int scelta;
  cout<<"MENU"<<endl<<"1. Inserisci una nuova sfera"<<endl<<"2. Visualizza le sfere che compongono il sistema"<<endl<<"3. Volume totale"<<endl<<"4. Seleziona sfere con raggio sufficientemente grande"<<endl<<"0. Esci"<<endl;
  cout<<endl<<"Si scelga l'operazione da svolgere "<<endl<<">>> ";
  cin>>scelta;
  do{
    switch(scelta){
    case 0:
      cout<<"A presto!"<<endl;
      exit(1);
    case 1:
      cout<<"Inserisci nome della sfera, coordinate del centro di massa (x,y,z) ed il raggio"<<endl;
      cin>>e>>a>>b>>c>>d;
      ris=spazio.inserisci(e,a,b,c,d);
      cout<<"La sfera è stata inserita con successo: "<<conv_bool(ris)<<endl;
      if(ris==false)
        cerr<<"Inserimento fallito: si è tentato di aggiungere una sfera in una regione di spazio già occupata."<<endl;
      break;
    case 2:
      spazio.visualizza();
      break;
    case 3:
      cout<<"Volume totale del sistema: "<<spazio.volume()<<endl;
      break;
    case 4:
      cout<<"Inserisci il valore di raggio discriminante: ";
      cin>>a;
      v=spazio.seleziona(a);
      b=v.size();
      if(b!=0){
        cout<<"Le sfere con raggio maggiore sono le seguenti:"<<endl;
        stampa_vector(v);
        cout<<endl;
      } else
        cout<<"Non ci sono sfere con raggio maggiore di "<<a<<endl;
      break;
    };
    cout<<endl<<"Si scelga l'operazione da svolgere "<<endl<<">>> ";
    cin>>scelta;
  }while(scelta!=0);
  cout<<"A presto!"<<endl;
}
