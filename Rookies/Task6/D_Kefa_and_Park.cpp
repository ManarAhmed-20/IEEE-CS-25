#include <iostream>
#include <vector>

using namespace std;

const int Mvalue = 1e5 + 5;
vector<int> adj[Mvalue];
vector<bool> cats(Mvalue), vis(Mvalue);
int n, m, ans = 0;

void dfs(int node, int cons) {
    if (cats[node]) 
        cons++;
    else 
        cons = 0;

    if (cons > m) 
        return;

    vis[node] = true;
    bool isLeaf = true;

    for (int next : adj[node]) {
        if (!vis[next]) {
            dfs(next, cons);
            isLeaf = false;
        }
    }

    if (isLeaf) 
        ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int hasCat;
        cin >> hasCat;
        cats[i] = (hasCat == 1);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, 0); 

    cout << ans << endl;
    return 0;
}