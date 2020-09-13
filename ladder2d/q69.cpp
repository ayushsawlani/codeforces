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
    ll n;
    cin>>n;
    map <string, ll> ans;
    while(n--)
    {
        string query;
        cin>>query;
        if(query=="typeof")
        {
            string a;
            cin>>a;
            ll i=0;
            string asli;
            ll s1=0;
            ll s2=0;
            while((a[i]=='&')&&(i<sz(a)))
            {
                i++;
            }
            s1=i;
            while((a[i]!='*')&&(i<sz(a)))
            {
                asli.pb(a[i]);
                i++;
            }
            while(i<sz(a))
            {
                s2++;
                i++;
            }
            if(asli=="void")
            {
                if(s2-s1>=0)
                {
                    cout<<"void";
                    fr(i, 0, s2-s1-1)
                    {
                        cout<<"*";
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<"errtype"<<endl;
                }
            }
            else if(ans.find(asli)==ans.end())
            {
                cout<<"errtype"<<endl;
            }
            else if(ans[asli]+s2-s1<0)
            {
                cout<<"errtype"<<endl;
            }
            else
            {
                cout<<"void";
                fr(i, 0, ans[asli]+s2-s1-1)
                    cout<<"*";
                cout<<endl;
            }
        }
        else
        {
            string a, b;
            cin>>a>>b;
            ll i=0;
            string asli;
            ll s1=0;
            ll s2=0;
            while((a[i]=='&')&&(i<sz(a)))
            {
                i++;
            }
            s1=i;
            while((a[i]!='*')&&(i<sz(a)))
            {
                asli.pb(a[i]);
                i++;
            }
            while(i<sz(a))
            {
                s2++;
                i++;
            }
            if(asli=="void")
            {
                if(s2>=s1)
                {
                    ans[b]=s2-s1;
                }
                else
                {
                    ans.erase(b);   
                }
            }
            else
            {
                if(ans.find(asli)!=ans.end())
                {
                    if(ans[asli]+s2>=s1)
                    {
                        ans[b]=ans[asli]+s2-s1;   
                    }
                    else
                    {
                        ans.erase(b);
                    }
                }
                else
                {
                    ans.erase(b);
                }
                
            }
        }
    }
}