#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
#define ll int
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
//#define ll long long int
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ld inf = 1e6;
const ld unit=1e-10;
//uncomment for accurate decimal precision.
ld dfs1(ve <ve <ll>> &G, map <pair <ll,ll>, ll> &wt, ve <ll> &yess, ve <pair <ll,ll>> &assign, ve <ll> &c, ll seed)
{
    //cout<<seed<<endl;
    yess.pb(seed);
    c[seed]=1;
    ld ans=-inf;
    for (auto chi:G[seed])
    {
        pair <ll, ll> temp(wt[pair<ll,ll>(chi, seed)]-assign[seed].fi,(-assign[seed].se));
        if(c[chi]==0)
        {
            assign[chi]=temp;
            ans=max(ans, dfs1(G, wt, yess ,assign, c, chi));
        }
        else
        {
            if(temp!=assign[chi])
            {
                if(temp.se==assign[chi].se)
                    ans=max(ans, inf);
                else
                {
                    ans=max(ans, ((ld)(temp.fi-assign[chi].fi))/((ld)(-temp.se+assign[chi].se)));
                }
            }
        }    
    }
   //cout<<seed+1<<" "<<ans<<endl;
    return ans;
}
ld func(ve <ll> &yess, ve <pair <ll,ll>> &assign, ld helo)
{
    ld ans=0;
    for(auto j:yess)
    {
        ans+=max(((ld)assign[j].fi+helo*((ld)assign[j].se)),-((ld)assign[j].fi+helo*((ld)assign[j].se)));
    }
    //cout<<ans<<" "<<helo<<endl;
    return ans;
}
int main()
{
    cout << fixed << setprecision(6);
    fastio
    ll n, m;
    cin>>n>>m;
    ve <ve <ll>> G(n);
    map <pair <ll,ll>, ll> wt;
    ll f=0;
    fr(i, 0, m-1)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        a--;
        b--;
        if(wt.find(pair <ll, ll>(a, b))==wt.end())
        {
            wt[pair <ll,ll>(a, b)]=c;
            wt[pair <ll,ll>(b, a)]=c;
        }
        else
        {
            if(wt[pair <ll,ll>(a, b)]!=c)
            {
                f=1;
            }
        }
        G[a].pb(b);
        G[b].pb(a);
    }
    if(f){
        cout<<"NO"<<endl;
        return 0;
    }
    ve <pair <ll,ll>> assign(n, pair <ll,ll>(0, 1));
    ve <ll> yess;
    ve <ll> c(n, 0);
    ve <double> ans(n);
    fr(i, 0, n-1)
    {
        //cout<<i<<endl;
        if(c[i]==0)
        {
            ld oof=dfs1(G, wt, yess, assign, c, i);
            //outarr(i, yess, sz(yess));
            //cout<<endl;
            if(oof==inf)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else if(oof==-inf)
            {
                ld l=-inf, r=inf;
                while(l<r)
                {
                    ld m=(l+r)/2.0;
                    ld r1, r2, r3;
                    r1=func(yess, assign, m-unit);
                    r2=func(yess, assign, m);
                    r3=func(yess, assign, m+unit);
                    if((r1>r2)&&(r2<r3))
                    {
                        oof=m;
                        break;
                    }
                    else if(r1<r3)
                    {
                        r=m-unit;
                    }
                    else if(r3<r1)
                    {
                        l=m+unit;
                    }
                    else
                    {
                        oof=m;
                        break;
                    }
                    
                }
                if(oof==-inf)
                    oof=r;
            }
            for(auto j:yess)
            {
                ans[j]=(ld)assign[j].fi+(ld)assign[j].se*oof;
            }
            //cout<<oof<<endl;
            yess.clear();
        }
    }
    for(auto i:wt)
    {
        ld dif=ans[i.fi.fi]+ans[i.fi.se]-i.se;
        if((dif>=1e-6)||(dif<=-1e-6))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    outarr(i, ans, n);
    cout<<endl;
    //*/
}