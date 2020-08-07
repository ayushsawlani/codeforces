#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll a,b,m1=0,m2=0;
    vector <ll> v1,v2;
    cin>>a>>b;
    for(ll i=0;i<s.size();i++)
    {
        m1=((m1*10+(ll)s[i]-48)%a);
        if(m1==0)
        {
            v1.push_back(i+1);
        }
    }
    ll x=1;
    for(ll i=s.size()-1;i>=0;i--)
    {
        m2=((m2+((ll)s[i]-48)*x)%b);
        x=((x*10)%b);
        if(m2==0)
            v2.push_back(i);
    }
    sort(v2.begin(),v2.end());
    ll i=0,j=0;
    ll ans=-1;
    while((i<v1.size())&&(j<v2.size()))
    {
        if(v1[i]<v2[j])
        {
            i++;
        }
        else if(v1[i]==v2[j])
        {
            ans=v1[i];
            break;
        }
        else
        {
            j++;
        }
    }
    
    while((s[ans]=='0')&&(ans<s.size()))
    {
        ans++;
    }
    if((ans==-1)||(ans==s.size()))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<ans;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    for(ll i=ans;i<s.size();i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}