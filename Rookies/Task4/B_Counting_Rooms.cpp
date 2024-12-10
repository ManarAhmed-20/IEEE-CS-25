#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool inrange(int x, int y, int n, int m)
{
    if (((0 <= x) && (x < n)) && ((0 <= y) && (y < m)))
        return true;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string v[1000];
    bool vis[1000][1000]={false};
    for (int i=0;i<n;i++)
    {
        cin >> v[i];
    }
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#')
                continue;
            if (vis[i][j] == 1)
                continue;

            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while (! q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if ((inrange(nx, ny, n, m) && v[nx][ny] != '#') && vis[nx][ny] == 0)
                    {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
