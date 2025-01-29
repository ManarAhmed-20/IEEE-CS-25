#include <iostream>
using namespace std;

const int MAXN = 1005;
int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int parentDir[MAXN][MAXN];
string path;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool isBoundary(int x, int y)
{
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

bool dfs(int x, int y)
{
    visited[x][y] = true;

    if (isBoundary(x, y))
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny))
        {
            parentDir[nx][ny] = i;
            if (dfs(nx, ny))
            {
                path += dir[i];
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    int startX = -1, startY = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
                grid[i][j] = '.';
            }
        }
    }

    if (dfs(startX, startY))
    {
        cout << "YES" << endl;
        //reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
