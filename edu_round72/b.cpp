#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		ll d[n],h[n];
		ll dmax =0;
		ll dh[n];
		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>h[i];
			if(dmax<d[i])
			{
				dmax = d[i];
			}
			dh[i]=h[i]-d[i];
		}
		sort(dh,dh+n);
		ll ans = 0;
		if(dmax>=x)
			cout<<1<<endl;
		else
		{	
			if(dh[0]<0)
			{
				ans = (x-dmax)/abs(dh[0]) + 1;
				if((x-dmax)%abs(dh[0])!=0)
					ans+=1;
				cout<<ans<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}