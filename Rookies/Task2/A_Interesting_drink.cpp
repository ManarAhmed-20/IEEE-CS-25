#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int s, int value)
{
    int r = 0;
    int l = s - 1;
    int total = 0;

    while (r <= l)
    {
        int mid = (l + r) / 2;
        if (value >= arr[mid])
        {
            total = mid + 1;
            r = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int q;
    cin >> q;
    while (q--)
    {
        int mi;
        cin >> mi;
        int result = binarySearch(arr, n, mi);
        cout << result << endl;
    }
    return 0;
}
