
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int j = 0; j<n; j++) {
        a[j] = j +1;
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if(i+j >= n) {
                cout<< a[i+j-n]<<" ";
            } else {
                cout<< a[i+j]<<" ";
            }
            if (j==n-1) cout<<endl;
        }
    }

    return 0;
}