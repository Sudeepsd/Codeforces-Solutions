#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> Pair;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    
    long long ans = 0;
    int balance = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> minHeap;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(')
            ++balance;
        else if (s[i] == ')')
            --balance;
        else {
            long long cost1, cost2;
            cin >> cost1 >> cost2;
            
            s[i] = ')';
            ans += cost2;
            --balance;
            
            minHeap.push({cost1 - cost2, i});
        }
        
        if (balance < 0) {
            if (minHeap.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            
            const auto cheapest = minHeap.top();
            minHeap.pop();
            
            ans += cheapest.first;
            s[cheapest.second] = '(';
            balance += 2;
        }
    }
    
    if (balance != 0) {
        cout << "-1\n";
        return 0;
    }
    
    cout << ans << "\n";
    cout << s << "\n";
    return 0;

    return 0;
}