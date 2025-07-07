#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double varianza(vector<double> v){
  int n=v.size();
  double somma=0;
  double somma_q=0;
  for (double x:v){
    somma=somma+x;
    somma_q=somma_q+(x*x);
  }
  double var=(somma_q/n)-pow(somma/n,2);
  return sqrt(var);
}

int main() {
  vector<double> a;
  cout<< "Inserisci vector (scrivi 0 per terminare) ";
  double ris;
  do{
    cin>>ris;
    if(ris!=0)
      a.push_back(ris);
  }while(ris!=0);
  double varian=varianza(a);
  cout<<"La varianza è "<<varian<<endl;
}
