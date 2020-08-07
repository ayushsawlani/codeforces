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
vector <ll> compress_array(vector <ll> a, ll n)
{
    vector <ll> ans;
    ll i=0;
    ll c=1;
    while(i<n-1)
    {
        if(a[i]!=a[i+1])
        {
            pair <ll,ll> temp;
            temp.first=a[i];
            temp.second=c;
            ans.push_back(c);
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
        ans.push_back(c);
        c=1;
    }
   return ans;
}
int main()
{
    //fastio
    ll n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    ll c1=0;
    ve <ll> util;
    fr(i, 0, n-1)
    {
        if(s1[i]=='0')
        {
            c1++;
        }
        if(s2[i]=='0')
        {
            c1--;
        }
        if(s1[i]!=s2[i])
        {
            util.pb(s1[i]-'0');
        }
    }
    if(c1!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ve <ll> imp=compress_array(util, sz(util));
    ve <ll> imp1;
    ll ans=0;
    while(sz(imp))
    {
        ans++;
        fr(i, 0, sz(imp)-1)
        {
            imp[i]--;
        }
        ll j=0;
        while((imp[j]==0)&&(j<sz(imp)))
        {
            j++;
        }
        while(j<sz(imp))
        {
            if(imp[j]==0)
            {
                ll cap=0;
                j+=2;
                while((imp[j]==0)&&(j<sz(imp)))
                {
                    cap+=imp[j-1];
                    j+=2;
                }
                if(j-1<sz(imp))
                    cap+=imp[j-1];
                imp1[sz(imp1)-1]+=cap;
            }
            else
            {
                imp1.pb(imp[j]);
                j++;
            }
        }
        imp=imp1;
        imp1.clear();
    }
    cout<<ans<<endl;
}