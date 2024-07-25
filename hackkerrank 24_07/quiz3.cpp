class Box {  
  
    int length;  
    int breadth;  
    int height;  

public:  
    Box() : length(0), breadth(0), height(0) {} 

    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}   

    Box(const Box& B) : length(B.getLength()), breadth(B.getBreadth()), height(B.getHeight()) {}  

    void setLength(int l) { length = l; }  
    int getLength() const { return length; }  

    void setBreadth(int b) { breadth = b; }  
    int getBreadth() const { return breadth; }  

    void setHeight(int h) { height = h; }  
    int getHeight() const { return height; }  

    long long CalculateVolume() const {  
        return static_cast<long long>(length) * breadth * height;  
    }  

    // Overloading the < operator  
    bool operator<(const Box& B) const {  
        if (length < B.length) return true;  
        if (length == B.length && breadth < B.breadth) return true;  
        if (length == B.length && breadth == B.breadth && height < B.height) return true;  
        return false;  
    }  

    // Overloading the << operator  
    friend std::ostream& operator<<(std::ostream& os, const Box& B) {  
        os << B.length << " " << B.breadth << " " << B.height;  
        return os;  
    }  
}; 