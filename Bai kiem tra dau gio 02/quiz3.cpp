#include <iostream>  

using namespace std;  

int main() {  
    int m, n;
    cin >> m >> n;  

    int a[m][n];
    for (int i = 0; i < m; ++i) {  
        for (int j = 0; j < n; ++j) {  
            a[i][j]=0;  
        }  
    }

    int value = 0; 
    int row = 0, col = 0;  
    int x = m, y = n;

    while (value <= x * y - 1) {  
        for (int i = col; i < n && a[row][i] == 0; i++) {  
            a[row][i] = value+=1;  
        }  
        for (int i = row + 1; i < m && a[i][n-1] == 0; i++) {  
            a[i][n-1] = value+=1;  
        }  
        for (int i = n - 2; i >= col && a[m-1][i] == 0; i--) {  
            a[m-1][i] = value+=1;  
        }  
        for (int i = m - 2; i > row && a[i][col] == 0; i--) {  
            a[i][col] = value+=1;  
        }  
        row++;  
        col++;  
        m--;  
        n--;  
    }  

    for (int i = 0; i < x; i++) {  
        for (int j = 0; j < y; j++) {  
            cout << a[i][j] << " "; 
        }  
        cout << endl;  
    }  

    return 0;
}