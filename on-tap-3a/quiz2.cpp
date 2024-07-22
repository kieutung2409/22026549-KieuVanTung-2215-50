
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int left, int right, int value) {
    if (left > right) 
        return false;
    int mid = (left + right) /2;
    if (arr[mid] == value) 
        return true;
    if (arr[mid] < value) {
        return binarySearch(arr, mid + 1, right, value);
    }
    if (arr[mid] > value) {
        return binarySearch(arr, left, mid - 1, value);
    }
    return false;
}

int main() {
    int m, n;
    cin>>m >>n;
    int a[m], b[n];
    for(int i = 0; i < m; i++) {
        cin >>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
         if (binarySearch(a, 0, m-1, b[i])) cout<<"YES ";
        else cout<<"NO ";
    }

    return 0;
}