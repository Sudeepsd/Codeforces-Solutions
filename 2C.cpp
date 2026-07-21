#include <bits/stdc++.h>
using namespace std;

const long double tolerance = 1e-12L;

struct Circle {
    int x, y, r;
};

int main() {
    Circle circle[3];
    
    for (int i = 0; i < 3; ++i) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
    }
    
    long double a1 = 2.0L * (circle[0].x - circle[1].x);
    long double b1 = 2.0L * (circle[0].y - circle[1].y);
    long double p1 = circle[1].r * circle[1].r - circle[0].r * circle[0].r;
    long double q1 = circle[0].x * circle[0].x + circle[0].y * circle[0].y
        - circle[1].x * circle[1].x - circle[1].y * circle[1].y;
        
    long double a2 = 2.0L * (circle[0].x - circle[2].x);
    long double b2 = 2.0L * (circle[0].y - circle[2].y);
    long double p2 = circle[2].r * circle[2].r - circle[0].r * circle[0].r;
    long double q2 = circle[0].x * circle[0].x + circle[0].y * circle[0].y
        - circle[2].x * circle[2].x - circle[2].y * circle[2].y;
        
    long double det = a1 * b2 - a2 * b1;
    
    long double X1 = (p1 * b2 - p2 * b1) / det;
    long double X0 = (q1 * b2 - q2 * b1) / det;
    long double Y1 = (a1 * p2 - a2 * p1) / det;
    long double Y0 = (a1 * q2 - a2 * q1) / det;
    
    long double dx = X0 - circle[0].x;
    long double dy = Y0 - circle[0].y;
    
    long double A = X1 * X1 + Y1 * Y1;
    long double B = 2.0L * (X1 * dx + Y1 * dy) - circle[0].r * circle[0].r;
    long double C = dx * dx + dy * dy;
    
    vector<long double> roots;
    if (fabsl(A) < tolerance) {
        if (fabsl(B) > tolerance) {
            roots.push_back(-C / B);
        }
    } else {
        long double D = B * B - 4.0L * A * C;
        
        if (D >= -tolerance) {
            D = max((long double)0.0L, D);
            
            long double sq = sqrtl(D);
            
            roots.push_back((-B - sq) / (2.0L * A));
            roots.push_back((-B + sq) / (2.0L * A));
        }
    }
    
    bool found = false;
    long double best = 0;
    
    for (long double t : roots) {
        if (t < 1.0L - tolerance)
            continue;
            
        if (t < 1.0L)
            t = 1.0L;
            
        if (!found || t < best) {
            best = t;
            found = true;
        }
    }
    
    if (!found)
        return 0;
        
    long double ansX = X1 * best + X0;
    long double ansY = Y1 * best + Y0;
    
    if (fabsl(ansX) < 0.5e-10L)
        ansX = 0;
        
    if (fabs(ansY) < 0.5e-10L)
        ansY = 0;
        
    cout << fixed << setprecision(5) << ansX << " " << ansY << "\n";
    return 0;
}