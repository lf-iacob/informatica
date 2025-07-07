#include <iostream>
#include <cmath>
using namespace std;

int main() {
  string scelta;
  cout << "Scegli il gioco: " <<endl;
  cout << "a Scopri se un numero è perfetto"<<endl;
  cout << "b Scopri i numeri perfetti in un intervallo"<<endl;
  cin >> scelta;
  if (scelta=="a") {
  int num, somma=0;
  cout << "Inserisci numero ";
  cin >> num;
  for (int i=1; i<=num/2; i++) {
    if (num%i==0) 
      somma=somma+i;
  }
  if (somma==num)
    cout << "Il numero è perfetto!" << endl;
  else
    cout << "Il numero non è perfetto :(" << endl;
  }
  if (scelta=="b") {
  int a,b;
  cout << "Inserisci estremi intervallo [a,b]: ";
  cin >> a >> b;
  for (int j=a; j<=b; j++) {
    int somma=0;
    for (int i=1; i<=j/2; i++) {
      if (j%i==0)
        somma=somma+i;
    }
    if (somma==j)
      cout << "Il numero " <<j<<" è perfetto!" << endl;
  }
  }
}
