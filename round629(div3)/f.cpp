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
vector <pair <ll,ll>> compress_array(vector <ll> a, ll n)
{
    vector <pair <ll,ll>> ans;
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
    ll n,k;
    cin>>n>>k;
    ve <ll> in(n);
    inarr(i,in,n);
    sort(in.begin(),in.end());
    ve <pair <ll,ll>> compressin=compress_array(in,n);
    ll size=sz(compressin);
    ve <pair <ll,ll>> aagese(size),peechese(size);
    aagese[size-1].first=0;
    aagese[size-1].second=compressin[size-1].second;
    peechese[0].first=0;
    peechese[0].second=compressin[0].second;
    frn(i,size-2,-1)
    {
        aagese[i].first=aagese[i+1].first+aagese[i+1].second*(compressin[i+1].first-compressin[i].first);
        aagese[i].second=aagese[i+1].second+compressin[i].second;
    }
    fr(i,1,size)
    {
        peechese[i].first=peechese[i-1].first+peechese[i-1].second*(compressin[i].first-compressin[i-1].first);
        peechese[i].second=peechese[i-1].second+compressin[i].second;
    }
    ll ans=inf;
    ll j=-1;
    fr(i,0,size)
    {
        if(compressin[i].second>=k)
        {
            cout<<0<<endl;
            return 0;
        }
    } 
    fr(i,0,size)
    {
        if(peechese[i].second>=k)
        {
            j=i;
            break;
        }
        
    }
    if(j==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ans=min(ans,peechese[j].first-(peechese[j].second-k));
    //cout<<j<<" "<<ans<<endl;
    frn(i,size-1,-1)
    {
        if(aagese[i].second>=k)
        {
            j=i;
            break;
        }
    }
    if(j==size-1)
    {
        cout<<0<<endl;
        return 0;
    }
    ans=min(ans,aagese[j].first-(aagese[j].second-k));
   // cout<<j<<" "<<ans<<endl;
    fr(i,0,size)
    {
        ans=min(ans,peechese[i].first+aagese[i].first-(n-k));
     //   cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}