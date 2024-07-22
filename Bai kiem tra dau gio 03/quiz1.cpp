
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    bool check = 1;
    for (int i = 0; i< n/2; i++) {
        if (s[i] != s[n-1-i]) {
            cout<<"No";
            check = 0;
            break;
        }
    }
    if ( check == 1) {
        cout<<"Yes";
    }

    return 0;
}