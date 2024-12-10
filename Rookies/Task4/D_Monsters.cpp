#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dX[] = {1, 0, -1, 0};
int dY[] = {0, 1, 0, -1};
char directions[] = {'D', 'R', 'U', 'L'};

bool inBound(int x,int y , int n,int m){
    return x>=0 && x<n &&y>=0 && y<m ;
}
bool theBound(int x,int y , int n,int m){
    return x==0 || x==n-1 || y==0 || y==m-1;
}

int main() {
    int n,m;
    cin>>n>>m;
    if(n<=0 || m<=0 ||n>1000 ||m>1000)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<vector<char>> grid (n,vector<char>(m));
    pair<int,int> A={-1,-1};
    pair<int,int> ending={-1,-1};
    queue<pair<int,int>> monsterQ;

    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<m ; j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                A={i,j};
            }
            else if(grid[i][j]=='M'){
                monsterQ.push({i,j});
            }
        }
    }
    if(A.first ==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<vector<int>> Mtime (n,vector<int>(m,-1));
    queue<pair<int,int>> Q;

    while(!monsterQ.empty()){
        auto [x,y]=monsterQ.front();
        Mtime[x][y]=0;
        Q.push({x,y});
        monsterQ.pop();
    }


    while(! Q.empty())
    {
        auto [x,y]=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nX= x+dX[i];
            int nY= y+dY[i];
            if(inBound(nX , nY,n,m) && grid[nX][nY]=='.' && Mtime[nX][nY]==-1)
            {

                Mtime[nX][nY] = Mtime[x][y]+1;
                Q.push({nX ,nY});

            }
        }
    }

    vector<vector<int>> Atime (n,vector<int>(m,-1));
    vector<vector<pair<int,int>>> parent (n,vector<pair<int,int>>(m,{-1,-1}));
    Q.push(A);
    Atime[A.first][A.second]=0;

    while(! Q.empty())
    {
        auto [x,y]=Q.front();
        Q.pop();
        if(theBound(x,y,n,m) && (Atime[x][y]<Mtime[x][y]||Mtime[x][y]==-1))
        {
            ending={x,y};
            break;
        }
        for(int i=0;i<4;i++){
            int nX= x+dX[i];
            int nY= y+dY[i];
            if(inBound(nX , nY,n,m) && grid[nX][nY]=='.' && Atime[nX][nY]==-1)
            {
                if(Mtime[nX][nY]==-1 || Atime[x][y]+1<Mtime[nX][nY])
                {
                    Atime[nX][nY]=Atime[x][y]+1;
                    parent[nX][nY]={x,y};
                    Q.push({nX,nY});
                }
            }
        }
    }
    if(ending.first==-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        string path;
        pair<int,int> cur=ending;
            while(cur !=A)
            {
                pair<int,int> par=parent[cur.first][cur.second];
                for (int j = 0; j < 4; j++)
                {
                    if(par.first+dX[j] ==cur.first&&par.second+dY[j]==cur.second)
                    {
                        path+=directions[j];
                        break;
                    }
                }
                cur=par;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path<<endl ;
        }
    return 0;
}
