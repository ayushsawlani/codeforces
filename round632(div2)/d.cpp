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
int main()
{
    //fastio
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ve <ve <ll>> util;
    ll m1=0;
    ll m2=0;
    while(1)
    {
        ll flag=0;
        ve<ll> temp;
        fr(i,0,n-1)
        {
            if((s[i]=='R')&&(s[i+1]=='L'))
            {
                flag=1;
                temp.pb(i+1);
                m1++;
            }
        }
        if(flag==0)
            break;
        fr(i,0,sz(temp))
        {

                char _temp;
            swap(s[temp[i]-1],s[temp[i]],_temp);
        }
        util.pb(temp);
        m2++;
    }
    if((k>m1)||(k<m2))
    {
        cout<<-1<<endl;
        return 0;
    }
    ve <ve <ll>> ans;
    ll flag=0;
    fr(i,0,sz(util))
    {
        if(flag==0)
        {
            ll st=-1;
            fr(j,0,sz(util[i]))
            {
                if(m2-i==k)
                {
                    flag=1;
                    st=j;
                    break;
                }
                ans.pb(ve <ll>(1,util[i][j]));
                k--;
            }
            if(flag)
            {
                ve<ll> temp;
                fr(j,st,sz(util[i]))
                {
                    temp.pb(util[i][j]);
                }
                ans.pb(temp);
                k--;
            }
        }
        else
        {
            ans.pb(util[i]);
        }
    }
    //cout<<sz(ans)<<endl;
    fr(i,0,sz(ans))
    {
        cout<<sz(ans[i])<<" ";
        outarr(j,ans[i],sz(ans[i]));
        cout<<endl;
    }
}