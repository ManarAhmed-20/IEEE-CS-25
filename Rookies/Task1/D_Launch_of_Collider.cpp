#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n,positions[200000];
    int min_collision_time=INT_MAX; //Large number
    string directions;

    cin>>n;
    cin>>directions;

    for(int i=0 ; i<n ; i++){
        cin>>positions[i];
    }

    for (int i=0 ; i<n-1 ; i++){
        if(directions[i] == 'R' && directions[i+1]== 'L')
        {
            int time = (positions[i+1]-positions[i])/2;
            min_collision_time = min(min_collision_time , time);
        }
    }
    if(min_collision_time == INT_MAX)//no collision occured
        cout << -1 << endl;
    else
        cout<<min_collision_time<<endl;
    return 0;
}
