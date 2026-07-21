#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    const int n = s.length();

    vector<int> dp(n, -1);
    stack<int> stack;

    int maxLen = 0, count = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            stack.push(i);
        else if (!stack.empty()) {
            int idx = stack.top(); stack.pop();
            dp[i] = i - idx + 1;
            if (idx > 0 && dp[idx - 1] != -1)
                dp[i] += dp[idx - 1];

            if (maxLen == dp[i]) {
                ++count;
            } else if (dp[i] > maxLen) {
                maxLen = dp[i];
                count = 1;
            }
        }
    }

    cout << maxLen << ' ' << count << '\n';
    return 0;
}