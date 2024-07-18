
#include <iostream>
#include <cmath>
#include <iomanip>  // for setprecision

void solveQuadratic(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        
        // In ra các nghiệm từ nhỏ đến lớn, chỉ in 1 lần nếu nghiệm kép
        if (x1 == x2) {
            std::cout << std::fixed << std::setprecision(2) << x1 << std::endl;
        } else {
            if (x1 < x2) {
                std::cout << std::fixed << std::setprecision(2) << x1 << std::endl;
                std::cout << std::fixed << std::setprecision(2) << x2 << std::endl;
            } else {
                std::cout << std::fixed << std::setprecision(2) << x2 << std::endl;
                std::cout << std::fixed << std::setprecision(2) << x1 << std::endl;
            }
        }
    } else if (delta == 0) {
        double x = -b / (2 * a);
        std::cout << std::fixed << std::setprecision(2) << x << std::endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(abs(delta)) / (2 * a);
        std::cout << std::fixed << std::setprecision(2) << realPart << " " << -imaginaryPart << std::endl; // Nghiệm phức
        std::cout << std::fixed << std::setprecision(2) << realPart << " " << imaginaryPart << std::endl; // Nghiệm phức
    }
}

int main() {
    double a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    solveQuadratic(a, b, c);

    return 0;
}