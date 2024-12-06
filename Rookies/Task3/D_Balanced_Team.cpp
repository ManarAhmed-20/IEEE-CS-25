#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    int i=0,j=0,team=0;
    while (j<n){
        if(arr[j]-arr[i]<=5){
            team=max(team , j-i+1);
            j++;
        }else{
            i++;
        }
    }
    cout<<team<<endl;
    return 0;
}
