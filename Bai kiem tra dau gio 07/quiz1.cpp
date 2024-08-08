#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string multiply(const string &a, int b) {
    string result = "";
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; --i) {
        int temp = (a[i] - '0') * b + carry;
        result += (temp % 10) + '0';
        carry = temp / 10;
    }

    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    string result = multiply(a, b);
    cout << result << endl;

    return 0;
}