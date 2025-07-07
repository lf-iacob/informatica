#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int k;
  double x, somma=0, termine;
  cout << "Inserisci il numero di termini: ";
  cin >> k;
  cout << "Inserisci x: ";
  cin >> x;
  for (int i=0; i<=k-1; i++) {
    long long int fatt=1;
    for (int j=1; j<=2*i+1; j++) 
      fatt=fatt*j;
    termine=(pow(-1,i)*pow(x,2*i+1))/fatt;
    somma=somma+termine;
  }
  cout << "sen(x) = " << somma<< endl;
  cout << "Valore esatto: " << sin(x) << endl;
}
