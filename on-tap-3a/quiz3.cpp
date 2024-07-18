
#include <bits/stdc++.h>
using namespace std;

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<a[i];
    }
    cout << endl;
} 

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout<<0<<endl<<1<<endl;
        return 0;
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i] == 0 || (a[i] == 1 && a[i-1] == 0)) {
            if (a[i] == 0) {
                print(a, n);
                a[i] = 1;
                i = n;
            } else {
                print(a, n);
                a[i-1] = 1;
                a[i] = 0;
                i = n;
            }
        }
        else {
            for (int j = i-1 ; j >= 0; j--) {
                if(a[j] == 0) {
                    print(a, n);
                    for (int k = j+1; k < n; k++) {
                        a[k] = 0;
                    }
                    a[j] = 1;
                    i = n;
                    break;
                }
                else if (j == 0) {
                    print(a, n);
                    i = 0; //break
                }
            }
        }
    }
    
    return 0;
}