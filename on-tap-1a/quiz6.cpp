#include<bits/stdc++.h>

using namespace std;
int main() {
    int x;
    cin>>x;
    if(x<0) {
        cout<<"NO";
        return 0;
    }
    for (int i = 0; i <= sqrt(x) ; i++) {
        if (i*i == x) {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    
    return 0;
}