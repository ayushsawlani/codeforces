#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i=0,j=0;
	int len_s=s.size();
	while(1)
	{
		if(j>=len_s)
			break;
		if(j<=len_s-3)
		{
			if((s[j]=='W')&&(s[j+1]=='U')&&(s[j+2]=='B'))
			{
				j=j+2;
			}
			else 
				break;
		}
		else 
			break;
		j++;
	}
	i=j;
	int flag=0;
	while(1)
	{
		if(i>=len_s)
			break;
		if(i<=len_s-3)
		{
			if((s[i]=='W')&&(s[i+1]=='U')&&(s[i+2]=='B'))
			{
				i=i+2;
				if(flag==0)
					cout<<" ";
				flag=1;
			}
			else 
			{
				flag=0;
				cout<<s[i];
			}
		}
		else {
			flag=0;
			cout<<s[i];
		}
		i++;
	}
}

