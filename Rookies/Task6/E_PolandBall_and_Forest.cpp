#include <iostream>
#include <vector>

using namespace std;

const int Mvalue = 10000;
vector<int> adj[Mvalue + 1]; 
bool visited[Mvalue + 1]; 

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i) { 
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
    }

    int tree_count = 0;
    
   
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { 
            tree_count++; 
            dfs(i); 
        }
    }

    cout << tree_count << endl; 
    return 0;
}
