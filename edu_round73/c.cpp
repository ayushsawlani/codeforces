#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll c,m,x;
        cin>>c>>m>>x;
        ll m1=min(c,m);
        ll m2=max(c,m);
        ll ans=0;
        if(m1<=m2+x-m1)
        {
            ans=m1;
        }
        else
        {
            ans=x;
            m1-=x;
            m2-=x;
            ans+=m2-m1;
            ll temp=m2-m1;
            m2-=2*temp;
            m1-=temp;
            ans+=(m2+m1)/3;
        }
        cout<<ans<<endl;
        
        
    }   
}
