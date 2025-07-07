#include <iostream>
using namespace std;

int main() {
  int n;
  double m,k,x_0,v_0,t;
  cout << "Inserisci massa ";
  cin >> m;
  cout << "Inserisci costante elastica ";
  cin >> k;
  cout << "Inserisci posizione iniziale ";
  cin >> x_0;
  cout << "Inserisci velocità iniziale ";
  cin >> v_0;
  cout << "Inserisci discretizzazione ";
  cin >> n;
  cout << "Inserisci intervallo di tempo ";
  cin >> t;
  double dt=t/n;
  double posizione=x_0, velocita=v_0, posizione_1=x_0;
  cout << "Coordinate di fase per istanti discreti successivi"<<endl<<"POSIZIONE"<<"\t"<<"VELOCITA'"<<endl<<"\t"<<posizione<<"\t"<<velocita<<endl;
  for (int i=1; i<=n; i++) {
    posizione_1=posizione;
    posizione=posizione+(velocita*dt);
    velocita=velocita-((k/m)*posizione_1*dt);
    cout << "\t"<< posizione << "\t" << velocita << endl;
  }
}
