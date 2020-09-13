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
//cout << fixed << setprecision(9);
void dfs(ve <ve <ll>> &G, ve <ll> &col, ve <ll> &pi, ve <ll> &nonum, ll seed)
{
    col[seed]=1;
    ll f=1;
    for(auto chi:G[seed])
    {
        if(col[chi]==0)
        {
            f=0;
            pi[chi]=seed;
            dfs(G, col, pi, nonum, chi);
            nonum[seed]+=nonum[chi];            
        }
    }
    if(f)
        nonum[seed]=1;
}
class maxst
{
    private:
        ve <ll> input, segtree;
        ll size, ksize;
    public:
        maxst(ve <ll> in)
        {
            input=in;
            //outarr(i, input, sz(input));
            //cout<<endl;
            size=(ll)sz(in);
            ksize=1;
            for(;ksize<size;ksize=ksize*2);
            segtree.resize(2*ksize-1);
            for(ll i=0;i<2*ksize-1;i++)
                segtree[i]=-1;
            for(ll i=ksize-2+size;i>=ksize-1;i--)
                segtree[i]=i-ksize+1;
            for(ll i=ksize-2;i>=0;i--)
            {
                if(segtree[2*i+1]==-1)
                    segtree[i]=segtree[2*i+2];
                else if(segtree[2*i+2]==-1)
                    segtree[i]=segtree[2*i+1];
                else if(input[segtree[2*i+1]]>input[segtree[2*i+2]])
                    segtree[i]=segtree[2*i+1];
                else
                {
                    segtree[i]=segtree[2*i+2];
                }
            }        
        }
        ll getmaxutil(ll l, ll r, ll i, ll j, ll seed)
        {
            if((l>j)||(i>r))
            {
                return -1;
            }
            else if((i>=l)&&(j<=r))
            {
                return segtree[seed];
            }
            else
            {
                ll mid=(i+j)/2;
                ll p1=getmaxutil(l, r, i, mid, 2*seed+1);
                ll p2=getmaxutil(l, r, mid+1, j, 2*seed+2);
                if(p1==-1)
                    return p2;
                else if(p2==-1)
                    return p1;
                else if(input[p1]>input[p2])
                    return p1;
                else
                {
                    return p2;
                }
            }
        }
        ll getval(ll ind)
        {
            //cout<<"yo"<<endl;
            //cout<<ind<<endl;
            //cout<<input[ind]<<endl;
            return input[ind];
        }
        ll getmax(ll l, ll r)
        {
            //cout<<l<<" "<<r<<endl;
            if(l>r)
                return -1;
            return getmaxutil(l, r, 0, ksize-1, 0);
        }
        void updatetree(ll ind, ll val)
        {
            ll treeind=ind+ksize-1;
            //segtree[treeind]=val;
            input[ind]=val;
            while(treeind>0)
            {
                ll pa=(treeind-1)/2;
                ll i=pa;
                if(segtree[2*i+1]==-1)
                    segtree[i]=segtree[2*i+2];
                else if(segtree[2*i+2]==-1)
                    segtree[i]=segtree[2*i+1];
                else if(input[segtree[2*i+1]]>input[segtree[2*i+2]])
                    segtree[i]=segtree[2*i+1];
                else
                {
                    segtree[i]=segtree[2*i+2];
                }
                //segtree[pa]=max(segtree[2*pa+1], segtree[2*pa+2]);
                treeind=pa;
            }
        }

};
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, S;
        cin>>n>>S;
        ve <ve <ll>> G(n);
        map <pair <ll,ll>, ll> wt, cost;
        fr(i, 0, n-2)
        {
            ll a, b, w, c;
            cin>>a>>b>>w>>c;
            a--;
            b--;
            G[a].pb(b);
            G[b].pb(a);
            wt[pair <ll,ll>(a, b)]=w;
            wt[pair <ll,ll>(b, a)]=w;
            cost[pair <ll,ll>(a, b)]=c;
            cost[pair <ll,ll>(b, a)]=c;
        }
        ve <ll> col(n, 0), pi(n, -1), nonum(n, 0);
        dfs(G, col, pi, nonum, 0);
        ll sum=0;
        ve <ll> utilwt1, utilnum1, arr1;  
        ve <ll> utilwt2, utilnum2, arr2; 
        ll sz_arr1=sz(arr1);
        ll sz_arr2=sz(arr2); 
        fr(i, 1, n-1)
        {
            sum+=wt[pair <ll,ll>(i, pi[i])]*nonum[i];
            if(cost[pair <ll,ll>(i, pi[i])]==1)
            {
                utilwt1.pb(wt[pair <ll,ll>(i, pi[i])]);
                utilnum1.pb(nonum[i]);
                arr1.pb(utilnum1[sz_arr1]*ceil(utilwt1[sz_arr1]/2.0));
                sz_arr1++;
            }
            else
            {
                utilwt2.pb(wt[pair <ll,ll>(i, pi[i])]);
                utilnum2.pb(nonum[i]);
                arr2.pb(utilnum2[sz_arr2]*ceil(utilwt2[sz_arr2]/2.0));
                sz_arr2++;
            }
        }
        maxst tree1=(* new maxst(arr1));
        maxst tree2=(* new maxst(arr2));
        ll ans=inf;
        ve <ll> final1, final2;
        if(sz_arr1)
        {
            while(1)
            {
                ll ind=tree1.getmax(0, sz_arr1-1);
                ll val=tree1.getval(ind);
                if(val==0)
                    break;
                final1.pb(val);
                utilwt1[ind]-=ceil(utilwt1[ind]/2.0);
                tree1.updatetree(ind, utilnum1[ind]*ceil(utilwt1[ind]/2.0));
            }
        }
        if(sz_arr2)
        {
            while(1)
            {
                ll ind=tree2.getmax(0, sz_arr2-1);
                ll val=tree2.getval(ind);
                if(val==0)
                    break;
                final2.pb(val);
                utilwt2[ind]-=ceil(utilwt2[ind]/2.0);
                tree2.updatetree(ind, utilnum2[ind]*ceil(utilwt2[ind]/2.0));
            }
        }
        ll sz_final1=sz(final1);
        ll sz_final2=sz(final2);
        ll i=0, j=0;
        ll sum1=0;
        while((j<sz_final2)&&(sum-sum1>S))
        {
            sum1+=final2[j++];
        }
            j--;
        while((i<sz_final1)&&(sum-sum1>S))
        {
            sum1+=final1[i++];
        }
        i--;
        ans=min(ans, (i+1)+2*(j+1));
        while((i<sz_final1)&&(j>=0))
        {
            if(sum-sum1<=S)
            {
                //cout<<i<<" "<<j<<endl;
                ans=min(ans, (i+1)+2*(j+1));
                sum1-=final2[j--];
            }
            else
            {
                i++;
                if(i==sz_final1)
                    break;
                sum1+=final1[i];
            }
        }
        if(sum-sum1<=S)
            ans=min(ans, (i+1)+2*(j+1));
        while(i<sz_final1)
        {
            i++;
            if(i==sz_final1)
                break;
            sum1+=final1[i];
            if(sum-sum1<=S)
                ans=min(ans, (i+1)+2*(j+1));
        }
         if(sum-sum1<=S)
            ans=min(ans, (i+1)+2*(j+1));
        
        while(j>=0)
        {
            if(sum-sum1<=S)
                ans=min(ans, (i+1)+2*(j+1));
            sum1-=final2[j--];
        }
        if(sum-sum1<=S)
            ans=min(ans, (i+1)+2*(j+1));        
        cout<<ans<<endl;
    }
}