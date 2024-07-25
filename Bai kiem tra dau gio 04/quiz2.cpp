// Toán tử in ra màn hình
ostream& operator<<(ostream& os, const BigInt& num)
{
    os << num.value;
    return os;
}

// Hàm khởi tạo
BigInt::BigInt() 
{
    value = "0";
}

BigInt::BigInt(const char *num)
{
    value = num;
}

BigInt::BigInt(const BigInt& num)
{
    value = num.value;
}

// Toán tử cộng
BigInt operator+(const BigInt& num, const BigInt& other)
{
    string num1 = num.value;  
        string num2 = other.value;  
        string result;  

        int carry = 0;  
        int i = num1.length() - 1;  
        int j = num2.length() - 1;  
  
        while (i >= 0 || j >= 0 || carry > 0) {  
            int digit1 = (i >= 0) ? (num1[i] - '0') : 0;  
            int digit2 = (j >= 0) ? (num2[j] - '0') : 0;  

            int sum = digit1 + digit2 + carry;  
            carry = sum / 10; 
            result.push_back((sum % 10) + '0');

            i--;  
            j--;  
        }  
  
        string final;  
        for (int k = result.length() - 1; k >= 0; k--) {  
            final.push_back(result[k]);  
        }  

        return BigInt(final.c_str());
}
