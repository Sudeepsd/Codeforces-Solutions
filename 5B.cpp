#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> lines;
    string line;
    int maxLine = 0;
    
    while (getline(cin, line)) {
        lines.push_back(line);
        maxLine = max(maxLine, (int)line.length());
    }
    
    for (int i = 0; i < maxLine + 2; ++i)
        cout << "*";
    cout << "\n";
    
    bool leftAlign = true;
    for (const string& line : lines) {
        int spaces = maxLine - line.length();
        cout << "*";
        for (int i = 0; i < (spaces + !leftAlign) / 2; ++i)
            cout << " ";
        cout << line;
        for (int i = 0; i < (spaces + leftAlign) / 2; ++i)
            cout << " ";
        cout << "*\n";
        if (spaces % 2 == 1)
            leftAlign = !leftAlign;
    }
    
    for (int i = 0; i < maxLine + 2; ++i)
        cout << "*";
    cout << "\n";
    
    return 0;
}