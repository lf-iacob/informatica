#include <iostream>
using namespace std;

class vettore{
private:
  double x1,x2,x3;
public:
  vettore(double a, double b, double c){
    x1=a; x2=b; x3=c;
  };
  vettore(){
    x1=0; x2=0; x3=0;
  };
  void scrivi();
  void leggi();
  static vettore* somma(vettore *v1, vettore *v2);
  static vettore* prodotto(double k, vettore *v);
  static double prodotto_scalare(vettore *v1, vettore *v2);
  static vettore* prodotto_vettoriale(vettore *v1, vettore *v2);
};

void vettore::scrivi(){
  cout<<x1<<" "<<x2<<" "<<x3;
}
void vettore::leggi(){
  cout<<"Inserisci le coordinate del vettore ";
  cin>>x1>>x2>>x3;
}
vettore* vettore::somma(vettore *v1, vettore *v2){
  vettore *p;
  p=new vettore(v1->x1+v2->x1, v1->x2+v2->x2, v1->x3+v2->x3);
  return p;
}
vettore* vettore::prodotto(double k, vettore *v){
  vettore *p;
  p=new vettore(k*v->x1, k*v->x2, k*v->x3);
  return p;
}
double vettore::prodotto_scalare(vettore *v1, vettore *v2){
  return v1->x1*v2->x1+v1->x2*v2->x2+v1->x3*v2->x3;
}
vettore* vettore::prodotto_vettoriale(vettore *v1, vettore *v2){
  vettore *p;
  double i=(v1->x2*v2->x3)-(v2->x2*v1->x3);
  double j=(v2->x1*v1->x3)-(v1->x1*v2->x3);
  double k=(v1->x1*v2->x2)-(v2->x1*v1->x2);
  p=new vettore(i,j,k);
  return p;
}

int main() {
  vettore *v, *w;
  v=new vettore();
  w=new vettore();
  cout<<"v: ";
  v->leggi();
  cout<<"w: ";
  w->leggi();
  cout<<"Inserisci fattore moltiplicativo k ";
  double cost;
  cin>>cost;

  cout<<"PRODOTTO kv ";
  vettore::prodotto(cost, v)->scrivi();
  cout<<endl<<"PRODOTTO kw ";
  vettore::prodotto(cost, w)->scrivi();
  cout<<endl<<"SOMMA v+w ";
  vettore::somma(v,w)->scrivi();
  cout<<endl<<"PRODOTTO SCALARE v.w "<<vettore::prodotto_scalare(v,w);
  cout<<endl<<"PRODOTTO VETTORIALE vxw ";
  vettore::prodotto_vettoriale(v,w)->scrivi();
  
  delete v;
  delete w;
}
