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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
bool check(string &s1, string &s2)
{
    ll n=sz(s1);
    ll c=0;
    fr(i, 0, n-1)
    {
        if(s1[i]!=s2[i])
        {
            c++;
        }
    }
    if(c>1)
        return false;
    return true;
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <string> in(n);
        inarr(i, in, n)
        ve <string> pos;
        ve <bool> flag;
        fr(i, 0, m-1)
        {
            fr(j, 0, 25)
            {
                string temp="";
                fr(k, 0, i-1)
                {
                    temp.pb(in[0][k]);
                }
                temp.pb(j+'a');
                fr(k, i+1, m-1)
                {
                    temp.pb(in[0][k]);
                }
                pos.pb(temp);
                flag.pb(true);
            }
        }
        fr(i, 0, sz(pos)-1)
        {
            for(auto it2: in)
            {
                if(check(pos[i], it2)==false)
                {
                    flag[i]=false;
                }
            }
        }
        string ans="-1";
        fr(i, 0,  sz(flag)-1)
        {
            if(flag[i])
            {
                ans=pos[i];
            }
        }
        cout<<ans<<endl;
    }
}