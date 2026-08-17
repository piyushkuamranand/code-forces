#include <bits/stdc++.h>
using namespace std;
 
vector<int> parent(10005), sz(10005, 1);
 
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
 
    if (a == b) return;
 
    if (sz[a] < sz[b]) swap(a, b);
 
    parent[b] = a;
    sz[a] += sz[b];
}
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        unite(i, x);
    }
 
    int ans = 0;
 
    for (int i = 1; i <= n; i++) {
        if (find(i) == i)
            ans++;
    }
 
    cout << ans << '
';
 
    return 0;
}