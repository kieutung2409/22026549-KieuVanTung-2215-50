class BadLengthException : public exception {  
    
public:  
    BadLengthException(int length) : length_(length) {}  

    virtual const char* what() const noexcept override {  
        return msg_.c_str();  
    }  

private:  
    int length_;
    string msg_ = to_string(length_);
}; 