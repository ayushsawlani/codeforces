#include <bits/stdc++.h>
using namespace std;
int isgreater(string s1, string s2)
{
	int len_s=s1.size();
	for(int i=0;i<len_s;i++)
	{
		if(s1[i]<97)
			s1[i]+=32;
		if(s2[i]<97)
			s2[i]+=32;
		if(s1[i]<s2[i])
			return -1;
		else if(s1[i]>s2[i])
			return 1;
	}
	return 0;
}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<isgreater(s1,s2);
}
