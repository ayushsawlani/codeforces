#include <bits/stdc++.h>
using namespace std;
int *merge(int arr1[], int arr2[], int arr_c1, int arr_c2)
{
	int *arr=(int *)(malloc((arr_c1+arr_c2)*sizeof(int)));
	int p1=0,p2=0,p=0;
	while(p<arr_c1+arr_c2)
	{
		if(p1<arr_c1)
		{
			if(p2>=arr_c2)
				arr[p++]=arr1[p1++];
			else if(arr1[p1]<arr2[p2])
				arr[p++]=arr1[p1++];
			else 
				arr[p++]=arr2[p2++];
		}
		else
			arr[p++]=arr2[p2++];
	}
	return 
		arr;
}
			

int main()
{
	int n;
	cin >> n;
	int n1,n2;
	cin >> n1;
	int arr1[n1];
	for(int i=0;i<n1;i++)
		cin>>arr1[i];
	cin>>n2;
	int arr2[n2];
	int *arr;
	for(int i=0;i<n2;i++)
		cin>>arr2[i];
	sort(arr1,arr1+n1);
	sort(arr2,arr2+n2);
	arr=merge(arr1,arr2,n1,n2);
	int flag=0;
	for(int i=1;i<n1+n2;i++)
	{
		if(arr[i]-arr[i-1]>1)
			flag=1;
	}
	if(arr[0]!=1)
		flag=1;
	if(arr[n1+n2-1]!=n)
		flag=1;
	if(flag==0)
		cout<<"I become the guy.";
	else 
		cout<<"Oh, my keyboard!";
}
