
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
    bool check = true;
    if(a*b<0) {
        check = false;
        a = abs(a);
        b = abs(b);
    }
    int ucln = UCLN(a,b);
    a = a/ucln;
    b = b/ucln;
    if(b==1) {
        if(check == false) {
            cout<<-a;
        } else cout<<a;
    } else {
        if(check == false) {
            cout<<-a<<"/"<<b;
        } else cout<<a<<"/"<<b;
    }

    return 0;
}