#include <bits/stdc++.h>
using namespace std;

int main() {
    string cell1, cell2;
    cin >> cell1 >> cell2;
    
    int c1 = cell1[0] - 'a';
    int r1 = cell1[1] - '1';
    
    int c2 = cell2[0] - 'a';
    int r2 = cell2[1] - '1';
    
    cout << max(abs(r1 - r2), abs(c1 - c2)) << "\n";
    
    while (r1 != r2 || c1 != c2) {
        if (c1 < c2) {
            cout << 'R';
            ++c1;
        }
        if (c1 > c2) {
            cout << 'L';
            --c1;
        }
        if (r1 < r2) {
            cout << 'U';
            ++r1;
        }
        if (r1 > r2) {
            cout << 'D';
            --r1;
        }
        cout << '\n';
    }
}