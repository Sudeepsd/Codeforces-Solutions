#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, hours;
    cin >> n >> hours;
    
    vector<int> minHours(n);
    vector<int> maxHours(n);
    
    int minTime = 0, maxTime = 0;
    for (int i = 0; i < n; ++i) {
        cin >> minHours[i] >> maxHours[i];
        minTime += minHours[i];
        maxTime += maxHours[i];
    }
    
    if (minTime <= hours && hours <= maxTime) {
        int remaining = hours - minTime;
        for (int i = 0; i < n && remaining > 0; ++i) {
            int add = min(remaining, maxHours[i] - minHours[i]);
            minHours[i] += add;
            remaining -= add;
        }
        
        cout << "YES\n";
        for (int time : minHours) {
            cout << time << ' ';
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}