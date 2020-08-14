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
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(temp);
            c=1;
        }
        else
        {
            c++;
        }
        i++;   
    }
    if(i<n)
    {
        pair <ll,ll> temp;
        temp.first=a[i];
        temp.second=c;
        ans.push_back(temp);
        c=1;
    }
    return ans;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k, l;
        cin>>n>>k>>l;
        ve <ll> in(n);
        inarr(i, in, n);
        ve <pair <ll,ll>> util=compress_array(in, n);
        ll t=-1;
        string ans="Yes";
        fr(i, 0, sz(util)-1)
        {
            if((util[i].fi+k)<=l)
            {
                t=-1;
            }
            else if(util[i].fi>l)
            {
 //               cout<<1<<endl;
                ans="No";
                break;
            }
            else
            {
                ll maxt=(k+k+util[i].fi-l)%(2*k);
                ll mint=l-util[i].fi;
                if((t==-1)||((t>k)&&((t<maxt)||(maxt==0))))
                {
                    t=maxt;
                }
                //cout<<t<<endl;
                ll pos=util[i].fi;
                if(t<=k)
                    pos+=t;
                else
                {
                    pos+=(k-(t-k));
                }
                if(pos>l)
                {
                 //   cout<<pos<<" "<<k<<" "<<t<<endl;
                   // cout<<2<<endl;
                    ans="No";
                    break;
                }
                ll difft=(util[i].se-1)%(2*k);
                ll period=(util[i].se-1)/(2*k);
                /*cout<<endl;
                    cout<<difft<<endl;
                    cout<<mint<<" "<<t<<endl;
                    cout<<period<<endl;
                //*/
                if((period)||(difft>((mint-t+2*k)%(2*k))))
                {
                 //   cout<<3<<endl;
                    ans="No";
                    break;
                }
                else
                {
                    t=(difft+t+1)%(2*k);
                }
                
            }
            
        }
        cout<<ans<<endl;
    }
}