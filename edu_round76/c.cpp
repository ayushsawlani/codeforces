#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
ll c[200010];
int main()
{
 cin.tie(0);
ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        memset(c,0,(n+1)*sizeof(ll));
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll i=0,j=0;
        c[a[i]]++;
        ll ans=INT64_MAX;
        while((j<n)&&(i<n))
        {
            j++;
            if(j>=n)
                break;
            c[a[j]]++;
            while((c[a[j]]>1)&&(i<j))
            {
                ans=min(ans,j-i+1);
                c[a[i]]--;
                i++;
            }   
        }
        if(ans==INT64_MAX)
            cout<<-1<<endl;
        else
        {
            cout<<ans<<endl;
        }
    }
}