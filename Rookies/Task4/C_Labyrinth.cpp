#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char directions []= {'D','R','U','L'};
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
    vector<string> v(n);
vector<vector<bool>> vis(n, vector<bool>(m, false));
vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int,int> start,ending;
    //pair<int,int> parent[1000][1000];
    queue <pair<int,int>> q;
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
                start= {i,j};
            else if (v[i][j] == 'B')
                ending= {i,j};
        }}
        q.push(start);
        vis[start.first][start.second]=true;
        parent[start.first][start.second]= {-1,-1};

        bool founded=false;

        while (! q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if ((inrange(nx, ny, n, m) && v[nx][ny] != '#') && !vis[nx][ny])
                {
                    parent[nx][ny]= {x,y};
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    if(nx == ending.first && ny==ending.second)
                    {
                        founded=true;
                        break;
                    }
                }
            }
            if(founded)
                break;
        }
        if(!founded) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            pair<int,int> cur=ending;
            vector<char> path;
            while(cur !=start)
            {
                pair<int,int> par=parent[cur.first][cur.second];
                for (int j = 0; j < 4; j++)
                {
                    if(par.first+dx[j] ==cur.first&&par.second+dy[j]==cur.second)
                    {
                        path.push_back(directions[j]);
                        break;
                    }
                }
                cur=par;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (char c : path) cout << c;
            cout << endl;
        }
        return 0;
    }
