#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);
    vector<bool> vis(n + 1, false);

    queue<int> q;

    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int v : adj[node]){
            if(!vis[v]){
                vis[v] = true;
                parent[v] = node;
                q.push(v);
            }
        }
    }

    if(!vis[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;

    for(int v = n; v != -1; v = parent[v]){
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(int x : path) cout << x << " ";
}
