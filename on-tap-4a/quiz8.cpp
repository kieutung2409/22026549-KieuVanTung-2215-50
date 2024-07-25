#include <iostream>  
#include <vector>  

using namespace std;  

bool isSubarray(const vector<int>& a, const vector<int>& b) {  
    int n = a.size();  
    int m = b.size();  

    if (n > m) {  
        return false;  
    }  

    for (int i = 0; i <= m - n; ++i) {  
        bool found = true;  
        for (int j = 0; j < n; ++j) {  
            if (a[j] != b[i + j]) {  
                found = false;  
                break;  
            }  
        }  
        if (found) {  
            return true; 
        }  
    }  
    
    return false;
}  

int main() {  
    int n;  
    cin >> n;  
    vector<int> a(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> a[i];  
    }  

    int m;  
    cin >> m;  
    vector<int> b(m);  
    for (int i = 0; i < m; ++i) {  
        cin >> b[i];  
    }  
 
    if (isSubarray(a, b)) {  
        cout << "YES" << endl;  
    } else {  
        cout << "NO" << endl;  
    }  

    return 0;  
}