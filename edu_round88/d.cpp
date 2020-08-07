#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
class maxst
{
    private:
        ve <ll> input, segtree;
        ll size, ksize;
    public:
        maxst(ve <ll> in)
        {
            input=in;
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=-inf;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=input[i-ksize+1];
            for(ll i=ksize-2;i>=0;i--)
                segtree[i]=max(segtree[2*i+1], segtree[2*i+2]);
        }
        ll getmaxutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return -inf;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                return max(getmaxutil(l, r, i, mid, 2*seed+1),getmaxutil(l, r, mid+1, j, 2*seed+2));
            }
        }
        ll getmax(ll l, ll r)
        {
            return getmaxutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            segtree[treeind]=val;
            input[ind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                segtree[pa]=max(segtree[2*pa+1], segtree[2*pa+2]);
                treeind=pa;
            }
        }

};
class sumst
{
    private:
        ve <ll> segtree;
        ll size, ksize;
    public:
        sumst(ve <ll> in)
        {
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=0;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=in[i-ksize+1];
            for(ll i=ksize-2;i>=0;i--)
                segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        }
        ll getsumutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return 0;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                return getsumutil(l, r, i, mid, 2*seed+1)+getsumutil(l, r, mid+1, j, 2*seed+2);
            }
        }
        ll getsum(ll l, ll r)
        {
            return getsumutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            ll diff=segtree[treeind]-val;
            segtree[treeind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                segtree[pa]-=diff;
                treeind=pa;
            }
        }
};
ll bin1(maxst &maxtree, ll l, ll n, ll ele)
{
    ll i=l;
    ll j=n-1;
    while(i<j)
    {
        ll mid=(i+j+1)/2;
        if(maxtree.getmax(l, mid)<=ele)
        {
            i=mid;
        }
        else
        {
            j=mid-1;
        }
    }
    return i;
}
ll bin2(maxst &maxtree, ll l, ll ele)
{
    ll i=0;
    ll j=l;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(maxtree.getmax(mid, l)<=ele)
        {
            j=mid;
        }
        else
        {
            i=mid+1;
        }
    }
    return i;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <ll> in(n);
    inarr(i, in, n);
    maxst maxtree=(*new maxst(in));
    ll ans=0;
    ve <ll> pre(n), suf(n);
    pre[0]=in[0];
    suf[n-1]=in[n-1];
    fr(i, 1, n-1)
    {
        pre[i]=in[i]+pre[i-1];
        suf[n-i-1]=in[n-i-1]+suf[n-i];
    }
    maxst premax=(*new maxst(pre));
    maxst sufmax=(*new maxst(suf));
    fr(i, 0, n-1)
    {
        ll left=bin2(maxtree, i, in[i]);
        ll right=bin1(maxtree, i, n, in[i]);
        ans=max(ans,premax.getmax(i, right)-pre[i]+sufmax.getmax(left, i)-suf[i]);
    }
    cout<<ans<<endl;
}