
//When I uploaded the code to vjudge, the result was wrong answer, but I no longer have time to edit. 
#include <iostream>
#include <cmath>
using namespace std;
int result(int w[],int n,int x,int first,int second)
{
    if(x==n){
        return abs(first-second);
    }
    return min(result(w,n,x+1,first+w[x],second)
              ,result(w,n,x+1,first,second+w[x]));
}
int main()
{
    int n;
    cin>>n;
    int w[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }

    cout<<result(w,n,0,0,0)<<endl;
    return 0;
}
