#include <iostream>
#include <vector>
using namespace std;

/* vector <int> sq_matrix(int x) {
  cout << "Inserisci gli elementi della matrice" << endl;
  int num;
  vector <int> v;
  for (int j=0; j<x; j++) {
    cin >> num;
    v.push_back(num);
  }
  return v;
}

void pp_sq_matrix(int x, vector <int> v) {
  for (int i=0; i<x; i++) {
    for (int j=0; j<x; j++)
      cout << v[i+j] << " ";
    cout << endl;
  }
} */

int main() {
  string dim;
  cout << "Scegli dimensione matrice quadrata:"<<endl<<"a 2x2"<<endl<<"b 3x3"<<endl;
  cin >> dim;
  int num, det;
  cout << "Inserisci i numeri"<< endl;

  if (dim=="a") {
    int v[2][2];
    for (int i=0; i<2; i++) {
      for (int j=0; j<2; j++) {
        cin >> num;
        v[i][j]=num;
      }
    }
    for (int i=0; i<2; i++) {
      cout << "| ";
      for (int j=0; j<2; j++) {
      cout << v[i][j] << "\t";
      }
      cout << "|" <<endl;
    }
    det=(v[0][0]*v[1][1])-(v[0][1]*v[1][0]);
  } else {
    int v[3][3];
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        cin >> num;
        v[i][j]=num;
      }
    }
    for (int i=0; i<3; i++) {
      cout << "| ";
      for (int j=0; j<3; j++) {
      cout << v[i][j] << "\t";
      }
      cout << "|"<<endl;
    }
    det=(v[0][0]*v[1][1]*v[2][2])+(v[0][1]*v[1][2]*v[2][0])+(v[0][2]*v[1][0]*v[2][1])-(v[2][0]*v[1][1]*v[0][2])-(v[2][1]*v[1][2]*v[0][0])-(v[2][2]*v[1][0]*v[0][1]);
    }
  cout << "Il determinante è " << det << endl;
}
