struct Complex {
    int a;
    int b;
    
    Complex() : a(0), b(0) {}
    
    Complex(int _a, int _b) : a(_a), b(_b) {}

    double abs() {
        return sqrt(a*a + b*b);
    }
    
    void print() {
        if (a == 0 && b == 0) {  
            cout << "0" << endl;  
            return;  
        }  

        if (a != 0) {
            cout << a;  
        }  

        if (b != 0) {  
            if (b > 0) {  
                if (a != 0) cout << "+"; 
            } else {  
                cout << "-";
            }  

            if (b == 1 || b == -1) {  
                cout << "i";  
            } else {
                if (b>0) cout << b << "i";
                else cout << -b << "i";
            }  
        }  

        cout << endl;
    }
};

Complex add(Complex a, Complex b) {
    Complex sum(a.a + b.a, a.b + b.b);
    return sum;
}