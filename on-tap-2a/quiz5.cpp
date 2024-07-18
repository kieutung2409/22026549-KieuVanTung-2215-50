
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a,b;
    cin>>a>>b;
    if (a==0 || b==0) cout<<0;
    else {
        a= abs(a);
        b= abs(b);
        cout<<lcm(a,b);
    }

    return 0;
}