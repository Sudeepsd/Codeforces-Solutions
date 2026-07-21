#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int people = 0;
    int ans = 0;
    
    while (getline(cin, s)) {
        if (s[0] == '+')
            ++people;
        else if (s[0] == '-')
            --people;
        else {
            int len = s.length() - s.find(':') - 1;
            ans += people * len;
        }
    }
    cout << ans << "\n";

    return 0;
}