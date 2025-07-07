#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double media(vector<double> &v){
  int n=v.size();
  double somma=0;
  for (double x:v)
    somma=somma+x;
  double m=somma/n;
  return m;
}

double varianza(vector<double> &v){
  int n=v.size();
  double somma_q=0;
  for (double x:v)
    somma_q=somma_q+(x*x);
  double m=media(v);
  double var=(somma_q/n)-(m*m);
  return sqrt(var);
}

vector<double> selection(vector<double> &v, double t){
  double m=media(v);
  double s=varianza(v);
  int n=v.size();
  vector<double> w;
  for(int i=0; i<n; i++){
    if(abs(v[i]-m)>(t*s))
      w.push_back(v[i]);
  }
  return w;
}

void print_v(vector<double> v){
  int n=v.size();
  for(int i=0; i<n; i++)
    cout<<v[i]<<" ";
}

int main() {
  int dim;
  cout<<"Inserisci la dimensione del vector ";
  cin>>dim;
  vector<double> a(dim);
  cout<<"Inserisci elementi ";
  for(int i=0; i<dim; i++)
    cin>>a[i];
  cout<<"Inserisci parametro di selezione ";
  double par;
  cin>>par;
  vector<double> vec=selection(a, par);
  cout<<"Il nuovo vector ha dimensione "<<vec.size()<<endl;
  print_v(vec);
}
