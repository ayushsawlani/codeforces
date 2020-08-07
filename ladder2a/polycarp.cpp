#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans=0;
	int c=0;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);
	while(1)
	{
		if(c==n)
			break;
		if(arr[c]>=ans+1)
			ans++;
		c++;
	}
	cout<<ans;
}	
