#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>m>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int min =arr[m-1]-arr[0];
	for(int i=m;i<n;i++)
	{
		if(min>arr[i]-arr[i-m+1])
			min=arr[i]-arr[i-m+1];
	}
	cout<<min;
}
