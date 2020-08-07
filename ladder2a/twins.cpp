#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> v;
	int n;
	int temp,sum=0,sum1=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		sum+=temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for(int i=n-1;i>=0;i--)
	{
		sum1+=v[i];
		if(sum1>sum/2)
		{
			cout<<n-i;
			break;
		}
	}
}
