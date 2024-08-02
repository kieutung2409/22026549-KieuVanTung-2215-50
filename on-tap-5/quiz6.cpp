void reverse(char *s) {

    if (s == nullptr || *s == '\0') {  
        return;  
    }

    char *left = s; 
    char *right = s + strlen(s) - 1; 

    while (left < right) {  
        swap(*left, *right);  
        left++;
        right--;  
    }
}