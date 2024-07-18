#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ones = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string helper(int n) {
    if (n < 10) {
        return ones[n];
    } else if (n < 20) {
        return teens[n - 11];
    } else if (n < 100) {
        return tens[n / 10] + (n % 10 == 0 ? "" : "-" + ones[n % 10]);
    } else if (n < 1000) {
        return ones[n / 100] + " hundred" + (n % 100 == 0 ? "" : " " + helper(n % 100));
    }
    return "";
}

string readNumber(int num) {
    if (num < 0) {
        return "negative " + readNumber(-num);
    }
    if (num == 0) {
        return "zero";
    }
    
    vector<string> units = {"", "thousand", "million"};
    string result = "";
    
    for (int i = 0; num > 0; ++i) {
        if (num % 1000 != 0) {
            result = helper(num % 1000) + (units[i] == "" ? "" : " " + units[i]) + (result == "" ? "" : " " + result);
        }
        num /= 1000;
    }
    
    return result;
}

int main() {
    int number;
    cin >> number;
    
    cout << readNumber(number) << endl;
    
    return 0;
}