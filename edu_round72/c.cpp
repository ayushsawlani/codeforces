#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int zero_count = 0,cur_value =0;
		ll ans = 0;
		for(int i=0;i<s.length();i++)
		{	cur_value = 0;
			if(s[i]=='0')
				zero_count++;
			else
			{
			for(int j=i;(j<i+18 && j<s.length());j++)
			{
					cur_value = cur_value*2 + s[j]-'0'; 
					if(j-i+1+zero_count>=cur_value || j-i+1==cur_value)
					{
						ans++;
						//cout<<"cur_value = "<<cur_value<<"  "<<j<<" "<<i<<endl;
					}

			}
				zero_count =0;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}