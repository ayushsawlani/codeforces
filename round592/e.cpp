#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll c1=1;
    ll c2=1;
    ll i=0;
    ll j=n-1;
    ll flag=0;
    ll ans=0;
    while(k>0)
    {
        if(i==j)
        {
            cout<<0<<endl;
            return 0;
        }
        else
        {
            if(c1<c2)
            {
                if(k>=(a[i+1]-a[i])*c1)
                {
                    k-=(a[i+1]-a[i])*c1;
                    i++;
                    c1++;
                }
                else
                {
                        a[i]+=(k/c1);
                        k=0;
                    
                }
            }
            else
            {
                if(k>=(a[j]-a[j-1])*c2)
                {
                    k-=(a[j]-a[j-1])*c2;
                    c2++;
                    j--;
             
                }
                else
                {
                        a[j]-=(k/c2);
                        k=0;
                }
            }          
        }
    }
    ans+=a[j]-a[i];
    cout<<ans<<endl;
}