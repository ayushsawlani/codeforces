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
int main()
{
    //fastio
    string s1,s2;
    cin>>s1>>s2;
    ve <ll> fac1,fac2;
    if(sz(s1)>sz(s2))
    {
        string _s;
        swap(s1,s2,_s);
    }
    fr(i,1,(ll)sqrt(s1.size())+1)
    {
        if(s1.size()%i==0)
        { 
            fac1.pb(i);
            if(i!=s1.size()/i)
            {
                fac1.pb(s1.size()/i);
            }
        }
    }
    sort(fac1.begin(),fac1.end());
    fr(i,1,(ll)sqrt(s2.size())+1)
    {
        if(s2.size()%i==0)
        { 
            fac2.pb(i);
            if(i!=s2.size()/i)
            {
                fac2.pb(s2.size()/i);
            }
        }
    }
    sort(fac2.begin(),fac2.end());
    ve <ll> possible;
    ll i=0;ll j=0;
    while((i<sz(fac1))&&(j<sz(fac2)))
    {
        if(fac1[i]<fac2[j])
            i++;
        else if(fac1[i]>fac2[j])
            j++;
        else
        {
            possible.pb(fac1[i]);
            i++;
        }
    }
    ll ans=0;
    fr(i,0,possible.size())
    {
        ll flag=0;
        fr(j,0,s1.size())
        {
            if((s1[j]!=s1[j%possible[i]])||(s1[j]!=s2[j%possible[i]]))
            {
                flag=1;
                break;
            }  
        }
        fr(j,0,s2.size())
        {
            if((s2[j]!=s2[j%possible[i]])||(s2[j]!=s1[j%possible[i]]))
            {
                flag=1;
                break;
            }  
        }
        if(flag==0)
            ans++;
    }
    cout<<ans<<endl;

}