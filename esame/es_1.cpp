#include <iostream>
#include <vector>
using namespace std;

int funzione(vector<int> &w){
  int conta=0, n=w.size(), media=0;
  for(int i=0; i<n; i++)
    media+=w[i];
  media=media/n;
  for(int i=0; i<n; i++){
    if(w[i]>media)
      conta++;
  }
  return conta;
}

int main() {
  cout<<"ESAME DI INFORMATICA"<<endl<<"Data: 8.02.2024   Matricola: 353987   Cognome: Iacob"
      <<endl<<"ESERCIZIO 1"<<endl;
  cout<<"Inserisci gli elementi del vector (scrivi 'fine' per terminare)"<<endl;
  vector<int> v;
  string x;
  cin>>x;
  do{
    v.push_back(stod(x));
    cin>>x;
  }while(x!="fine");
  int m=funzione(v);
  cout<<"Il numero di elementi maggiori della media è "<<m<<endl;
}
