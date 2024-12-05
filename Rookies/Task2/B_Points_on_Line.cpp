#include <iostream>
using namespace std;

long long Group(int n,long long d,long long arr[])
{
    long long counting=0;
    for(int i=0 , j=0 ; i<n ;i++)
    {
        while(j<n && arr[j]-arr[i]<=d)
        {
            j++;
        }
        long long k = (long long)(j - i - 1);
        if(k>=2){counting += (k * (k - 1)) / 2LL;}

    }
    return counting;
}

int main() {
    //I preferred to use the dynamic programming method to reduce the time complexity
    int n;
    long long d;
    cin>>n>>d;
    long long arr[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
    cout<<Group(n,d,arr)<<endl;
    return 0;
}
