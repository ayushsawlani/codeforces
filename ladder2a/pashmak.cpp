#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
	{
		int dist=y2-y1;
		if(dist<0)
			dist=(-1)*dist;
		cout<<x1+dist<<" "<<y1<<" "<<x2+dist<<" "<<y2;
	
	}
	else if(y1==y2)
	{
		int dist=x2-x1;
		if(dist<0)
			dist=(-1)*dist;
		cout<<x1<<" "<<y1+dist<<" "<<x2<<" "<<y2+dist;
	}
	else
		if((x2-x1==y2-y1)||(x2-x1==y1-y2))
			cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
		else 
			cout<<-1;
}
