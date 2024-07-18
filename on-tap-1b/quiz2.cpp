#include<bits/stdc++.h>

using namespace std;
int main() {
    int x;
    cin>>x;
    int a[x];
    for (int i =0; i<x; i++) {
        cin>> a[i];
    }
    sort(a, a+ x);
    int y = a[1] - a[0];
    for (int i =1; i<x-1; i++) {
        if (y > a[i+1] - a[i]) y = a[i+1] -  a[i];
    }
    cout<<y;
    return 0;
}