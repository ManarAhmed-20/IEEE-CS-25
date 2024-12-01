#include <iostream>

using namespace std;

bool isLucky(int num)
{
    while(num>0){
        int digit = num%10;
        if(digit != 4 && digit != 7)
        {
            return false;
        }
        num /=10;
    }
    return true;
}

bool almostLucky(int num)
{
    for (int i = 1; i <= num; ++i) {
        if (isLucky(i) && num % i == 0) {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    if(isLucky(n) || almostLucky(n))
    {
        cout<<"YES"<<endl;
    }
    else{cout<<"NO"<<endl;}

    return 0;
}
