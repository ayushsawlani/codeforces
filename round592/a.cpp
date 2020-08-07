#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll flag=0;
        ll n1=0,n2=k-n1;
        for(;n1<=k;n1++)
        {
            n2=k-n1;
            if((n1*c>=a)&&(n2*d>=b))
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<n1<<" "<<n2<<endl;
        else
        {
            cout<<-1<<endl;
        }
        
    }
}