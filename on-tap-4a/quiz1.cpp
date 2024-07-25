struct Point 
{
    double x, y;
    Point() {
        x = 0;
        y = 0;
    };
    Point(double _x, double _y) {
        x = _x;
        y = _y;

    };
    Point(const Point& other) {
        x = other.x;
        y = other.y;
    };
};

class Triangle 
{
    Point p1, p2, p3;
public:
    Triangle(const Point& A, const Point& B, const Point& C) : p1(A), p2(B), p3(C) {}

    double Triangle::getPerimeter() const {  
         
        double AB = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
        double BC = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));  
        double AC = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));  
 
        return AB + AC + BC;  
    }
    double Triangle::getArea() const {  
 
        double AB = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
        double BC = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));  
        double AC = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));

        double halfPerimeter = (AB + AC + BC)/2;

        return sqrt(halfPerimeter * (halfPerimeter-AB) * (halfPerimeter-AC) * (halfPerimeter-BC)); 
    }  
};