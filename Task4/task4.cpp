#include "bits/stdc++.h"

using namespace std;

int getDel(int dig) {
    return dig % 3 == 0 ? dig / 3 : dig / 3 + 1;
}

void sol() {
    int l, r;
    cin >> l >> r;
    int cnt = getDel(r);
    int ans = cnt;
    int offset = 0;
    while (l + offset <= r - offset) {
        cnt = getDel(r - offset);
        ans += cnt;
        ans += getDel((l + offset) * cnt * 3);
        offset++;
//        cout << i << " " << getDel(i) << endl;
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
