#include <iostream>
using namespace std;

int fattoriale(int x) {
  int prodotto=1;
  for (int i=1; i<=x; i++) {
    prodotto=prodotto*i;
  }
  return prodotto;
}

int main() {
  int n, k;
  cout << "Inserisci n e k: ";
  cin >> n >> k;
/* int den=fattoriale(k), prodotto=1;
  for (int i=n-k+1; i<=n; i++){
    prodotto=prodotto*i;
  }
  cout << "Il risultato è "<<prodotto/den<<endl;
  cout << "Il risultato dovrebbe essere "<<fattoriale(n)/(fattoriale(n-k)*fattoriale(k))<<endl; */
  int den=1, num=1;
  for (int i=n-k+1; i<=n; i++)
    num=num*i;
  for (int i=1; i<=k; i++)
    den=den*i;
  cout << "Il risultato è "<<num/den<<endl;
  
  int den=1, num=1;
  for (int i=1; i<=k; i++) {
    den=den*i;
    num=num*(n-k+i);
  }
  cout << "Il risultato è "<<num/den<<endl;
}
