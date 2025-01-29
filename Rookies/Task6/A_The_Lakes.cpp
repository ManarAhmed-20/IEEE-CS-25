#include <iostream>
#include <vector>

using namespace std;

long long n ,m;
long long ans = -1 ,sum=0;
int v[1000][1000];
bool vis[1000][1000];
void dfs(long long i,long long j)
{
    if (i<0||i>n-1||j<0||j>m-1||v[i][j]==0||vis[i][j])
        return;

    vis[i][j]=true;
    sum+=v[i][j];

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}

int main()
{
    long long t=1;
    cin>>t;
    while(t--){
        cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            vis[i][j]= false;
        }
    }

    long long Max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]!=0&&vis[i][j]==0)
            {
                sum=0;
                dfs(i,j);
                Max = max(Max, sum);
            }
        }
    }
    cout<<Max<<endl;
    }
}
