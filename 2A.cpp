#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    
    vector<pair<string, int>> rounds(n);
    unordered_map<string, int> finalScore;
    
    for (auto& round : rounds) {
        cin >> round.first >> round.second;
        finalScore[round.first] += round.second;
    }
    
    int maxScore = 0;
    for (const auto& player : finalScore) {
        maxScore = max(maxScore, player.second);
    }
    
    unordered_map<string, int> currScore;
    for (const auto& [name, score] : rounds) {
        currScore[name] += score;
        
        if (currScore[name] >= maxScore && finalScore[name] == maxScore) {
            cout << name << "\n";
            return 0;
        }
    }
}