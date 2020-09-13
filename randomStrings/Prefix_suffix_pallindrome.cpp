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
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=sz(s);
        ll i=0;
        string ans1, ans2;
        while((s[i]==s[n-i-1])&&(i<n-i-1))
        {
            ans1.pb(s[i]);
            ans2.pb(s[i]);
            i++;
        }
        //cout<<ans1<<endl;
        //cout<<ans2<<endl;
        if(i==n-i-1)
        {
            cout<<s<<endl;
            continue;
        }
        string s1;
        fr(j, i, n-i-1)
        {
            s1.pb(s[j]);
        }
        //cout<<s1<<endl;
        string s2=s1;
        reverse(s2.begin(), s2.end());
        //cout<<s2<<endl;
        string s3=s1+"*"+s2;
        string s4=s2+"*"+s1;
        ve <ll> util1=z_array(s3);
        ve <ll> util2=z_array(s4);
        ll max_i=sz(s3);
        frn(i, sz(s3)-1, sz(s1)+1)
        {
            if(util1[i]+i==sz(s3))
            {
                max_i=i;
            }
        }
        string temp=ans1;
        reverse(temp.begin(), temp.end());
        fr(i, max_i, sz(s3)-1)
        {
            ans1.pb(s3[i]);
        }
        fr(i, 0, sz(temp)-1)
            ans1.pb(temp[i]);
        max_i=sz(s4);
        frn(i, sz(s4)-1, sz(s2)+1)
        {
            if(util2[i]+i==sz(s4))
            {
                max_i=i;
            }
        }
        temp=ans2;
        reverse(temp.begin(), temp.end());
        fr(i, max_i, sz(s4)-1)
        {
            ans2.pb(s4[i]);
        }
        fr(i, 0, sz(temp)-1)
            ans2.pb(temp[i]);
 
        if(sz(ans1)>sz(ans2))
        {
            cout<<ans1<<endl;
        }
        else
        {
            cout<<ans2<<endl;
        }
        
    }
}