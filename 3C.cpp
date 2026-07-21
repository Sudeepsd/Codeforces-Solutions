#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string rows[3];
    
    for (int i = 0; i < 3; ++i)
        cin >> rows[i];
        
        
    int xRow[3] = {0}, oRow[3] = {0};
    int xCol[3] = {0}, oCol[3] = {0};
    int xCount = 0, oCount = 0, dotCount = 0;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (rows[i][j] == '.') {
                ++dotCount;
            } else if (rows[i][j] == 'X') {
                ++xRow[i];
                ++xCol[j];
                ++xCount;
            } else {
                ++oRow[i];
                ++oCol[j];
                ++oCount;
            }
        }
    }
    
    bool xWon = false, oWon = false;
    
    for (int i = 0; i < 3; ++i) {
        if (xRow[i] == 3 || xCol[i] == 3)
            xWon = true;
        if (oRow[i] == 3 || oCol[i] == 3)
            oWon = true;
    }
    
    if (rows[0][0] == rows[1][1] && rows[1][1] == rows[2][2]) {
        if (rows[0][0] == 'X')
            xWon = true;
        else if (rows[0][0] == '0')
            oWon = true;
    }   
    if (rows[2][0] == rows[1][1] && rows[1][1] == rows[0][2]) {
        if (rows[1][1] == 'X')
            xWon = true;
        else if (rows[1][1] == '0')
            oWon = true;
    }
    
    if ((xWon && oWon) || xCount - oCount >= 2 || xCount - oCount < 0) {
        cout << "illegal\n";
    } else if (xWon) {
        if (xCount - oCount != 1)
            cout << "illegal\n";
        else
            cout << "the first player won\n";
    } else if (oWon) {
        if (xCount != oCount)
            cout << "illegal\n";
        else
            cout << "the second player won\n";
    } else if (dotCount == 0) {
        cout << "draw\n";        
    } else if (xCount == oCount) {
        cout << "first\n";
    } else {
        cout << "second\n";
    }

    return 0;
}