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
    int i=0,j=n-1 ,ATime=0 , BTime=0 , ABars=0 , BBars=0;
    while(i<=j)
    {
        if(ATime<=BTime){
            ATime +=arr[i];
            ABars++;
            i++;
        }else{
            BTime +=arr[j];
            BBars++;
            j--;
        }
    }
    cout<<ABars<<" "<<BBars<<endl;
    return 0;
}
