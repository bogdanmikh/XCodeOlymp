#include "bits/stdc++.h"

using namespace std;

//bgry
vector<vector<int>> g;
vector<pair<int, int>> port;



int getDist(int x, int y) {
    auto [xl, xr] = port[x];
    auto [yl, yr] = port[y];
    if (xl == yl || xl == yr || xr == yl || xr == yr) {
        return 1;
    }
    for (auto v : g[x]) {
        auto [vl, vr] = port[v];
        
    }
}

void sol() {
    int n, q;
    cin >> n >> q;
    g.assign(4, {});
    port.assign(n, {});
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'B') {
            g[0].emplace_back(i);
            port[i].first = 0;
        } else if (s[0] == 'G') {
            g[1].emplace_back(i);
            port[i].first = 1;
        } else if (s[0] == 'R') {
            g[2].emplace_back(i);
            port[i].first = 2;
        }
        
        if (s[1] == 'R') {
            g[2].emplace_back(i);
            port[i].second = 2;
        } else if (s[1] == 'G') {
            g[1].emplace_back(i);
            port[i].second = 1;
        } else if (s[1] == 'Y') {
            g[3].emplace_back(i);
            port[i].second = 3;
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << getDist(x, y);
    }
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
