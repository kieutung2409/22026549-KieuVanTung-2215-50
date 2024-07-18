
#include <bits/stdc++.h>
using namespace std;

int result(int x) {
    int sum = 0;
    int m = x;
    while(m>0) {
        int a = m%10;
        if (a!=0 && x%a==0) sum+=1;
        m/=10;
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    for(int i =0; i<n; i++) {
        int x;
        cin>>x;
        cout<<result(x)<<endl;
    }

    return 0;
}