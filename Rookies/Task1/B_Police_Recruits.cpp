#include <iostream>

using namespace std;

int main()
{
    int untreated=0;
    int officer=0;
    int n, event;
    cin>>n;
    for(int i=0 ; i<n ;i++){
        cin>>event;
        if(event==-1)//the crime has occurred
        {
           if(officer>0){officer--;}
           else{untreated++;}
        }
        else{ officer += event;}
    }
    cout<<untreated<<endl;
    return 0;
}
