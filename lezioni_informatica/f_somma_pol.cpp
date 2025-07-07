#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<double> spol(vector<double> &a, vector<double> &b){
  int n=a.size(), m=b.size();
  int l=max(n,m);
  vector<double> c(l);
  for(int i=0; i<l; i++){
    if(i<=min(n,m))
      c[i]=a[i]+b[i];
    else{
      if(n>=m)
        c[i]=a[i];
      if(n<m)
        c[i]=b[i];
    }
  }
  return c;
}

void print_v(vector<double> v){
  int n=v.size();
  for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
}

int main() {
  int d1, d2;
  cout<<"Inserisci il grado dei polinomi ";
  cin>>d1>>d2;
  double dim1=d1+1, dim2=d2+1;
  vector<double> v1(dim1), v2(dim2);
  cout<<"Inserisci coefficienti: primo polinomio ";
  for(int i=0; i<dim1; i++)
    cin>>v1[i];
  cout<<"Inserisci coefficienti: secondo polinomio ";
  for(int i=0; i<dim2; i++)
    cin>>v2[i];
  vector<double> v3=spol(v1,v2);
  cout<<"Il nuovo polinomio ha coefficienti"<<endl;
  print_v(v3);
}
