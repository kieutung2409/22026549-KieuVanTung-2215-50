#include<bits/stdc++.h>

using namespace std;
int main() {
  double a, b, c;
  cin >> a>>b>>c;
  
  if (a <= 0 || b <= 0 || c <= 0) cout << "Invalid";
  else {
    if (a + b <= c || a + c <= b || b + c <= a) cout << "Invalid";
    else {
      if (a == b && b == c && a == c) {
          cout<<a+b+c<<endl;
          cout << "deu";
      }
      else {
        if (a == b || b == c || c == a) {
            cout<<a+b+c<<endl;
            cout << "can";
        }
        else {
          if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
              cout<<a+b+c<<endl;
              cout << "vuong";
          } else {
              cout<<a+b+c<<endl;
              cout << "thuong";
          }
        }
      }
    }
  }
}