#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v;
    cin >> n >> v;
    
    vector<pair<int, int>> ones, twos;
    
    for (int i = 1; i <= n; ++i) {
        int t, p;
        cin >> t >> p;
        
        if (t == 1) {
            ones.push_back({p, i});
        } else {
            twos.push_back({p, i});
        }
    }
    
    sort(ones.rbegin(), ones.rend());
    sort(twos.rbegin(), twos.rend());
    
    vector<long long> pref(twos.size() + 1);
    for (int i = 0; i < (int)twos.size(); ++i)
        pref[i + 1] = pref[i] + twos[i].first;
        
    long long ans = 0, sum = 0;
    int i1 = 0, i2 = 0;
    
    for (int i = 0; i <= min(v, (int)ones.size()); ++i) {
        if (i > 0)
            sum += ones[i - 1].first;
            
        int j = min((int)twos.size(), (v - i) / 2);
        
        if (sum + pref[j] > ans) {
            ans = sum + pref[j];
            i1 = i;
            i2 = j;
        }
    }
    
    cout << ans << "\n";
    
    for (int i = 0; i < i1; ++i)
        cout << ones[i].second << ' ';
    for (int i = 0; i < i2; ++i)
        cout << twos[i].second << ' ';
    cout << '\n';

    return 0;
}