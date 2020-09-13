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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
vector <pair <char,ll>> compress_array(string a, ll n)
{
    vector <pair <char ,ll>> ans;
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
    pair <ll,ll> temp;
    temp.first=a[i];
    temp.second=c;
    ans.push_back(temp);
    c=1;
    return ans;
}
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
        sort(s.begin(), s.end());
        if(k==1)
        {
            cout<<s<<endl;
            continue;
        }
        ve <pair <char,ll>> util=compress_array(s, n);
        string ans;
        if(sz(util)==1)
        {
            cout<<s.substr(0, ceil((util[0].se*1.0)/(k*1.0)))<<endl;
        }
        else
        {
            if(util[0].se<k)
            {
                cout<<s[k-1]<<endl;
                continue;
            }
            else if(util[0].se>k)
            {
                cout<<s.substr(k-1, n-k+1)<<endl;
                continue;
            }
            else
            {
                if(sz(util)==2)
                {
                    cout<<s[0];
                    fr(i, 0, ceil((util[1].se*1.0)/(k*1.0))-1)
                        cout<<util[1].fi;
                    cout<<endl;
                }
                else
                {
                    cout<<s.substr(k-1, n-k+1)<<endl;
                }
            }
            
        } 
    }
}