#include <iostream>
using namespace std;

// Dichiarazione classe "veicolo"
class veicolo {
private:
  string nome;
  string proprietario;
  bool stato_motore;
  int x, y;
  int orientamento;
  int passi;
public:
  veicolo (string _nome, string _proprietario) {
    nome=_nome;
    proprietario=_proprietario;
    stato_motore=false;
    x=0; y=0;
    orientamento=0;
    passi=0;
  }
  void accendi_motore() {
    stato_motore=true;
  }
  void spegni_motore() {
    stato_motore=false;
  }
  void gira(int n) {
    orientamento=n;
  }
  void spegnimento_obbligato();
  int avanzamento(int np);
  void situazione();
};

// Implementazione normale metodo "avanzamento"
int veicolo::avanzamento(int np) {
  if (stato_motore==true) {
    switch (orientamento) {
      case 0:
        y=y+np;
        break;
      case 1:
        x=x+np;
        break;
      case 2:
        y=y-np;
        break;
      case 3:
        x=x-np;
        break;
    }
    passi = passi+np;
    return passi;
  } else {
    cout << "Se non accendi il veicolo, come pensi di potrelo far avanzare? Io non lo spingo, ti avviso." << endl;
    return passi;
  }
}

// Implementazione normale metodo "situazione"
void veicolo::situazione() {
  cout << "Veicolo: " << nome << ", appartentente a " << proprietario << " si trova in posizione x="
  << x << " y=" << y << ", orientato nella direzione " << orientamento << " dopo aver compiuto "
  << passi << " passi." << endl;
}

// Implementazione normale metodo "spegnimento_obbligato"
void veicolo::spegnimento_obbligato() { 
  if (stato_motore==true) {
    cout << "Non è possibile terminare il programma se il motore è ancora acceso, spegnilo prima di andare via!" << endl;
    int spegni_obbligato;
    cin >> spegni_obbligato;
    while (spegni_obbligato != 2) {
      cout << "Riprova: "; 
      cin >> spegni_obbligato;
    }
    spegni_motore();
  } else {
    cout << "Spero ti sia divertito. A presto!" << endl;
  }
}

// Interfaccia utente
int main() {
  // Inserimento dati per inizializzazione
  string nome_proprietario, nome_veicolo;
  cout << "Buongiorno! Ho il piacere di conoscere... " << endl;
  cout << "Inserisci il tuo nome: ";
  cin >> nome_proprietario;
  cout << "Hai appena preso possesso del tuo nuovo veicolo " << endl;
  cout << "Inserisci il nome del veicolo: ";
  cin >> nome_veicolo;
  cout << endl;
  veicolo v (nome_veicolo, nome_proprietario);
  // Menu
  int menu;
  cout << "Vogliamo metterlo alla prova? Scegli una delle seguenti azioni scrivendo il numero corrispondente " << endl;
  cout << "(Digita 0 per terminare il programma)" << endl;
  cout << "1) Accendi il motore" << endl;
  cout << "2) Spegni il motore" << endl;
  cout << "3) Gira il veicolo" << endl;
  cout << "4) Avanza" << endl;
  cout << "5) Stato del veicolo" << endl;
  cout << endl;
  cout << ">>> ";
  cin >> menu;
  cout << endl;
  while (menu!=0) {
    switch (menu) {
      case 1:
        v.accendi_motore();
        break;
      case 2:
        v.spegni_motore();
        break;
      case 3:
        int direzione;
        cout << "Scegli la direzione verso cui puntare il veicolo" << endl;
        cout << "0) Alto" << endl;
        cout << "1) Destra" << endl;
        cout << "2) Basso" << endl;
        cout << "3) Sinistra" << endl;
        cout << "4) Esci" << endl;
        cin >> direzione;
        if (direzione != 4)
          v.gira(direzione);
        break;
      case 4:
        int step;
        cout << "Di quante unità vuoi avanzare? ";
        cin >> step;
        v.avanzamento(step);
        break;
      case 5:
        v.situazione();
        break;
    }
    cout << endl << ">>> ";
    cin >> menu;
  }
  if (menu == 0)
    v.spegnimento_obbligato();
}
