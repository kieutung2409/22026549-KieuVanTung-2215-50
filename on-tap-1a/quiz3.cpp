#include<bits/stdc++.h>

using namespace std;
int main() {
  double x1, v1, x2, v2;
  cin >> x1 >> v1 >> x2 >> v2;
  
  if (x1<=x2 && v1>v2) {
      while (x1 < x2)
      {
		x1 += v1;
		x2 += v2;
		if (x1 == x2) {
		    cout<<"YES";
		    return 0;
		}
      }
      cout<<"NO";
  } else if (x2<=x1 && v2>v1) {
      while (x1 < x2)
      {
		x1 += v1;
		x2 += v2;
		if (x1 == x2) {
		    cout<<"YES";
		    return 0;
		}
      }
      cout<<"NO";
  } else {
      cout<<"NO";
  }
  
  return 0;
}