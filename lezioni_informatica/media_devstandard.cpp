#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  double x, somma=0, somma_q=0;
  cout << "Quanti numeri vuoi inserire? ";
  cin>>n;
  cout << "Inserisci i numeri: ";
  for (int i=0; i<n; i++) {
    cin>>x;
    somma+=x;
    somma_q+=(x*x);
  }
  cout<<"La media è "<<somma/n<<endl;
  cout<<"La deviazione standard è "<<sqrt((somma_q/n)-pow((somma/n),2))<<endl;
}
