/* Definire una classe biblioteca avente i seguenti metodi pubblici 
a) costruttore, crea inizialmente una biblioteca vuota;
b) NO :)))))) void leggi(nomefile), apre in lettura il file contenente i dati in alcuni libri (ad esempio titolo e autore) e inserisce nella biblioteca i libri in questione. Un problema tecnico si ha sia con il titolo che con l'autore, dato che potrebbe contenere degli spazi e la lettura con >> di una stringa non consente la presenza di spazi. Quindi o si eliminano gli spazi usando il carattere " " oppure si legge da file tramite il metodo getline, mettendo titolo in una riga e autore in un'altra;
c) bool presente(titolo), cerca un libro in base al titolo, restituisce true se c'ê, false
altrimenti;
d) int libri_scritti(autore), restituisce il numero di libri scritti dall'autore;
e) void acquista(titolo, autore), inserisce un nuovo libro;
f) NO :)))))) void salva(nomefile), salva il contenuto nel file, usando lo stesso "formato" previsto per il metodo leggi
Memorizzare i dati dei libri in opportune strutture dati interne alla classe. Per semplificare un po' l'esercizio, si usino solo libri con un solo autore, altrimenti per gestire gli autori di un libro occorrerebbe un'ulteriore struttura dati.
*/

//POV: parti con un esercizio del prof, ti vengono 1000 idee e quindi finisci per implementare tantissimi nuovi metodi e ti ritrovi ad aver trasformato la biblioteca originaria in una libreria

#include <iostream>
#include <vector>
using namespace std;

string conv_bool(bool b){
  if(b==true)
    return "Vero";
  return "Falso";
}

// CLASSE LIBRO
// Un'alternativa sarebbe stata una semplice struct con autore e titolo o ancora una mappa, visti i metodi invocabili dulla classe "biblioteca"
// Idea di implementazione: libro è la classe madre, ma ci sono tutte le classi figlie che sono un genere specifico di libro (libro fantasy, libro giallo, libro horror, libro romantico, ecc...). Oppure, per non farla troppo complcata, si potrebbe indicare come campo del libro una mappa di string (generi di libro) e bool (se il libro è di quel genere o meno)
class libro{
private:
  string titolo, autore;
  static int n_serie;
  int pagine;
  double prezzo;
  bool letto;
public:
  libro(){
    titolo=""; autore=""; prezzo=0;
    pagine=0; n_serie++; letto=false;
  }
  libro(string t, string a, double c, int p){
    titolo=t; autore=a; prezzo=c;
    pagine=p; n_serie++; letto=false;
  }
  string get_titolo(){return titolo;}
  string get_autore(){return autore;}
  double get_prezzo(){return prezzo;}
  void leggi(){letto=true;}
  friend istream& operator>>(istream&s, libro&l);
  friend ostream& operator<<(ostream&s, libro&l);
};

int libro::n_serie=0;

istream& operator>>(istream&s, libro&l){
  s>>l.titolo>>l.autore>>l.prezzo>>l.pagine;
  return s;
}

ostream& operator<<(ostream&s, libro&l){
  s<<"Titolo:'"<<l.titolo<<"' Autore:"<<l.autore<<" Pagine:"<<l.pagine<<" Prezzo:"<<l.prezzo<<" Letto:"<<conv_bool(l.letto)<<endl;
  return s;
}


// CLASSE BIBLIOTECA
// Idea implementazione: invece di un vector, usare una mappa per registrare i libri e come secondo campo ci dovrebbe essere un intero che conta quanti esemplari di quel libro ci sono in libreria
class biblioteca{
private:
  vector<libro> libri;
  int m;
  double cassa;
public:
  biblioteca(double c){m=0; cassa=c;}

  void acquista();
  //void investi(double n);
  void vendi(int index);
  friend ostream& operator<<(ostream&s, biblioteca&b);
  bool presente(string tit);
  int libri_scritti(string aut);
  void leggi_libro(int index);
  double get_cassa();
};

void biblioteca::acquista(){
  libro l;
  cin>>l;
  if(l.get_prezzo()<cassa){
    libri.push_back(l);
    m++;
    cassa-=l.get_prezzo();
  }else
    cerr<<"Credito insufficiente"<<endl;
}

// Buona idea ma ha bisogno di un'implementazione migliore, per non permettere all'utente di inserire qualunque cifra in qualsivoglia momento (cosa che fa perdere il significato del metodo stesso). Tipo si possono investire alcune cifre solo in base a quanti soldi si possiede in cassa o in base a quanti libri compongono la biblioteca
/* void biblioteca::investi(double n){
  cassa+=n;
}
*/

void biblioteca::vendi(int index){
  cassa+=libri[index].get_prezzo();
  for(int i=index+1; i<m; i++)
    libri[i-1]=libri[i];
  m--;
  libri.resize(m);
}

ostream& operator<<(ostream&s, biblioteca&b){
  for(int i=0; i<b.m; i++)
    s<<"LIBRO n."<<i<<" "<<b.libri[i];
  return s;
}

bool biblioteca::presente(string tit){
  for(int i=0; i<m; i++){
    if(libri[i].get_titolo()==tit)
      return true;
  }
  return false;
}

int biblioteca::libri_scritti(string aut){
  int conta=0;
  for(int i=0; i<m; i++){
    if(libri[i].get_autore()==aut)
      conta++;
  }
  return conta;
}

void biblioteca::leggi_libro(int index){
  libri[index].leggi();
}

double biblioteca::get_cassa(){
  return cassa;
}

int main() {
  cout<<"LIBRERIA 'Ars Longa'"<<endl;
  string vars; double vard; int vari;
  
  cout<<"Inserisci il credito iniziale: ";
  cin>>vard;
  biblioteca* biblio=new biblioteca(vard);
  
  string scelta; int sce;
  cout<<"MENU"<<endl<<"Attenzione: i titoli e gli autori dei libri sono spaziati dall'underscore"<<endl<<"1. Acquista libro"<<endl<<"2. Cerca libro nel catalogo"<<endl<<"3. Vendi libro"<<endl<<"4. Conta libri di specifico autore"<<endl<<"5. Catalogo libri"<<endl<<"6. Leggi libro"<<endl<<"7. Cassa"<<endl<<"Scrivere 'esci' per uscire";
  cout<<endl<<"\nSi scelga l'operazione da svolgere "<<endl<<">>> ";
  cin>>scelta;
  while(scelta!="esci"){
    sce=stoi(scelta);
    switch(sce){
    case 1:
      cout<<"Inserisci le informazioni del libro che si vuole acquistare: titolo, autore, prezzo e numero pagine"<<endl;
      biblio->acquista();
      cout<<"Libro nuovo aggiunto con successo al catalogo"<<endl;
      break;
    case 2:
      cout<<"Inserisci il titolo del libro che si sta cercando: ";
      cin>>vars;
      cout<<"Libro presente in libreria: "<<conv_bool(biblio->presente(vars))<<endl;
      break;
    case 3:
      cout<<"Inserisci l'indice del libro che si vuole vendere: ";
      cin>>vari;
      biblio->vendi(vari);
      break;
    case 4:
      cout<<"Inserisci autore: ";
      cin>>vars;
      cout<<"Sono presenti "<<biblio->libri_scritti(vars)<<" volumi a suo nome"<<endl;
      break;
    case 5:
      cout<<"CATALOGO"<<endl<<*biblio;
      break;
    case 6:
      cout<<"Inserisci indice libro da leggere: ";
      cin>>vari;
      biblio->leggi_libro(vari);
      cout<<"Libro letto con succeso!"<<endl;
      break;
    case 7:
      cout<<"Cassa: "<<biblio->get_cassa()<<endl;
      break;
    };
    cout<<endl<<"Si scelga l'operazione da svolgere "<<endl<<">>> ";
    cin>>scelta;
  };
  cout<<"A presto!"<<endl;

  delete biblio;
}
