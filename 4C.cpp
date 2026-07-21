#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    unordered_map<string, int> namesCnt;
    while (n--) {
        string name; cin >> name;
        
        if (namesCnt.contains(name)) {
            cout << name + to_string(namesCnt[name]) << "\n";
            ++namesCnt[name];
        } else {
            cout << "OK\n";
            namesCnt[name] = 1;
        }
    }

    return 0;
}