#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    int books[n];
    for (int i=0 ; i<n ; i++){
        cin>>books[i];
    }
    int l=0,r=0,sum=0,answer=0;
    while (r<n){
        while(r<n && (sum + books[r]<=t))
        {
            sum += books[r];
            r++;
        }
        answer=max(answer , r-l);
        sum-=books[l];
        l++;
    }

    cout<<answer<<endl;
    return 0;
}
