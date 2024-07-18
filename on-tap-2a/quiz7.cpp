
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n], b[n];
    int minA = INT_MAX, minB = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin>>a[i]>>b[i];
        if(a[i] < minA) minA = a[i];
        if(b[i] < minB) minB = b[i];
    }
    cout<< minA * minB;
    

    return 0;
}