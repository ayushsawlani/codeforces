#include <bits/stdc++.h>
using namespace std;
#define ll long long
void next(string &s)
{
    ll flag=0;
    for(ll i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            flag=1;
            s[i]='1';
            break;
        }
        else
        {
            s[i]='0';
        }
    }
    if(flag==0)
        s[0]= '-';
    
}

int main()
{
    string s;
    cin>>s;
    ll x=s.size();
    ll ans=pow(2,x-1)-1;
    string s1;
    s1.push_back('1');
    ll i=1;
    while(i<x)
    {
        s1.push_back('0');
        i++;
    }
    while((s1.compare(s)<=0)&&(s1[0]!='-'))
    {
        ans++;
        next(s1);
    }
    cout<<ans<<endl;
}