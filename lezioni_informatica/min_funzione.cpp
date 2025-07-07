#include <iostream>
#include <cmath>
using namespace std;

//Trovare il valore nell'insieme {0, 0.01, ... , 0.99,1}
//che rende minima la funzione f(x)=|x-cosx|

int main() {
  double passo;
  cout << "Inserisci il passo ";
  cin >> passo;
  double p=0, min=1;
  for (double i=0; i<=1; i=i+passo) {
    double funzione=abs(i-cos(i));
    if (funzione<=min) {
      p=i;
      min=funzione;
    }
  }
  cout << "Il valore che rende minima f(x) è x="<<p<<" e f(x)="<<min<<endl;
}
