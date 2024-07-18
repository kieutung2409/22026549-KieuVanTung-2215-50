#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    if (x==2) return 1;
    for(int i =2; i*i <=x; i++) {
        if (x%i==0) return 0;
    }
    return 1;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++) {
        cin >>a[i];
    }
    for(int i = 0; i<n; i++) {
        if (check(a[i])==1) cout<<a[i]<<" ";
    }

    return 0;
}