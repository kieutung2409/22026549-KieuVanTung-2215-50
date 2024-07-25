class Student {  
    int age;  
    string first_name;  
    string last_name;  
    int standard;  

public:  
 
    void set_age(int Age) {  
        age = Age;  
    }  
    int get_age() const {  
        return age;  
    }  

    void set_standard(int Standard) {  
        standard = Standard;  
    }  
    int get_standard() const {  
        return standard;  
    }  
 
    void set_first_name(const string &First_name) {  
        first_name = First_name;  
    }  
    string get_first_name() const {  
        return first_name;  
    }  
  
    void set_last_name(const string &Last_name) {  
        last_name = Last_name;  
    }  
    string get_last_name() const {  
        return last_name;  
    }  

    string to_string() const {  
        stringstream ss;  
        ss << age << "," << last_name << "," << first_name << "," << standard;  
        return ss.str();  
    }  
}; 