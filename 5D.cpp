#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double a, v, l, d, w;
    cin >> a >> v;
    cin >> l >> d >> w;

    w = min(w, v);
    double ans = 0;
    
    auto getTime = [&](double dist, double u) {
        double accnDist = (v * v - u * u) / (2 * a);
        if (dist <= accnDist) {
            double v2 = sqrt(u * u + 2 * a * dist);
            return (v2 - u) / a;
        }
        return (v - u) / a + (dist - accnDist) / v;
    };
    
    if (w == v || d <= w * w / (2 * a)) {
        ans = getTime(l, 0);
    } else {
        double x = sqrt(a * d + w * w / 2);
        
        if (x <= v) {
            ans += (2 * x - w) / a;
        } else {
            double accnDist = v * v / (2 * a);
            double decDist = (v * v - w * w) / (2 * a);
            double cruiseDist = d - accnDist - decDist;
            
            ans += v / a;
            ans += cruiseDist / v;
            ans += (v - w) / a;
        }
        
        ans += getTime(l - d, w);
    }
    
    cout << fixed << setprecision(10) << ans << "\n";
    
    return 0;
}