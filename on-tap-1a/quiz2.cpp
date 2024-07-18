#include<bits/stdc++.h>

using namespace std;
int main() {
  double a1, b1, c1, a2, b2, c2;
  cin >> a1>>b1>>c1 >>a2>>b2>>c2;
  
  int D = a1 * b2 - a2 * b1;
  int Dx = c1 * b2 - c2 * b1;
  int Dy = a1 * c2 - a2 * c1;
  if (D == 0) {
   
    if (Dx + Dy == 0)
      cout<<"Vo so nghiem";
    else
      cout<<"Vo nghiem";
    }

  else {
    double x = Dx / D;
    double y = Dy / D;
    cout<< "x = ";
    cout<<x;
    cout<<", y = ";
    cout<<y;
  }
  
}