#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
ve <ll> z_array(string s)
{
    ve <ll> ans(s.size());
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
    ll arr[1000001]={0};
    string s;
    cin>>s;
    ve <ll> z=z_array(s);
    ll ans=-1;
    ll len_s=s.size();
    ll greatest =0;
    for(ll i=1;i<s.size();i++)
    {
        if(i+z[i]!=s.size())
            greatest=max(greatest,z[i]);
    }
    for(ll i=1;i<s.size();i++)
    {
        if((i+z[i]==s.size())&&(greatest>=z[i]))
        {
            ans=max(ans,z[i]);
        }
        else
        {
            if(greatest<z[i])
                greatest=z[i];
        }
    }
    if(ans==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        for(ll i=0;i<ans;i++)
            cout<<s[i];
        cout<<endl;
    }



    

}