#include "bits/stdc++.h"

using namespace std;

vector<int> prefixFunction(const string& s) {
    vector<int> pi(s.length(), 0);
    
    for (int i = 1; i < s.length(); i++) {
        int j = pi[i - 1];
        
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        
        if (s[i] == s[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = j;
        }
    }
    
    return pi;
}

void sol() {
    string s, t;
    cin >> s >> t;

    vector<int> pi = prefixFunction(t + '#' + s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol();
    }
}
