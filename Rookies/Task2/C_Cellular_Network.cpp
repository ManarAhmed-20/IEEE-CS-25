#include <iostream>
#include <cmath>
using namespace std;
 
bool isCover(int n,int m,int cities[],int towers[],long long mid)
{
    int j=0;
    for(int i=0 ; i<n ; i++)
    {
        while (j < m && abs(cities[i] - towers[j]) > mid)
        {
            j++;
        }
 
        if(j==m)
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    int cities[n];
    int towers[m];
 
    for(int i=0; i<n; i++)
    {
        cin>>cities[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>towers[i];
    }
    long long left = 0, right = 2e9, answer = 0;
 
    while(left<=right)
    {
        long long mid = (left + right) / 2;
 
        if(isCover(n,m,cities,towers,mid))
        {
            answer=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<answer<<endl;
    return 0;
}