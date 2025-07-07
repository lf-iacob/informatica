#include <iostream>

using namespace std;

int main() {
  while (true) {
  int num, somma=0, carry;
  cout << "Inserisci il numero intero tra 1 e 10^7: ";
  cin >> num;
  for (int i=0; i<6; i++) {
    carry = num%10;
    num=num/10;
    if (carry!=0 || num!=0)
      somma=somma+1;
  }
  cout << "Il numero inserito ha "<<somma<<" cifre"<<endl;
  }
}
