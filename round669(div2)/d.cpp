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
const ll inf = 9e14;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
class minst
{
    private:
        ve <ll> input, segtree;
        ll size, ksize;
    public:
        minst(ve <ll> in)
        {
            input=in;
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=inf;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=input[i-ksize+1];
            for(ll i=ksize-2;i>=0;i--)
                segtree[i]=min(segtree[2*i+1], segtree[2*i+2]);
        }
        ll getminutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return inf;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                return min(getminutil(l, r, i, mid, 2*seed+1),getminutil(l, r, mid+1, j, 2*seed+2));
            }
        }
        ll getmin(ll l, ll r)
        {
            return getminutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            segtree[treeind]=val;
            input[ind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                segtree[pa]=min(segtree[2*pa+1], segtree[2*pa+2]);
                treeind=pa;
            }
        }

};
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> stac;
    ve <ll> nextgreat(n, n);
    ve <ll> nextleast(n, n);
    ve <ll> prevgreat(n, -1);
    ve <ll> prevleast(n, -1);
    fr(i, 0, n-1)
    {
        if(sz(stac))
        {
            ll top=stac[sz(stac)-1];
            while(in[i]>=in[top])
            {
                nextgreat[top]=i;
                stac.pop_back();
                if(sz(stac))
                    top=stac[sz(stac)-1];
                else
                    break;
            }
        }
        stac.pb(i);
    }
    //outarr(i, nextgreat, n);
    //cout<<endl;
    stac.clear();
    fr(i, 0, n-1)
    {
        if(sz(stac))
        {
            ll top=stac[sz(stac)-1];
            while(in[i]<=in[top])
            {
                nextleast[top]=i;
                stac.pop_back();
                if(sz(stac))
                    top=stac[sz(stac)-1];
                else
                    break; 
           }
        }
        stac.pb(i);
    }
    stac.clear();
    frn(i, n-1, 0)
    {
        if(sz(stac))
        {
            ll top=stac[sz(stac)-1];
            while(in[i]<=in[top])
            {
                prevleast[top]=i;
                stac.pop_back();
                if(sz(stac))
                    top=stac[sz(stac)-1];
                else
                    break; 
           }
        }
        stac.pb(i);
    }
    stac.clear();
    frn(i, n-1, 0)
    {
        if(sz(stac))
        {
            ll top=stac[sz(stac)-1];
            while(in[i]>=in[top])
            {
                prevgreat[top]=i;
                stac.pop_back();
                if(sz(stac))
                    top=stac[sz(stac)-1];
                else
                    break; 
           }
        }
        stac.pb(i);
    }
    //outarr(i, nextleast, n);
    //cout<<endl;
    //(outarr(i, nextgreat, n);
    //cout<<endl;
    ve <ll> ans(n, inf);
    ans[n-1]=0;
    minst tree=(*new minst(ans));
    frn(i, n-1, 0)
    {
        if(i!=n-1)
            ans[i]=min(ans[i], 1+min(nextgreat[i]!=n?ans[nextgreat[i]]:inf, nextleast[i]!=n?ans[nextleast[i]]:inf));
        if(prevgreat[i]!=-1)
        {
            ans[prevgreat[i]]=min(ans[prevgreat[i]], 1+ans[i]);
        }
        if(prevleast[i]!=-1)
        {
            ans[prevleast[i]]=min(ans[prevleast[i]], 1+ans[i]);
        }
        //cout<<ans[i]<<endl;
    }
    frn(i, n-1, 0)
    {
   }
    cout<<ans[0]<<endl;
    //*/
}