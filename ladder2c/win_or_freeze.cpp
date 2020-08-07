#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll check(ll p)
{
    ll x=sqrt(p);
    for(ll i=2;i<=x;i++)
    {
        if(p%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
   ll q;
    cin>>q;
    ll c=0;
    ll x=sqrt(q);
    ll i=1;
    vector <ll> v;
    while((q>0)&&(i<=x))
    {
        if(q%i==0)
        {
            v.push_back(i);
            v.push_back(q/i);
        }
        i++;
    }
    if((v.size()==4)&&((check(v[3])==1)&&(check(v[2])==1)))
    {
        cout<<2<<endl;
    }
    else if(v.size()==2)
    {
        cout<<1<<endl<<0<<endl;
    }
    else
    {
        ll t=q;
        i=2;
        ll pro=1;
        c=0;
        while((q>0)&&(i<=x))
        {
            if(c>=2)
                break;
            if(q%i==0)
            {
                pro=pro*i;
                q=q/i;
                c++;
                if(c>=2)
                    break;
                if((check(q)==0)&&(q*pro!=t))
                {
                    pro=pro*q;
                    c++;
                }
            }
            else
            {
                i++;
            }
        }
        cout<<1<<endl<<pro<<endl;
    }
    
}