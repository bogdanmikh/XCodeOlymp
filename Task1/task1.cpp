#include "bits/stdc++.h"

using namespace std;

void sol() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int64_t> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    uint64_t sum = 0;
    for (int i = n - 1; i >= 0; i -= 2) {
        sum += arr[i];
    }
    for (int i = n - 2; i >= 0; i -= 2) {
        if (sum <= arr[i] + k) {
            cout << 0 << endl;
            return;
        }
        sum -= (arr[i] + k);
    }
    if (sum <= 0) {
        cout << 0 << endl;
        return;
    }
    cout << sum << endl;
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
