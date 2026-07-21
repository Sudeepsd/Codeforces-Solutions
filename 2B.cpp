#include <bits/stdc++.h>
using namespace std;

int countFactor(int num, int factor) {
    int count = 0;
    while (num > 0 && num % factor == 0) {
        ++count;
        num /= factor;
    }
    return count;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> twos(n, vector<int>(n));
    vector<vector<int>> fives(n, vector<int>(n));
    
    int zeroRow = -1, zeroCol = -1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            
            if (x == 0) {
                zeroRow = i, zeroCol = j;
                twos[i][j] = fives[i][j] = 1e9;
            } else {
                twos[i][j] = countFactor(x, 2);
                fives[i][j] = countFactor(x, 5);
            }
        }
    }
    
    vector<vector<char>> parentTwo(n, vector<char>(n));
    vector<vector<char>> parentFive(n, vector<char>(n));
    vector<vector<int>> dpTwo(n, vector<int>(n, 1e9));
    vector<vector<int>> dpFive(n, vector<int>(n, 1e9));
    
    dpTwo[0][0] = twos[0][0];
    dpFive[0][0] = fives[0][0];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0)
                continue;
                
            if (i > 0 && dpTwo[i-1][j] + twos[i][j] < dpTwo[i][j]) {
                dpTwo[i][j] = dpTwo[i-1][j] + twos[i][j];
                parentTwo[i][j] = 'D';
            }
            if (i > 0 && dpFive[i-1][j] + fives[i][j] < dpFive[i][j]) {
                dpFive[i][j] = dpFive[i-1][j] + fives[i][j];
                parentFive[i][j] = 'D';
            }
            if (j > 0 && dpTwo[i][j-1] + twos[i][j] < dpTwo[i][j]) {
                dpTwo[i][j] = dpTwo[i][j-1] + twos[i][j];
                parentTwo[i][j] = 'R';
            }
            if (j > 0 && dpFive[i][j-1] + fives[i][j] < dpFive[i][j]) {
                dpFive[i][j] = dpFive[i][j-1] + fives[i][j];
                parentFive[i][j] = 'R';
            }
        }
    }
    
    const int best = min(dpTwo[n-1][n-1], dpFive[n-1][n-1]);
    
    if (zeroRow != -1 && best > 1) {
        cout << 1 << '\n';
        cout << string(zeroRow, 'D') << string(zeroCol, 'R');
        cout << string(n - zeroRow - 1, 'D') << string(n - zeroCol - 1, 'R');
        cout << '\n';
        return 0;
    }
    
    const bool useTwo = dpTwo[n-1][n-1] < dpFive[n-1][n-1];
    const auto& parent = useTwo ? parentTwo : parentFive;
    
    string path;
    int r = n - 1, c = n - 1;
    
    while (r > 0 || c > 0) {
        const auto& dir = parent[r][c];
        path += dir;
        
        if (dir == 'D')
            --r;
        else
            --c;
    }
    reverse(path.begin(), path.end());
    cout << best << "\n" << path << "\n";
    return 0;
}