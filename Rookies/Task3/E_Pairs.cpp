#include <iostream>
#include <algorithm>
using namespace std;
bool ISexists(int arr[],int start,int n,int target)
{
    int r = start;
    int l = n - 1;

    while (r <= l)
    {
        int mid = (l + r) / 2;
        if(target == arr[mid]){
            return true;
        }
        else if (target > arr[mid])
        {
            r = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long pairs=0;
    for(int i=0;i<n;i++){
        int target=k+arr[i];
        if(ISexists(arr,i+1,n,target)){
            pairs++;
        }
    }
    cout<<pairs<<endl;
    return 0;
}
