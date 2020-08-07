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
ve <ll> z_array(string s)
{
    ve <ll> ans(sz(s));
    ans[0]=-1;
    ll l=0,r=0;
    for(ll i=1;i<s.size();i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while((r<s.size())&&(s[r]==s[r-i]))
            {
                r++;
            }
            r--;
            ans[i]=r-l+1;
        }
        else
        {
            ll k=i-l;
            if(ans[k]+i<=r)
            {
                ans[i]=ans[k];
            }
            else
            {
                l=i;
                while((r<s.size())&&(s[r]==s[r-i]))
                {
                    r++;
                }
                r--;
                ans[i]=r-l+1;
            }
            
        }
    }
    return ans;
}
ll solution(string s)
{
    ll n=sz(s);
    if(n%2)
        return 2;
    string left=s.substr(0, n/2);
    string right=s.substr(n/2, n/2);
    if(left!=right)
        return 1;
    return solution(left);

}
int main()
{
    //fastio
    string s;
    cin>>s;
    ll n=sz(s);
    if(n==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    string s1;
    fr(i, 0, (n)/2-1)
    {
        s1.pb(s[i]);
    }
    string s2;
    ll f=0;
    fr(i, 0, sz(s1)-1)
    {
        if(s1[i]!=s1[0])
            f=1;
    }
    if(f==0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    fr(i, (n+1)/2, n-1)
    {
        s2.pb(s[i]);
    }
    cout<<solution(s)<<endl;

}