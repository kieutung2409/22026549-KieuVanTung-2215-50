
#include <bits/stdc++.h>
using namespace std;

void print(int a[], int size, int x, int y) {
    int sumx = 0, sumy = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) sumx +=1;
        else sumy +=1;
    }
    if (sumx == x && sumy == y) {
        for (int i = 0; i < size; i++) {
            cout<<a[i];
        }
        cout << endl;
    }

} 

int main() {
    int x,y;
    cin >> x>> y;
    int n = x + y;
    if (n == 1) {
        if (x==0) cout<< 0;
        else cout<< 1;
        return 0;
    }
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    for (int i = n-1; i > 0; i--) {
        if (a[i] == 0 || (a[i] == 1 && a[i-1] == 0)) {
            if (a[i] == 0) {
                print(a, n, x, y);
                a[i] = 1;
                i = n;
            } else {
                print(a, n, x, y);
                a[i-1] = 1;
                a[i] = 0;
                i = n;
            }
        }
        else {
            for (int j = i-1 ; j >= 0; j--) {
                if(a[j] == 0) {
                    print(a, n, x, y);
                    for (int k = j+1; k < n; k++) {
                        a[k] = 0;
                    }
                    a[j] = 1;
                    i = n;
                    break;
                }
                else if (j == 0) {
                    print(a, n, x, y);
                    i = 0; //break
                }
            }
        }
    }
    
    return 0;
}