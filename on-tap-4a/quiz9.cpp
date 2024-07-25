string decimal_to_binary(long number) {  
    if (number == 0) {  
        return "0";
    }  
    
    string binary = "";  
    
    while (number > 0) {  
        int remainder = number % 2;  
        binary += to_string(remainder);  
        number /= 2;  
    }  
    
    reverse(binary.begin(), binary.end());  
    return binary;  
}  