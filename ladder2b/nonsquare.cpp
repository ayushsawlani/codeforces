#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll ans =INT64_MAX;
    double n;
    cin>>n;
    ll flag=0;
    for(double s=0;s<=90;s++)
    {
        double temp=((-1)*s+sqrt(s*s+4*n))/2.0;
        ll x=temp;
        if(temp-x==0)
        {
            ll sum=0;
            while(x>0)
            {
                sum+=x%10;
                x=x/10;
            }
            if(sum==s)
            {
                flag=1;
                ans= min(ans,(ll)(temp));
            }
        }
    }
    if(flag==0)
        cout<<-1<<endl;
    else
    {
        cout<<ans<<endl;
    }
    
}