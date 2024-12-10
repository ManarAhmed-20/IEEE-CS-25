#include <iostream>
#include <queue>
#include <string>
using namespace std;
int X[]={-1,-1,1,1,-2,-2,2,2};
int Y[]={-2,2,-2,2,1,-1,1,-1};

pair<int,int> toIndex(string pos){
    return {pos[0]-'a',pos[1]-'1'};
}
bool within_boundary(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}
int minMoves(string start,string ending){
    auto [xStart,yStart] = toIndex(start);
    auto [xEnd,yEnd]=toIndex(ending);

    if(xStart == xEnd && yStart==yEnd)
        return 0;
    int mov=0;
    queue<pair<int,int>> que;
    que.push({xStart,yStart});

    bool visited[8][8]={false};
    visited[xStart][yStart]=true;

    while(! que.empty()){
        int qsize=que.size();
        for(int i=0;i<qsize;i++){
            auto [xFront , yFront]=que.front();
            que.pop();
            for(int j=0 ; j<8 ;j++){
                int newX=xFront+X[j];
                int newY=yFront+Y[j];

                if(within_boundary(newX,newY)&& !visited[newX][newY])
                {
                    if(newX == xEnd && newY==yEnd)
                        return mov+1;
                    visited[newX][newY]=true;
                    que.push({newX,newY});
                }
            }
        }
        mov++;
    }
return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string start,ending;
        cin>>start>>ending;
        cout<<minMoves(start,ending)<<endl;

    }
    return 0;
}
