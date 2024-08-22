#include "bits/stdc++.h"

using namespace std;

void sol() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    int ans = max(l1, l2) + min(r1, r2);
    
    if (l1 == l2) {
        ans--;
    }
    
    if (r1 == r2) {
        ans--;
    }
    cout << ans << endl;
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
