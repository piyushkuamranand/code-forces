#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n);
 
    for (int &x : a)
        cin >> x;
 
    vector<int> ones;
 
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            ones.push_back(i);
    }
 
    // No existing 1
    if (ones.empty()) {
        int first = -1, last = -1;
 
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
 
        if (first != -1) {
            a[first] = 1;
            a[last] = 1;
        }
    }
    else {
        // Find best pair of endpoints.
        int bestL = ones[0];
        int bestR = ones[0];
 
        // Between consecutive existing 1s
        for (int i = 0; i + 1 < (int)ones.size(); i++) {
            if (ones[i + 1] - ones[i] > bestR - bestL) {
                bestL = ones[i];
                bestR = ones[i + 1];
            }
        }
 
        // Extend first 1 to the left using earliest -1
        for (int i = 0; i < ones[0]; i++) {
            if (a[i] == -1) {
                if (ones[0] - i > bestR - bestL) {
                    bestL = i;
                    bestR = ones[0];
                }
                break;
            }
        }
 
        // Extend last 1 to the right using latest -1
        for (int i = n - 1; i > ones.back(); i--) {
            if (a[i] == -1) {
                if (i - ones.back() > bestR - bestL) {
                    bestL = ones.back();
                    bestR = i;
                }
                break;
            }
        }
 
        // Make chosen endpoints 1
        a[bestL] = 1;
        a[bestR] = 1;
 
        // Everything between them must be 0
        for (int i = bestL + 1; i < bestR; i++) {
            if (a[i] == -1)
                a[i] = 0;
        }
    }
 
    // All unused -1 become 0
    for (int &x : a) {
        if (x == -1)
            x = 0;
    }
 
    for (int x : a)
        cout << x << ' ';
 
    cout << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--)
        solve();
}