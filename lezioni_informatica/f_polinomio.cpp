#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double polinomio(vector<int> v, double x){
  int n=v.size();
  double somma=0;
  for(int i=0; i<n; i++){
    somma=somma+v[i]*pow(x,i);
  }
  return somma;
}

int main() {
  int d;
  cout<<"Inserisci il grado del polinomio ";
  cin>>d;
  int dim=d+1;
  vector<int> a(dim);
  cout<<"Inserisci i coefficienti del polinomio a[0],...,a[dim] ";
  for(int i=0; i<dim; i++)
    cin>>a[i];
  cout<<"Inserisci la variabile ";
  double z;
  cin>>z;
  double ris=polinomio(a,z);
  cout<<"Il risultato è "<<ris<<endl;
}
