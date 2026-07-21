#include <bits/stdc++.h>
using namespace std;

struct Envelope {
    int width;
    int height;
    int index;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cardWidth, cardHeight;
    cin >> n >> cardWidth >> cardHeight;
    
    vector<Envelope> envelopes;
    
    for (int i = 0; i < n; ++i) {
        int width, height;
        cin >> width >> height;
        
        if (width > cardWidth && height > cardHeight) {
            envelopes.push_back({width, height, i + 1});
        }
    }
    
    if (envelopes.empty()) {
        cout << "0\n";
        return 0;
    }
    
    sort(envelopes.begin(), envelopes.end(), [](const Envelope& a, const Envelope& b){
        return (a.width != b.width) ? (a.width < b.width) : (a.height < b.height);
    });
    
    const int size = envelopes.size();
    vector<int> dp(size, 1);
    vector<int> parent(size, -1);
    int bestEnd = 0;
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envelopes[j].width < envelopes[i].width && envelopes[j].height < envelopes[i].height && dp[j] + 1> dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        
        if (dp[i] > dp[bestEnd])
            bestEnd = i;
    }
    
    vector<int> ans;
    for (int i = bestEnd; i != -1; i = parent[i]) {
        ans.push_back(envelopes[i].index);
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (const int x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}