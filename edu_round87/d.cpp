#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
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
        ll getans()
        {
            fr(i, ksize-1, 2*ksize-2)
            {
                if(segtree[i])
                    return i-(ksize-1);
            }
            return 0;
        }

};
ll bin(sumst &sumtree, ll x, ll n)
{
    ll i=0;
    ll j=n+4;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(sumtree.getsum(0, mid)>=x)
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
class sumbitree
{
    private:
        ve <ll> tree;
        ll n;
    public:
        ll getsum(ll index)
        {
            ll sum = 0; // Iniialize result 
        
            // index in BITree[] is 1 more than the index in arr[] 
            index = index + 1; 
        
            // Traverse ancestors of BITree[index] 
            while (index>0) 
            { 
                // Add current element of BITree to sum 
                sum += tree[index]; 
        
                // Move index to parent node in getSum View 
                index -= index & (-index); 
            } 
            return sum; 
        }
        void updateBIT(int index, int val) 
        {
            // index in BITree[] is 1 more than the index in arr[] 
            index = index + 1; 
        
            // Traverse all ancestors and add 'val' 
            while (index <= n) 
            { 
                // Add 'val' to current node of BI Tree 
                tree[index] += val; 

                // Update index to that of parent in update View 
                index += index & (-index); 
            } 
        } 
        sumbitree(ve <ll> arr)
        { 
            n=sz(arr);
            tree.resize(n+1);
            // Create and initialize BITree[] as 0 
            for (int i=1; i<=n; i++) 
                tree[i] = 0; 
            // Store the actual values in BITree[] using update() 
            for (int i=0; i<n; i++) 
                updateBIT(i, arr[i]); 
        
            // Uncomment below lines to see contents of BITree[] 
            //for (int i=1; i<=n; i++) 
            //     cout << BITree[i] << " "; 
        
        } 
};
ll bin1(sumbitree &sumtree, ll x, ll n)
{
    ll i=1;
    ll j=n;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(sumtree.getsum(mid)>=x)
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
    fastio
    ll n,q;
    cin>>n>>q;
    ve <ll> in(n);
    inarr(i, in, n);
    ve <ll> co(n+5, 0);
    fr(i, 0, n-1)
    {
        co[in[i]]++;
    }
/*    sumst sumtree=*(new sumst(co));
    while(q--)
    {
        ll _t;
        cin>>_t;
        if(_t>0)
        {
            sumtree.updatetree(_t, sumtree.getsum(_t, _t)+1);
        }
        else
        {
            ll p=bin(sumtree, -_t, n);
            sumtree.updatetree(p, sumtree.getsum(p, p)-1);
        }
    }
    cout<<sumtree.getans()<<endl;
    //*/
    sumbitree sumtree=*(new sumbitree(co));
    while(q--)
    {
        ll _t;
        cin>>_t;
        
        if(_t>0)
        {
            sumtree.updateBIT(_t, 1);
        }
        else
        {
            ll p=bin1(sumtree, -_t, n);
            sumtree.updateBIT(p, -1);
        }
        
    }
    
    fr(i, 1, n)
    {
        if(sumtree.getsum(i)-sumtree.getsum(i-1))
        {
            cout<<i;
            return 0;
        }
    }
    //*/
    cout<<0<<endl;
}