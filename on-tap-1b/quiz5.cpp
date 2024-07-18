#include<bits/stdc++.h>

using namespace std;
int main() {
    int sum;
    for (int i =0; i<5; i++) {
        int a;
        cin>>a;
        sum+=a;
    }
    cout<<fixed<<setprecision(2)<<(double)sum/5;
    
    return 0;
}