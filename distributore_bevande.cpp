#include <iostream>
#include <vector>
#include <map>
using namespace std;

class bevanda{
public:
  bevanda(string n, double c){
    nome=n;
    costo=c;
  };
  double get_costo(){
    return costo;
  }
private:
  string nome;
  double costo;
};

class distributore_bevande{
private:
  double cassa;
  double inserimento;
  double prezzo;
  map<bevanda*, int>  bev;
  bevanda *coca;
  bevanda *fanta;
  bevanda *acqua;
  bevanda *monster;
public:
  distributore_bevande(int c, int f, int a, int m){
    coca=new bevanda("Coca cola", 1.20);
    fanta=new bevanda("Fanta", 1.00);
    acqua=new bevanda("Acqua", 0.80);
    monster=new bevanda("Monster", 1.30);
    cassa=0;
    inserimento=0;
    prezzo=0;
    bev={{coca, c}, {fanta, f}, {acqua, a}, {monster, m}};
  }
  void inserisci_moneta(int c);
  void annulla();
  void seleziona(bevanda *b);
  double get_cassa(){
    return cassa;
  }
  void gestione_distributore();
  friend ostream& operator<<(ostream& s, distributore_bevande &d);
  ~ distributore_bevande(){
    delete coca; delete fanta; delete acqua; delete monster;
  }
};

void distributore_bevande::inserisci_moneta(int c){
  if(c==1 || c==2 || c==5 || c==10 || c==20 || c==50){
    inserimento=c*0.01;
    prezzo=prezzo+inserimento;
    cassa=cassa+inserimento;
    cout<<"Operazione andata a buon fine"<<endl;
  }else
    cerr<<"Operazione fallita"<<endl;
}

void distributore_bevande::annulla(){
  cassa=cassa-inserimento;
  prezzo=prezzo-inserimento;
  inserimento=0;
  cout<<"Inserimento annullato"<<endl;
}

void distributore_bevande::seleziona(bevanda *b){
  if(bev[b]<=0)
    cerr<<"Bevanda esaurita, operazione non disponibile"<<endl;
  else{
    if(prezzo<b->get_costo())
      cerr<<"Importo insufficiente"<<endl;
    else{
      double resto=prezzo-b->get_costo();
      bev[b]=bev[b]-1;
      cout<<"Bevanda consegnata!"<<endl;
      cassa=cassa-resto;
      cout<<"Il resto è pari a "<<resto<<" €"<<endl;
      prezzo=0;
      inserimento=0;
   }
  }
}

void distributore_bevande::gestione_distributore(){
  int operazione;
  cout<<"MENU"<<endl<<"1. Inserisci moneta"<<endl<<"2. Annulla ultimo inserimento"<<endl
    <<"3. Seleziona bevanda"<<endl<<"   31. Coca cola: "<<coca->get_costo()<<"€"<<endl<<"   32. Fanta: "<<fanta->get_costo()<<"€"<<endl
      <<"   33. Acqua: "<<acqua->get_costo()<<"€"<<endl<<"   34. Monster: "<<monster->get_costo()<<"€"<<endl<<"0. Esci"<<endl<<"NB La macchina accetta solo centesimi di euro"<<endl;
  cout<<"Scegli l'operazione da compiere ";
  cin>>operazione;
  do{
    switch(operazione){
    case 1:
      int moneta;
      cout<<">> ";
      cin>>moneta;
      inserisci_moneta(moneta);
      break;
    case 2:
      annulla();
      break;
    case 3:
      int indice;
      cin>>indice;
      vector<bevanda *> bibita;
      for(auto elemento:bev){
        bibita.push_back(elemento.first);
      }
      seleziona(bibita[indice-31]);
      break;
    };
    if(operazione==0)
    break;
    cout<<"Scegli l'operazione da compiere ";
    cin>>operazione;
  }while(operazione!=0);
  cout<<"A presto!"<<endl;
}

ostream& operator<<(ostream& s, distributore_bevande &d){
  s<<"La cassa ha "<<d.get_cassa()<<" €"<<endl
    <<"Le bibite disponibili sono "<<endl;
  string bibita[4]={"Coca cola", "Fanta", "Acqua", "Monster"};
  int i=0;
  for(auto ele:d.bev){
    s<<"Bevanda: "<<bibita[i]<<"\t"<<" Unità: "<<ele.second<<endl;
    i++;
  }
  return s;
}

int main() {
  distributore_bevande *dis=new distributore_bevande(10, 6, 21, 3);
  dis->gestione_distributore();
  cout<<*dis;
  dis-> ~distributore_bevande();
  delete dis;
}
