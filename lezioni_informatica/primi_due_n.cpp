#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n_max;
  cout << "Scegli fine intervallo ";
  cin >> n_max;
  cout<<"NUMERI PRIMI (2^n-1)"<<endl;
  for (int i=2; i<=n_max; i++){
    bool primo=true;
    for (int j=2; j<=i/2; j++){
      if (j%i==0){
        primo=false;
        break;
      }
    }
    if(primo==true){
      for(int n=1; n<=31; n++){
        if(i==pow(2,n)-1)
          cout<<"Il numero primo "<<i<<" usa n="<<n<<endl;
      }
    }
  }
}
