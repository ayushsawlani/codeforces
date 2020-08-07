#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,d,l;
    cin>>n>>d>>l;
    ll max=((n+1)/2)*l-(n/2);
    ll min=(n+1)/2-((n/2)*l);
    if((d<min)||(d>max))
        cout<<-1<<endl;
    else
    {
        ll sum=0;
        ll ans[n];
        if(d>0)
        {
            for(ll i=1;i<n;i=i+2)
            {
                ans[i]=1;
                sum--;
            }
            
                
        }
        else
        {
            for(ll i=1;i<n;i=i+2)
            {
                ans[i]=l;
                sum-=l;
            }
        }
            ll flag=0;
            for(ll i=0;i<n;i=i+2)
            {
                if(d-sum>((n-i+1)/2)*l)
                {
                    flag=1;
                    i=i-2;
                    sum--;
                }
                if(flag==0)
                {
                    if(i+2<n)
                    {
                        sum++;
                        ans[i]=1;
                    }
                    else
                    {
                        ans[i]=d-sum;
                        sum=d;
                    }
                    
                }
                else
                {
                    if(d-sum>=l)
                    {
                        ans[i]=l;
                        sum+=l;
                    }
                    else
                    {
                        ans[i]=d-sum;
                        sum=d;
                    }
                    
                }
            }
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
}