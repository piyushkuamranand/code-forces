#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
 
        string a, b;
        cin >> a >> b;
 
        vector<int> p;
 
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                p.push_back(i);
            }
        }
 
        int k = p.size();
 
        if (k % 2) {
            cout << -1 << '
';
        } else if (k == 0) {
            cout << 0 << '
';
        } else if (k == 2) {
            if (p[1] == p[0] + 1) {
                cout << min(x, 2 * y) << '
';
            } else {
                cout << y << '
';
            }
        } else {
            cout << (k / 2) * y << '
';
        }
    }
 
    return 0;
}