#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len_s=s.size();
	for(int i=0;i<len_s;i++)
	{
		if((s[i]!='a')&&(s[i]!='e')&&(s[i]!='i')&&(s[i]!='o')&&(s[i]!='u')&&(s[i]!='y')&&(s[i]!='A')&&(s[i]!='E')&&(s[i]!='I')&&(s[i]!='O')&&(s[i]!='U')&&(s[i]!='Y'))
		{
       			if(s[i]<97)
				s[i]=s[i]+32;
			cout<<"."<<s[i];
		}			
	}
}
