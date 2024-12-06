#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        long long pairs=0;
        cin>>n>>l>>r;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr , arr+n);
        for(int i=0;i<n;i++)
        {
            int low=l-arr[i];
            int high=r-arr[i];
            int start=lower_bound(arr+i+1 , arr+n , low)-arr;
            int ending=upper_bound(arr+i+1 , arr+n , high)-arr-1;

            if(start<=ending)
            {
                pairs+=(ending-start +1);
            }
        }

        cout<<pairs<<endl;
    }
    return 0;
}
