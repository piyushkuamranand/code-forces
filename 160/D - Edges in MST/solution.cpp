#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
    vector<int> parent, sz;
 
    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
 
    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
 
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
 
        if (a == b)
            return;
 
        if (sz[a] < sz[b])
            swap(a, b);
 
        parent[b] = a;
        sz[a] += sz[b];
    }
};
 
struct Edge {
    int u, v, w, id;
};
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<Edge> edges(m);
 
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
 
        --edges[i].u;
        --edges[i].v;
 
        edges[i].id = i;
    }
 
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.w < b.w;
         });
 
    vector<string> ans(m, "none");
 
    DSU dsu(n);
 
    // Temporary graph
    vector<vector<pair<int,int>>> graph(n);
 
    vector<int> tin(n, -1);
    vector<int> low(n);
 
    int timer = 0;
 
    // DFS for bridges
    auto dfs = [&](auto&& self, int u, int parentEdge) -> void {
 
        tin[u] = low[u] = timer++;
 
        for (auto [v, id] : graph[u]) {
 
            if (id == parentEdge)
                continue;
 
            if (tin[v] != -1) {
 
                low[u] = min(low[u], tin[v]);
 
            } else {
 
                self(self, v, id);
 
                low[u] = min(low[u], low[v]);
 
                if (low[v] > tin[u]) {
                    ans[edges[id].id] = "any";
                }
            }
        }
    };
 
    int i = 0;
 
    while (i < m) {
 
        int j = i;
 
        while (j < m && edges[j].w == edges[i].w)
            ++j;
 
        vector<int> candidate;
        candidate.reserve(j - i);
 
        vector<int> vertices;
        vertices.reserve(2 * (j - i));
 
        // ----------------------------------
        // Build temporary graph
        // ----------------------------------
 
        for (int k = i; k < j; k++) {
 
            int u = dsu.find(edges[k].u);
            int v = dsu.find(edges[k].v);
 
            if (u == v) {
                ans[edges[k].id] = "none";
                continue;
            }
 
            candidate.push_back(k);
 
            graph[u].push_back({v, k});
            graph[v].push_back({u, k});
 
            vertices.push_back(u);
            vertices.push_back(v);
        }
 
        // Remove duplicate vertices
        sort(vertices.begin(), vertices.end());
        vertices.erase(unique(vertices.begin(), vertices.end()),
                       vertices.end());
 
        // ----------------------------------
        // Find bridges
        // ----------------------------------
 
        for (int v : vertices) {
            tin[v] = -1;
        }
 
        for (int v : vertices) {
 
            if (tin[v] == -1) {
                dfs(dfs, v, -1);
            }
        }
 
        // ----------------------------------
        // Remaining candidates
        // are "at least one"
        // ----------------------------------
 
        for (int id : candidate) {
 
            if (ans[edges[id].id] != "any") {
                ans[edges[id].id] = "at least one";
            }
        }
 
        // ----------------------------------
        // Clear temporary graph
        // ----------------------------------
 
        for (int v : vertices) {
            graph[v].clear();
        }
 
        // ----------------------------------
        // Merge this weight into DSU
        // ----------------------------------
 
        for (int k = i; k < j; k++) {
            dsu.unite(edges[k].u, edges[k].v);
        }
 
        i = j;
    }
 
    // ----------------------------------
    // Output in original order
    // ----------------------------------
 
    for (int i = 0; i < m; i++) {
        cout << ans[i] << '
';
    }
 
    return 0;
}