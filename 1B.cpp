#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    
    while (t--) {
        string s; cin >> s;
        
        string s1;
        int i = 0;
        while (i < s.length() && isalpha(s[i])) {
            s1 += s[i];
            ++i;
        }
        
        string s2;
        while (i < s.length() && isdigit(s[i])) {
            s2 += s[i];
            ++i;
        }
        
        if (i == s.length()) {
            int x = 0;
            for (const char ch : s1) {
                x = x * 26 + (ch - 'A' + 1);
            }
            
            cout << 'R' << s2 << 'C' << to_string(x) << "\n";
        } else {
            int x = 0;
            while (++i < s.length())
                x = x * 10 + (s[i] - '0');
                
            s1.clear();
            while (x > 0) {
                s1 += ((x - 1) % 26) + 'A';
                x = (x - 1) / 26;
            }
            reverse(s1.begin(), s1.end());
            cout << s1 << s2 << "\n";
        }
    }
}