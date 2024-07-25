#include <iostream>  
#include <vector>  

using namespace std;  

int main() {  
    int n;  
    cin >> n;  
    vector<int> count(n + 1, 0); 

    int original_n = n;

    while (n != 1) {  
        for (int i = 2; i <= n; i++) {  
            if (n % i == 0) {  
                count[i]++;
                n /= i;  
                i--;
            }  
        }  
    }  

    for (int i = 2; i <= original_n; i++) {  
        if (count[i] > 0) {  
            cout << i << " " << count[i] << endl;  
        }  
    }  

    return 0;  
}