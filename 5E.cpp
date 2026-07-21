#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> heights(n);
    
    int maxIndex = 0;
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
        if (heights[i] > heights[maxIndex])
            maxIndex = i;
    }
    
    reverse(heights.begin(), heights.begin() + maxIndex);
    reverse(heights.begin() + maxIndex, heights.end());
    reverse(heights.begin(), heights.end());
    
    heights.push_back(heights[0]);
    
    vector<int> rightMax(n + 1), equal(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        rightMax[i] = i + 1;
        
        while (rightMax[i] < n && heights[rightMax[i]] < heights[i])
            rightMax[i] = rightMax[rightMax[i]];
            
        if (rightMax[i] < n && heights[rightMax[i]] == heights[i]) {
            equal[i] = equal[rightMax[i]] + 1;
            rightMax[i] = rightMax[rightMax[i]];
        }
    }
    
    vector<int> leftMax(n + 1);
    for (int i = 1; i < n; ++i) {
        leftMax[i] = i - 1;
        while (leftMax[i] > 0 && heights[leftMax[i]] <= heights[i])
            leftMax[i] = leftMax[leftMax[i]];
    }
    
    long long ans = equal[0];
    for (int i = 1; i < n; ++i) {
        ans += equal[i];
        
        if (heights[i] == heights[0])
            continue;
            
        ans += (leftMax[i] == 0 && rightMax[i] == n) ? 1 : 2;
    }
    
    cout << ans << "\n";

    return 0;
}