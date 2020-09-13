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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        ve <ll> cou(66, 0);
        ll s=0;
        fr(i, 0, m-1)
        {
            ll _t;
            cin>>_t;
            s+=_t;
            cou[log2(_t)]++;
        }
        if(s<n)
        {
            cout<<-1<<endl;
            continue;
        }
        ve <ll> hello(66, 0);
        fr(i, 0, 65)
        {
            hello[i]=n%2;
            n=n/2;
        }
        ll ans=0;
        fr(i, 0, 64)
        {
            if(cou[i]==0)
            {
                if(hello[i])
                {
                    ll j=i;
                    while(cou[j]==0)
                    {
                        j++;
                    }
                    while(j>i)
                    {
                        cou[j]--;
                        cou[j-1]+=2;
                        ans++;
                        j--;
                    }
                }
            }
            cou[i]-=hello[i];
            hello[i]=0;
            cou[i+1]+=cou[i]/2;
            cou[i]=cou[i]%2;
        } 
        cout<<ans<<endl;  
    }
}