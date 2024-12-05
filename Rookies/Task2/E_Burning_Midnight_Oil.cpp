#include <iostream>
using namespace std;

bool tamam(int v,int n , int k)
{
    int x=v;
    while(v>0)
    {
        v /=k;
        x +=v;
    }
    if(x>=n){
        return true;
    }
    return false;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int mid , l=k , r=n , ans=n;
    while (l<=r){
        mid=(l+r)/2;
        if(tamam(mid,n , k))
        {
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << ans<<endl;
    return 0;
}
