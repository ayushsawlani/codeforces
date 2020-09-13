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
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        string ans="YES";
        ve <char> modi(k, '%');
        fr(i, 0, n-1) 
        {
            if(s[i]!='?')
            {
                if(modi[i%k]=='%')
                {
                    modi[i%k]=s[i];
                }
                else
                {
                    if(modi[i%k]!=s[i])
                        ans="NO";
                }
            }
        }
        ll c1=0, c2=0;
        fr(i, 0, k-1)
        {
            if(modi[i]=='1')
                c1++;
            else if(modi[i]=='0')
                c2++;
        }
        if(c1>k/2)
            ans="NO";
        if(c2>k/2)
            ans="NO";
        cout<<ans<<endl;

    }
}
