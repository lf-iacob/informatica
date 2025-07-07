#include <iostream>
using namespace std;

class conto_corrente {
private:
  int codice;
  string nominativo;
  double saldo;
public:
  conto_corrente(int codice, string nominativo, double saldo);
  bool preleva (double x);
  void versa (double x);
  double saldo_corrente();
  void situazione();
  bool bonifico (conto_corrente &c, double x);
  static int num_conti();
};

conto_corrente::conto_corrente(int cod, string nom, double saldo_iniz) {
  codice=cod;
  nominativo=nom;
  saldo=saldo_iniz;
}

void conto_corrente::versa(double x){
  saldo = saldo+x;
}

double conto_corrente::saldo_corrente() {
  return saldo;
}

bool conto_corrente::bonifico(conto_corrente &c, double x) {
  if (saldo<x)
    return false;
  saldo=saldo-x;
  c.saldo=c.saldo+x;
  return true;
}

int main() {
  conto_corrente c1(22, "Lorenzo Ciculo", 3000);
  conto_corrente c2=c1;
  c1.versa(50);
  cout << "Saldo di c2 dopo versamento in c1: " << c2.saldo_corrente() << endl;
  conto_corrente m (109, "Matteo Ioele", 681);
  conto_corrente l (247, "Leonardo Salvi", 100);
  bool ris = m.bonifico(l,50);
  cout << "Saldo di Matteo dopo il bonifico " << m.saldo_corrente() << endl;
  cout << "Saldo di Leo dopo il bonifico " << l.saldo_corrente() << endl;
}
