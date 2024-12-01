#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, totalSwaps=0;
    cin>>n;
    int arr[100];//max number of soldiers

    for (int i=0; i<n ; i++){
        cin>>arr[i];
    }
    int maxHeight = max_element(arr,arr+n)-arr;
    //int minHeight = min_element(arr,arr+n)-arr;
    //find the latest min element
    int minHeight = -1;
    int minValue = *min_element(arr, arr + n);
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == minValue) {
            minHeight = i;
            break;
        }
    }

    totalSwaps =maxHeight+(n-1-minHeight);

    if(maxHeight>minHeight)
        {totalSwaps--;}

    cout<<totalSwaps<<endl;
    return 0;
}
