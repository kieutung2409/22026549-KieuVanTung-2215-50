
#include <bits/stdc++.h>
using namespace std;

bool check(long long a[], int left, int right, long long x) { 
    
    int mid = (left + right)/2;
    if (mid == left && mid == right) {
        if (x == a[mid]) return 1;
        return 0;
    } else {
        if ( x == a[mid]) return 1;
        else if (x > a[mid]) return check(a, mid+1, right, x);
        else return check(a, left, mid-1, x);
    } 
    
    return 0;
}  

int main() {
    int m, n;
    cin>>m >>n;
    long long a[m], b[n];
    for(int i = 0; i < m; i++) {
        cin >>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
         if (check(a, 0, m-1, b[i]) == 1) cout<<"YES ";
        else cout<<"NO ";
    }

    return 0;
}