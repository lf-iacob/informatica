#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct COPPIA{
  int x, y;
};

vector<COPPIA> fatt(int n){
  vector<COPPIA> vett(n);
  int j=0,i=2,n_pr;
  do{
    int s=0;
    do{
      n_pr=n;
      if(n%i==0){
        vett[j].x=i;
        s++;
        n=n/i;
      }
    }while(n_pr%i==0);
    vett[j].y=s;
    i++; j++;
  }while(n!=1);
  vett.resize(j);
  return vett;
}

int main() {
  int num;
  cout<<"Inserisci il numero ";
  cin>>num;
  vector<COPPIA> f=fatt(num);
  int d=f.size();
  cout<<"La fattorizzazione è "<<endl<<num<<" = ";
  for(int i=0; i<d; i++){
    if(f[i].x!=0){
      cout<<f[i].x<<"^"<<f[i].y;
      if(i!=d-1)
        cout<<"+";
    }
  }
}
