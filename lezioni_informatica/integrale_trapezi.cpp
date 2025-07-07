#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a,b, somma=0;
  int n;
  cout << "Inserisci intervallo integrazione [a,b]: ";
  cin >> a >> b;
  cout << "In quanti sotto-range vuoi dividere l'intervallo? ";
  cin >> n;
  double h=(b-a)/n, trapezio;
  for (int i=0; i<n; i++) {
    trapezio=(h/2)*(pow(a+i*h,2)+pow(a+(i+1)*h,2));
    somma=somma+trapezio;
  }
  cout << "Il risultato calcolato è " << somma <<endl;
  double integrale_esa=(pow(b,3)/3)-(pow(a,3)/3);
  cout << "Il valore esatto è " << integrale_esa <<endl;
  cout << "L'errore compiuto è circa pari a " << integrale_esa-somma <<endl;

  // Gaussiana
  cout << "GAUSSIANA [-1;1]"<<endl;
  double alfa=-1, beta=1, sum=0;
  int m;
  cout << "In quanti sotto-range vuoi dividere l'intervallo? ";
  cin >> m;
  double k=(beta-alfa)/m, trap;
  for (int i=0; i<m; i++) {
    trap=(k/2)*(exp(-pow(alfa+i*k,2)/2)+exp(-pow(alfa+(i+1)*k,2)/2));
    sum=sum+trap;
  }
  cout << "Il risultato calcolato è " << (1/sqrt(2*M_PI))*sum <<endl;
  cout << "Il valore atteso è 0.68 circa" <<endl;
}
