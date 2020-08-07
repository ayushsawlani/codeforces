#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q;
    cin>>q;
    for(ll t=0;t<q;t++)
    {
        ll ans=0;
        ll b,p,f,h,c;
        cin>>b>>p>>f>>h>>c;
        if(h>c)
        {
            if(2*p<=b)
            {
                b=b-2*p;
                ans+=(p*h);
                if(2*f<=b)
                {
                    b=b-2*f;
                    ans+=(f*c);
                }
                else
                {
                    ans+=((b/2)*c);
                }
                
            }
            else
            {
                ans+=((b/2)*h);
            }
        }
        else
        {
             if(2*f<=b)
            {
                b=b-2*f;
                ans+=(f*c);
                if(2*p<=b)
                {
                    b=b-2*p;
                    ans+=(p*h);
                }
                else
                {
                    ans+=((b/2)*h);
                }
                
            }
            else
            {
                ans+=((b/2)*c);
            }
            
        }
        
        cout<<ans<<endl;


    }
}