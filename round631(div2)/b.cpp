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
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ve <ll> in(n),count(n,0);
        ve <pair <ll,ll>> ans;
        inarr(i,in,n);
        ve <ll> gre1(n),gre2(n);
        ll j=-1;
        frn(i,n-1,0)
        {
            count[in[i]]++;
            if(count[in[i]]==2)
            {
                j=i;
                break;
            }
        }
        gre1[0]=in[0];
        fr(i,1,n)
        {
            gre1[i]=max(gre1[i-1],in[i]);
        }
        gre2[n-1]=in[n-1];
        frn(i,n-2,-1)
        {
            gre2[i]=max(gre2[i+1],in[i]);
        }
        setvector(count,0,n)
        fr(i,0,n)
        {
            count[in[i]]++;
            if(count[in[i]]>1)
                break;
            if((i+1==gre1[i])&&(n-(i+1)==gre2[i+1]))
            {
                if(i>=j)
                    ans.pb(pair <ll,ll>(i+1,n-(i+1)));
            }
        }
        cout<<sz(ans)<<endl;
        fr(i,0,sz(ans))
        {
            cout<<ans[i].fi<<" "<<ans[i].se<<endl;
        }
    }
}