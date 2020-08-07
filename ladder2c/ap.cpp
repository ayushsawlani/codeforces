#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;    
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(a,a+n);
    ll d[n-1];
    map <ll,ll> m;
    for(ll i=0;i<n-1;i++)
    {
        d[i]=a[i+1]-a[i];
        if(m.find(d[i])!=m.end())
        {
            m[d[i]]++;
        }
        else
        {
            m[d[i]]=1;
        }
    }
    vector <ll> v;
    if(m.size()>2)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(m.size()==1)
    {
        v.push_back(a[0]-d[0]);
        if(d[0]!=0)
            v.push_back(a[n-1]+d[0]);
        if(n==2)
        {
            if((d[0]%2==0)&&(d[0]!=0))
            {
                v.push_back(a[0]+d[0]/2);
            }
        }
    }
    else
    {
        ll x[2];
        x[0]=d[0];
        for(ll i=1;i<n-1;i++)
        {
            if(d[i]!=x[0])
            {
                x[1]=d[i];
                break;
            }
        }
        sort(x,x+2);
        if((x[1]!=x[0]*2)||(m[x[1]]>1))
        {
            cout<<0<<endl;
            return 0;
        }
        else
        {
            ll i=0;
            while(d[i]!=x[1])
            {
                i++;
            }
            v.push_back(a[i]+x[0]);
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    
}