#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr1[101],arr2[101];
	int n;
	int ans=0;
	cin >> n;
	for(int i=0;i<101;i++)
	{
		arr1[i]=0;
		arr2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int temp1,temp2;
		cin>>temp1>>temp2;
		arr1[temp1]++;
		arr2[temp2]++;
	}
	for(int i=0;i<101;i++)
	{
		ans=ans+arr1[i]*arr2[i];
	}
	cout<<ans;

}
