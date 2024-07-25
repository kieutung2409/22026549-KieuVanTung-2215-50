struct Rectangle {
    int height;
    int length;
    
    Rectangle() : height(0), length(0) {}
    Rectangle(double _height, double _length) : height(_height), length(_length) {}

    int getPerimeter() {
        // your code goes here
        return 2* (height + length);
    }
    
    void print() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                if (i==0 || j==0 || i==height-1 || j==length-1) {
                    cout<<"*";
                } else cout<<" ";
                
                if (j == length-1) cout<<endl;
            }
        }
    }
};

int compare(Rectangle a, Rectangle b) {
    if (a.getPerimeter() < b.getPerimeter()) return -1;
    else if (a.getPerimeter() == b.getPerimeter()) return 0;
    return 1;
}