#include <iostream>
using namespace std;

int counter = 0,res = 0;
int n,x,y, z, mass[100][100];
void f(int p,int u,int counter)
{
	res = max(res,counter);
	for (int i=0;i<n;i++)
		if (i != p && mass[i][u])
			f(u,i,counter+mass[i][u]);
}
int main()
{
	cin>>n;
	for (int i=1; i<n; i++)
	{
		cin>>x>>y>>z;
		mass[x][y]=z;
		mass[y][x]=z;
	}
	f(-1,0,0);
	cout<<res<<endl;
	return 0;
}
