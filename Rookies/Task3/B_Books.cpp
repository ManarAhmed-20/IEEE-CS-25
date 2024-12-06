#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n ,t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //sort(arr , arr+n);
    int j=0,sum=0,max_num=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        while(sum>t){
            sum -=arr[j];
            j++;
        }
        max_num=max(max_num , i-j+1);
    }
    cout<<max_num<<endl;
    return 0;
}
