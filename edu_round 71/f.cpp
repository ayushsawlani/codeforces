#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 500000
int main()
{
    ll a[M+1]={0};
    ll p=707;
    ll update[p+1][p+1]={0};
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll type;
        cin>>type;
        ll x,y;
        cin>>x>>y;
        if(type==1)
        {
            a[x]+=y;
            for(ll i=1;i<p;i++)
            {
                update[i][x%i]+=y;
            }
        }
        else
        {
           if(x>=p)
            {
                ll ans=0;
                for(ll i=y;i<M+1;i=i+x)
                {
                    ans=ans+a[i];
                }
                cout<<ans<<endl;
            }
            else
            {
                cout<<update[x][y]<<endl;
            }
        }
    }
}