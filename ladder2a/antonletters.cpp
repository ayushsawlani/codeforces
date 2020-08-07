#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin, s);	
	int len_s=s.size();
	int ans=0;
	int arr[26];
	for(int i=0;i<26;i++)
		arr[i]=0;
	for(int i=0;i<len_s;i++)
	{
		if(((int)(s[i])-97>=0)&&((int)(s[i])-97<26))
			arr[(int)(s[i])-97]++;
	}
	for(int i=0;i<26;i++)
	{
		if(arr[i]>0)
			ans++;
	}
	cout<<ans;
}

