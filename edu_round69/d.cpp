#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cost(ll m,ll k,ll *a,ll i, ll j)
{
    ll n=j-i;
    if(i>0)
    {
        if(n%m!=0)
            return (a[j-1]-a[i-1]-(k)*(n/m+1));
        else
        {
            return(a[j-1]-a[i-1]-(k)*(n/m));
        }
    }   
    else
    {
        if(n%m!=0)
            return (a[j-1]-(k)*(n/(m+1)));
        else
        {
            return(a[j-1]-(k)*(n/m));
        }
 
    }
    
}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n+1];
    a[0]=0;
    for(ll i=1;i<n+1;i++)
    {
        ll temp;
        cin>>temp;
        a[i]=temp+a[i-1];
    }
    ll ans=0;
    ll p=0;
    ll best[n]={0};
    for(ll i=m-1;i<n;i++)
    {
        if(i>=m)
            best[i]=max(a[i+1]-a[i+1-m]-k+best[i-m],p);
        else
        {
            best[i]=max(a[i+1]-a[i+1-m]-k,p);
            
        }
        
    }
    for(ll i=-1;i<n;i++)
    {
        if(i>=0)
        {
            ll x=best[i];
            for(ll j=i+1;((j<i+m+1)&&(j<n));j++)
            {
                x=max(x,a[j+1]-a[i+1]-k+best[i]);
            }
            ans=max(ans,x);
        }
        else
        {
            ll x=0;
            for(ll j=0;(j<m)&&(j<n);j++)
            {
                x=max(x,a[j+1]-a[0]-k);
            }
            ans=max(ans,x);
        }
    }

    cout<<ans<<endl;

}