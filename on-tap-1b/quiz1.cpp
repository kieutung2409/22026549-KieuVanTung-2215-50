#include<bits/stdc++.h>

using namespace std;
int main() {
    int a;
    while (a>=0) {
        int b;
        cin >> b;
        if ( b!= a) {
            cout<< b<< " ";
        }
        a = b;
    }
    return 0;
}