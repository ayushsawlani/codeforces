#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll ans=(s.length()+1)/2;
    if(((s.length())%2)==1)
    
    {
        ll flag=0;
        for(ll i=1;i<s.length();i++)
            if(s[i]=='1')
                flag=1;
        if(flag==0)
            ans--;
    }
    cout<<ans<<endl;

}