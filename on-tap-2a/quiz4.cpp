
#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b) {
    int x = min(a,b);
    int y = max(a,b);
    if (y%x==0) return x;
    return UCLN(b%a,a);
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<UCLN(a,b);

    return 0;
}