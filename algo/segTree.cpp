#include "bits/stdc++.h"

using namespace std;

template<typename T>
class SegTree {
public:
    SegTree() = default;
    SegTree(const vector<T> &arr, const function<T(T, T)> &operation) {
        create(arr, operation);
    }
    
    void create(const vector<T> &arr, const function<T(T, T)> &operation) {
        m_operation = operation;
        while (m_length < arr.size()) {
            m_length *= 2;
        }
        m_tree.assign(m_length * 2 - 1, 0);
        
        for (int i = 0; i < arr.size(); i++) {
            set(i, arr[i]);
        }
    }
    
    T runOperation(int l, int r) {
        if (l < 0 || r > m_length) {
            cerr << "Invalid L or R value";
            return defaultValue();
        }
        return runOperation(l, r, 0, 0, m_length);
    }
    
    
private:
    int m_length = 1;
    vector<T> m_tree;
    function<T(T, T)> m_operation;
    
    T defaultValue() {
        if constexpr (is_same_v<T, int> || is_same_v<T, uint32_t> ||
            is_same_v<T, int64_t> || is_same_v<T, uint64_t>) {
            return 0;
        } else if constexpr (is_same_v<T, float> || is_same_v<T, double>) {
            return 0.;
        } else if constexpr (is_same_v<T, string>) {
            return string();
        } else {
            cerr << "The type is not supported\n";
            assert(false);
        }
    }
    
    T runOperation(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            return m_tree[x];
        }
        if (lx >= r || rx <= l) {
            return defaultValue();
        }
        
        int mid = (lx + rx) / 2;
        return m_operation(runOperation(l, r, x * 2 + 1, lx, mid), runOperation(l, r, x * 2 + 2, mid, rx));
    }
    
    void set(int i, T value) {
        set(i, value, 0, 0, m_length);
    }
    
    void set(int i, T value, int x, int lx, int rx) {
        if (rx - lx == 1) {
            m_tree[x] = value;
            return;
        }
        
        int mid = (lx + rx) / 2;
        
        if (i < mid) {
            set(i, value, x * 2 + 1, lx, mid);
        } else {
            set(i, value, x * 2 + 2, mid, rx);
        }
        m_tree[x] = m_operation(m_tree[x * 2 + 1], m_tree[x * 2 + 2]);;
    }
    
};

int operation(int a, int b) {
    return a + b;
}

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegTree<int> myTree(v, operation);
    cout << myTree.runOperation(1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol();
    }
}
