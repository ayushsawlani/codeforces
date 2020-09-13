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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
const ll inf = 9e18;
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
ll bin3(ve <ve <ll>> &ar, ll l, ll r,ll x)
{
    ll i=l;
    ll j=r;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(ar[mid][0]>x)
            j=mid;
        else
        {
            i=mid+1;
        }
    }
    if(ar[i][0]<=x)
        return inf;
    return i;
}
int main()
{
    fastio
    ll n;
    cin>>n;
    ve <ve <ll>> in(n, ve <ll>(4));
    fr(i, 0, n-1)
    {
        inarr(j, in[i], 4);
    }
    sort(in.begin(), in.end());
    ve <ll> a1,a2;
    fr(i, 0, n-1)
    {
        a1.pb(in[i][2]);
        a2.pb(in[i][3]);
    }
    maxst maxtree=(*new maxst(a1));
    minst mintree=(*new minst(a2));
    fr(i, 0, n-2)
    {
        ll x=min(bin3(in, i+1, n-1, in[i][1]),n);
        if(x>i+1)
        {
            ll m1=maxtree.getmax(i+1, x-1);
            ll m2=mintree.getmin(i+1, x-1);
            if(m1>in[i][3])
            {
       //         cout<<"x"<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
            if(m2<in[i][2])
            {
     //           cout<<"y"<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    fr(i, 0, n-1)
    {
        ll _t;
        swap(in[i][0], in[i][2], _t);
        swap(in[i][1], in[i][3], _t);
    }
    sort(in.begin(), in.end());
    a1.clear();
    a2.clear();
    fr(i, 0, n-1)
    {
        a1.pb(in[i][2]);
        a2.pb(in[i][3]);
    }
    maxtree=(*new maxst(a1));
    mintree=(*new minst(a2));
    fr(i, 0, n-2)
    {
        ll x=min(bin3(in, i+1, n-1, in[i][1]),n);
        if(x>i+1)
        {
            ll m1=maxtree.getmax(i+1, x-1);
            ll m2=mintree.getmin(i+1, x-1);
            if(m1>in[i][3])
            {
       //         cout<<"x"<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
            if(m2<in[i][2])
            {
     //           cout<<"y"<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
   cout<<"YES"<<endl;
    //*/
}