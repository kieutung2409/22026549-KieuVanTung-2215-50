
#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    string s2 = "";
    for(int i = s.length() -1; i>=0; i--) {
        s2 += s[i];
    }
    if (s.compare(s2) == 0) return 1;
    return 0;
}

int main() {
    string s;
    cin>> s;
    if (check(s)==1) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
