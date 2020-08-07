#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector <int> v;
	int len_s=s.size();
	int len=(len_s+1)/2;
	for(int i=0;i<len;i++)
	{
		v.push_back((int)s[2*i]-48);
	}	
	sort(v.begin(),v.end());
	for(int i=0;i<len-1;i++)
		cout<<v[i]<<"+";
	cout<<v[len-1];
}
