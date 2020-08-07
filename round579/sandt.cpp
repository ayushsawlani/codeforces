#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s,t;
    cin>>s>>t;
    ll len_t=t.size();
    ll len_s=s.size();
    ll i=0,j=0;
    ll first[len_t];
    ll last[len_t];
    while((i<len_s)&&(j<len_t))
    {
        if(s[i]==t[j])
        {
            first[j++]=i;
        }
        i++;
    }
    i=len_s-1;
    j=len_t-1;
    while((i>=0)&&(j>=0))
    {
        if(s[i]==t[j])
        {
            last[j--]=i;
        }
        i--;
    }
    ll ans=max(last[0],len_s-1-first[len_t-1]);
    for(ll i=1;i<len_t;i++)
    {
        ans=max(ans,last[i]-first[i-1]-1);
    }
    cout<<ans<<endl;
}