
#include <bits/stdc++.h>
using namespace std;

int check(int x) {
    string s = to_string(x);
    string s2 = "";
    for(int i = s.length() -1; i>=0; i--) {
        s2 += s[i];
    }
    if (s.compare(s2) == 0) return 1;
    return 0;
}

int result(int a, int b) {
    int count = 0;
    for(int i =a; i<=b; i++) {
        count += check(i);
    }
    return count;
}

int main() {
    int n;
    cin>> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        cout<<result(a,b)<<endl;
    }
    
    return 0;
}