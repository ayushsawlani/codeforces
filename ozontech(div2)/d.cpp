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
int main()
{
    //fastio
    ll n;
    cin>>n;
    ve <set <ll>> G(n);
    fr(i, 0, n-2)
    {
        ll a, b;
        cin>>a>>b;
        a--;
        b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    ve <ll> del(n, 0);
    while(1)
    {
        ve <ll> leaf;
        ll con;
        fr(i, 0, n-1)
        {
            if(sz(G[i])==1)
            {
                leaf.pb(i);
            }
            if(del[i]==0)
            {
                con=i+1;
            }
        }
        if(sz(leaf)==0)
        {
            cout<<"! "<<con<<endl;
            cout.flush();
            break;
        }
        cout<<"? "<<leaf[0]+1<<" "<<leaf[1]+1<<endl;
        cout.flush();
        ll w;
        cin>>w;
        if((w==leaf[0]+1)||(w==leaf[1]+1))
        {
            cout<<"! "<<w<<endl;
            cout.flush();
            break;
        }
        else
        {
            del[leaf[0]]=1;
            del[leaf[1]]=1;
            G[leaf[0]].clear();
            G[leaf[1]].clear();
            fr(i, 0, n-1)
            {
                G[i].erase(leaf[0]);
                G[i].erase(leaf[1]);
            }
        }
        
    } 
    //*/
}