#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[5][5];
	int i1,j1,dist=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==1)
			{
				i1=i;
				j1=j;
			}
		}
	}
	if(i1>2)
		dist=dist+i1-2;
	else
		dist=dist+2-i1;

	if(j1>2)
		dist=dist+j1-2;
	else
		dist=dist+2-j1;
	cout<<dist;
}	
