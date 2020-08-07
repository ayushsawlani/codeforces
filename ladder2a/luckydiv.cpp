#include <bits/stdc++.h>
using namespace std;
void f1(int arr1[1000],int n,int *arr_count)
{	
	if((n!=0)&&(n<=1000))
		arr1[(*arr_count)++]=n;
	
	if(n==0)
	{	
		f1(arr1,n+4,arr_count);
		f1(arr1,n+7,arr_count);
	}
	else if(n/10==0)
	{
		f1(arr1,n+40,arr_count);
		f1(arr1,n+70,arr_count);
	}
	else if(n/100==0)
	{
		f1(arr1,n+400,arr_count);
		f1(arr1,n+700,arr_count);
	}
	
}

int main()
{
	int arr1[1000];
	int *arr_count=(int *)(malloc(sizeof(int)));
	*arr_count=0;
	f1(arr1,0,arr_count);
	int input;
	cin>>input;
	int flag=0;
	for(int i=0;i<(*arr_count);i++)
	{
		if(input%arr1[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"YES";
	else
		cout<<"NO";
}
