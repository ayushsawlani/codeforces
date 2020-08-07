#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(m*a<b)
		cout<<n*a;
	else
	{
		if(a*(n%m)<b)	
			cout<<((n/m)*b+a*(n%m));
		else
			cout<<(n/m+1)*b;
	}

}
