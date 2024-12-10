#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxNum = 100001;
vector<int> Adjacent[maxNum];
bool Vis[maxNum];
vector<int> components;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    Vis[start] = true;

    while (!q.empty()) {
        int N = q.front();
        q.pop();

        for (int i : Adjacent[N]) {
            if (!Vis[i]) {
                Vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Adjacent[a].push_back(b);
        Adjacent[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!Vis[i]) {
            components.push_back(i);
            bfs(i);
        }
    }

    int k = components.size() - 1;
    cout << k << "\n";

    for (auto i = 1; i < components.size(); i++) {
        cout << components[0] << " " << components[i] << "\n";
    }

    return 0;

}
