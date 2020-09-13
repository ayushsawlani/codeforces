#include <bits/stdc++.h>
using namespace std;
#define M (ll)(1e9+7)
#define ll long long
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector <ll> daughter(n,-1);
        vector <ll> avail(n,1);
        for(ll i=0;i<n;i++)
        {
            ll k;
            cin>>k;
            for(ll j=0;j<k;j++)
            {
                ll temp;
                cin>>temp;
                temp--;
                if(avail[temp])
                {
                    if(daughter[i]==-1)
                    {
                        daughter[i]=temp;
                        avail[temp]=0;
                    }
                }
            }
        }
        ll check;
        for(check=0;check<n;check++)
        {
            if(daughter[check]==-1)
                break;
        }
       // cout<<check<<endl;
        if(check==n)
        {
            cout<<"OPTIMAL"<<endl;
            continue;
        }
        ll check2;
        for(check2=0;check2<n;check2++)
        {
            if(avail[check2])
                break;
        }
        cout<<"IMPROVE"<<endl<<check+1<<" "<<check2+1<<endl;

    }
}