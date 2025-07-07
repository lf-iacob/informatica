#include <iostream>
using namespace std;

int main() {
  int n_max, somma=0;
  cout << "Inserisci fine intervallo: ";
  cin >> n_max;
  for (int j=2; j<=n_max; j++) {
    bool primo=true;
    for (int i=2; i<=j/2; i++) {
      if (j%i==0) {
        primo=false;
        break;
      }
    }
    if (primo==true) {
      somma=somma+1;
      cout << j << " è un numero primo."<<endl;
    }
  }
  cout << "Nell'intervallo scelto ci sono "<<somma<<" numeri primi"<<endl;
}
