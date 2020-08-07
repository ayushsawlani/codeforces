#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int ans=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int max_i=0;
	int min_i=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[max_i])
			max_i=i;
		if(arr[i]<arr[min_i])
			min_i=i;
	}
	int max=arr[max_i];
	int min=arr[min_i];
	for(int i=max_i;i>0;i--)
	{
		int temp=arr[i];
		arr[i]=arr[i-1];
		arr[i-1]=temp;
		ans++;
	}
	for(int i=0;i<n;i++)
		if(arr[i]==min)
			min_i=i;
	for(int i=min_i;i<n-1;i++)
	{
		int temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
		ans++;
	}
	cout<<ans;
}
	
		
