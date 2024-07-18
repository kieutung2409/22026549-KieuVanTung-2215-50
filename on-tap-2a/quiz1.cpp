
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) {
        cin>>a[i];
    }
    sort(a, a+n);
    int result = 0;
    for (int i = 0 ; i< n-1; i++) {
        int j = i+1;
        int temp = 1;
        while(j<n) {
            if (a[j]-a[i] <= 1) {
                temp += 1;
                j++;
                result = max(result,temp);
            } else {
                result = max(result,temp);
                j = n;
            }
        }
    }
    cout<<result;

    return 0;
}