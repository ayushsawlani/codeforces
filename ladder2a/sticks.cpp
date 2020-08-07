#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;//hello
	int min=n;
	int max=n;
	if(min>m)
		min=m;
	if(max<m)
		max=m;
	if(min%2==0)
		cout<<"Malvika";
	else
		cout<<"Akshat";
}
