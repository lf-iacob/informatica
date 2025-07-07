#include <iostream>
#define N 3
using namespace std;

int main() {
  cout<<"Inserisci il numero di tre cifre ";
  int num;
  cin>>num;
  int v[N];
  for (int i=2; i>=0; i--) {
    int carry=num%10;
    v[i] = carry;
    num=num/10;
  }
  for (int i=0; i<3; i++)
    cout << v[i] <<" ";
}
