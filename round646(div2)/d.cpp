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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ve <ve <ll>> in(k);
        fr(i, 0, k-1)
        {
            ll num;
            cin>>num;
            while(num--)
            {
                ll t3;
                cin>>t3;
                in[i].pb(t3);
            }
        }
        ll i=1;
        ll j=n;
        ve <ll> get;
        fr(i, 1, n)
        {
            get.pb(i);
        }
        cout<<"? "<<n<<" ";
        outarr(i, get, n);
        cout.flush();
        ll maxele;
        cin>>maxele;
        ve <ll> ans(k, maxele);
        while(i<j)
        {
            ll mid=(i+j)/2;
            ve <ll> ask;
            fr(it, 1, mid)
            {
                ask.pb(it);
            }
            cout<<"?"<<" ";
            cout<<sz(ask)<<" ";
            outarr(it, ask, sz(ask))
            cout.flush();
            ll mad;
            cin>>mad;
            if(mad==maxele)
            {
                j=mid;
            }
            else
            {
                i=mid+1;
            }
        }
        ll yes=i;
        fr(i, 0, k-1)
        {
            ve <ll> col(n+4, 0);
            ll f=0;
            for(auto it1:in[i])
            {
                col[it1]=1;
                if(it1==yes)
                {
                    f=1;
                }
            }
            if(f)
            {
                ve <ll> ask;
                fr(j, 1, n)
                {
                    if(col[j]==0)
                    {
                        ask.pb(j);
                    }
                }
                cout<<"?"<<" ";
                cout<<sz(ask)<<" ";
                outarr(j, ask, sz(ask));
                cout.flush();
                int x;
                cin>>x;
                ans[i]=x;
                break;
            }
        }
        cout<<"!"<<" ";
        outarr(i, ans, k);
        cout<<endl;
        cout.flush();
        string tem;
        cin>>tem;
    }
}