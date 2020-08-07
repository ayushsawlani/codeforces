#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    ll ans=0;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        for(ll j=0;j<m;j++)
        {
            if(temp[j]=='1')
                a[i][j]=1;
            else
            {
                a[i][j]=0;
            }
            
        }
    }
    for(ll i=n;i>0;i--)
    {
        for(ll j=m;j>0;j--)
        {
            ll flag2=0;
            for(ll k=i-1;k<n;k++)
            {
                for(ll l=j-1;l<m;l++)
                {
                    ll flag1=0;
                    for(ll x=k-i+1;x<=k;x++)
                    { 
                        for(ll y=l-j+1;y<=l;y++)
                        {
                            if(a[x][y]!=0)
                            {
                                flag1=1;
                            }
                        }
                    }
                    if(flag1==0)
                        flag2=1;
                }
            }
            if(flag2)
                ans=max(ans,2*(i+j));
        }
    }
    cout<<ans<<endl;
    
}