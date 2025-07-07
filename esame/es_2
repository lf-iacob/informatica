#include <iostream>
#include <vector>
using namespace std;
#define M 4
#define N 3

void leggi_matrice(double A[M][N]){
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++)
      cin>>A[i][j];
  }
}

void stampa_vector(const vector<double> &v){
  int n=v.size();
  for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
}

vector<double> funzione(double A[M][N]){
  vector<double> v; double max;
  for(int i=0; i<M; i++){
    max=A[i][0];
    for(int j=1; j<N; j++){
      if(A[i][j]>max)
        max=A[i][j];
    }
    v.push_back(max);
  }
  return v;
}

int main() {
  cout<<"ESAME DI INFORMATICA"<<endl<<"Data: 8.02.2024   Matricola: 353987   Cognome: Iacob"
      <<endl<<"ESERCIZIO 2"<<endl;
  cout<<"Inserisci elementi matrice "<<M<<"x"<<N<<endl;
  double m[M][N];
  leggi_matrice(m);
  vector<double> w=funzione(m);
  cout<<"Vector risultante: ";
  stampa_vector(w);
  cout<<endl;
}
