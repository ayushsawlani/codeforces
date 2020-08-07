#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>=0)
		cout << n;
	else
	{
		int last=n%10;
		int beforelast=(n%100)/10;
		if(last>beforelast)
			cout<<n/10-beforelast+last;
		else
			cout<<n/10;
	}
}
