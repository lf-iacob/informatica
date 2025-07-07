#include <iostream>
using namespace std;

int main() {
  while (true) {
  int n;
  cout << "Inserisci il numero intero tra 1 e 99: ";
  cin>>n;
  cout << "Hai inserito il numero ";
    switch (n/10) {
    case 1:
      cout << "dieci";
      break;
    case 2:
      cout<<"venti";
      break;
    case 3:
      cout<<"trenta";
      break;
    case 4:
      cout<<"quaranta";
      break;
    case 5:
      cout<<"cinquanta";
      break;
    case 6:
      cout<<"sessanta";
      break;
    case 7:
      cout<<"settanta";
      break;
    case 8:
      cout<<"ottanta";
      break;
    case 9:
      cout<<"novanta";
      break;
    }
    switch (n%10) {
    case 1:
      cout<<"uno";
      break;
    case 2:
      cout<<"due";
      break;
    case 3:
      cout<<"tre";
      break;
    case 4:
      cout<<"quattro";
      break;
    case 5:
      cout<<"cinque";
      break;
    case 6:
      cout<<"sei";
      break;
    case 7:
      cout<<"sette";
      break;
    case 8:
      cout<<"otto";
      break;
    case 9:
      cout<<"nove";
      break;
    }
  cout <<endl;
  }
}
