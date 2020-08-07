#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll hp1,atk1,def1,hp2,atk2,def2,h,a,d;
    cin>>hp1>>atk1>>def1>>hp2>>atk2>>def2>>h>>a>>d;
    ll ans=INT64_MAX;
    ll c2=0;
    if(atk1<=def2)
    {
        c2+=(def2-atk1)+1;
    }
    for(ll i=0;1;i++)
    {
        for(ll j=c2;1;j++)
        {
            if((def1+i>=atk2))
            {
                ans=min(i*d+(j)*a,ans);
            }
            else
            {
                ll c3=hp2/(atk1+j-def2);
                if(hp2%(atk1+j-def2)>0)
                    c3++;
                ll req=c3*(atk2-def1-i)+1;
                ans=min(i*d+(j)*a+(max(req-hp1,(ll)0))*h,ans);
            }
            if(atk1+j-def2>=hp2)
                break;
        }
        if((def1+i>=atk2))
        {
            break;
        }
    }
    cout<<ans<<endl;
}
