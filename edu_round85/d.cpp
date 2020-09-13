#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ll func(ll x)
{
    if(x==0)
        return 0;
    else
    {
        return x*(x-1)+1;
    }
}
ll rea(ll x)
{
    if(x==1)
        return 1;
    else
        return (x-1)*2;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        ll i=1,j=n,range_l=-1,range_r=-1;
        ll m;
        while(i<j)
        {
            m=(i+j+1)/2;
            if(m*(m-1)+1<l-1)
                i=m;
            else if(m*(m-1)+1>l-1)
                j=m-1;
            else
                break;
        }
        range_l=j;
        i=1,j=n;
        while(i<j)
        {
            m=(i+j+1)/2;
            if(m*(m-1)+1<r-1)
                i=m;
            else if(m*(m-1)+1>r-1)
                j=m-1;
            else
                break;
        }
        range_r=j;
        ve <ll> ans;
        ve <ll> start;
        ve <ll> end;
        ll it=l-func(range_l)-1;
        while(sz(ans)<r-l+1)
        {
            if(it>=rea(range_l+1))
                break;
            if(it%2==0)
                ans.pb(range_l+1);
            else
            {
                ans.pb(it<rea(range_l+1)-1?(it+3)/2:1);
            }
            it++;
        }
        fr(i,range_l+2,range_r+1)
        {
            if(i==1)
            {
                ans.pb(1);
                continue;
            }
            else
            {
                fr(j,0,(i-1)*2-2)
                {
                    if(j%2==0)
                        ans.pb(i);
                    else
                    {
                        ans.pb((j+3)/2);
                    }
                }
                ans.pb(i);
                ans.pb(1);
            }
        }
        it=max((ll)0, l-func(range_r)-0);
        while(sz(ans)<r-l+1)
        {
            if(it>=rea(range_r+1))
                break;
            if(it%2==0)
                ans.pb(range_r+1);
            else
            {
                ans.pb(it<rea(range_r+1)-1?(it+3)/2:1);
            }
            it++;
        }
        outarr(i,ans,sz(ans));
        cout<<endl; 
    }
}