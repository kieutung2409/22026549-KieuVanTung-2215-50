class Student {  
    int arr[5];  

public:  
    void input() {
        for (int i = 0; i<5; i++) {
            cin>>arr[i];
        }
    }  
    int calculateTotalScore() {
        int sum = 0;
        for (int i = 0; i<5; i++) {
            sum += arr[i];
        }
        
        return sum;
    }
}; 