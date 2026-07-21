#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return hypot((a.x - b.x), (a.y - b.y));
}

int main() {
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    
    double A = dist(b, c);
    double B = dist(a, c);
    double C = dist(a, b);
    
    double triArea = abs((c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y)) / 2.0;
    double r = A * B * C / (4.0 * triArea);
    
    auto getAngle = [&](double x) -> double {
        return 2.0 * asin(min(1.0, x / (2.0 * r)));
    };
    
    double alpha = getAngle(A);
    double beta = getAngle(B);
    double gamma = getAngle(C);
    
    int n = 3;
    for (; n <= 1000; ++n) {
        double unit = 2.0 * PI / n;
        
        auto isValid = [&](double angle) {
            double k = angle / unit;
            return abs(k - round(k)) < 1e-4;
        };
        
        if (isValid(alpha) && isValid(beta) && isValid(gamma)) {
            break;   
        }
    }
    
    double area = n * r * r * sin(2.0 * PI / n) / 2.0;
    cout << fixed << setprecision(10) << area << "\n";
}