#include <iostream>
#include <set>

using namespace std;

int main() {
  int num1, num2, num3, med;
  cout << "Inserisci tre numeri ";
  cin >> num1 >> num2 >> num3;
  if ((num1<=num2 && num2<=num3) || (num3<=num2 && num2<=num1))
    med=num2;
  else if ((num2<=num1 && num1<=num3) || (num3<=num1 && num1<=num2))
    med=num1;
  else if ((num1<=num3 && num3<=num2) || (num2<=num3 && num3<=num1))
    med=num3;
  cout << "La mediana è " << med <<endl;
}
