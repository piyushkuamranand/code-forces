#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        if (n == 1) {
            cout << 1 << '
';
        } 
        else if (n == 2) {
            cout << -1 << '
';
        } 
        else {
            long long a[55];
            a[1] = 1;
            a[2] = 2;
            a[3] = 3;
 
            for (int i = 4; i <= n; i++) {
                a[i] = 2 * a[i - 1];
            }
 
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << '
';
        }
    }
 
    return 0;
}