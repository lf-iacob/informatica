#include <iostream>

using namespace std;

int main() {
  int n, somma=0;
  cout << "Inserisci numero ";
  cin >> n;
  cout << "I divisori di " << n << " sono i seguenti: ";
  for (int i=2; i<=n/2; i++) {
    if (n%i==0) {
      cout << i << " ";
      somma=somma+1;
    }
  }
  cout << endl<< "Numero totale di divisori: "<<somma<<endl;
}
