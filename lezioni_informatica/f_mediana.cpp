#include <iostream>
using namespace std;
#include <algorithm>
#define N 7

double mediana(double x[], int n){
  double ris;

  cout<<"Array ordinato"<<endl;
  sort(x, x+n);
  for(int i=0; i<N; i++)
    cout<<x[i]<<" ";
  cout<<endl;
  
  if(n%2==0)
    ris=(x[(n/2)-1]+x[n/2])/2;
  else
    ris=x[(n-1)/2];
  return ris;
}

int main() {
  double a[N];
  cout<<"Inserisci array ";
  for(int i=0; i<N; i++)
    cin>>a[i];
  double med=mediana(a,N);
  cout<<"La mediana è "<<med<<endl;
}
