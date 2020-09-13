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
        ll a=0, b=0, c=0, d=0;
        ll n;
        cin>>n;
        ve <ll> va, vb, vc, vd, ans;
        set <string> str;
        ve <string> in(n);
        fr(i, 0, n-1)
        {
            string s;
            cin>>s;
            str.insert(s);
            in[i]=s;
        }
        fr(i, 0, n-1)
        {
            string s=in[i];
            ll la=sz(s)-1;
            if((s[0]=='0')&&(s[la]=='0'))
            {
                a++;
                va.pb(i+1);
            }
            else if((s[0]=='1')&&(s[la]=='1'))
            {
                d++;
                vd.pb(i+1);
            }
            else if((s[0]=='0')&&(s[la]=='1'))
            {
                string s1=s;
                reverse(all(s1));
                b++;
                if(str.find(s1)==str.end())
                {
                    vb.pb(i+1);
                }
            }
            else
            {
                string s1=s;
                reverse(all(s1));
                c++;
                if(str.find(s1)==str.end())
                {
                    vc.pb(i+1);
                }
            }
 
        }
        if((!(b))&&(!(c))&&(a)&&(d))
        {
            cout<<-1<<endl;
            continue;
        }
        fr(i, 0, ((b-c)/2)-1)
        {
            ans.pb(vb[i]);
        }
        fr(i, 0, ((c-b)/2)-1)
        {
            ans.pb(vc[i]);
        }
        cout<<sz(ans)<<endl;
        outarr(i, ans, sz(ans));
        cout<<endl;
    }
}