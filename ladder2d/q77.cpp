#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
int main()
{
    cout << fixed << setprecision(9);
    //fastio
    ll n, m;
    cin>>n>>m;
    ve <pair <ll,ll>> ani(n);
    fr(i, 0, n-1)
    {
        cin>>ani[i].fi;
        ani[i].se=i;
    }
    sort(all(ani));
    ve <set <ll>> G(n);
    fr(i, 0, m-1)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    ve <ll> clan(n, -1), cou(n, 1);
    ve <ve <ll>> clanmember(n);
    clan[ani[n-1].se]=ani[n-1].se;
    clanmember[ani[n-1].se].pb(ani[n-1].se);
    ld ans=0;
    frn(i, n-2, 0)
    {
        ve <ll> compute;
        set <ll> check;
        ll mainclan=ani[i].se;
        for(auto j:G[ani[i].se])
        {
            if((clan[j]!=-1)&&(check.find(clan[j])==check.end()))
            {
                compute.pb(cou[clan[j]]);
                if(cou[mainclan]<cou[clan[j]])
                {
                    mainclan=clan[j];   
                }
                check.insert(clan[j]);
            }
        }
        ll s1=1;
        fr(j, 0, sz(compute)-1)
        {
            ans+=(s1*compute[j]*ani[i].fi);
            s1+=compute[j];
        }
        cou[mainclan]=s1;
        clan[ani[i].se]=mainclan;
        clanmember[mainclan].pb(ani[i].se);
        for(auto j:check)
        {
            if(j!=mainclan)
            {
                cou[j]=0;
                for(auto ele:clanmember[j])
                {
                    clan[ele]=mainclan;
                    clanmember[mainclan].pb(ele);
                }
                clanmember[j].clear();
            }
        }
    }
    cout<<(2*ans)/((n)*(n-1))<<endl;
    //*/
}