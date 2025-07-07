#include <iostream>
using namespace std;
#define N 231

int main() {
  bool b[N];
  for (int i=0; i<N; i++)
    b[i]=true;

  int d=2;
  for (int j=d+1; j<N; j++){
    for (int n=d+1; n<N; n++){
      if (n%d==0)
        b[n]=false;
    }
    if (b[j]==true)
      d=j;
  }

  cout << "I numeri primi sono"<<endl;
  for(int i=2; i<N; i++){
    if (b[i]==true)
      cout <<i<<" ";
  }
}
