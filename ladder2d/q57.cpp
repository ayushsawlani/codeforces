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
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
ll bin1(ve <ll> &arr, ll x)
{
    ll i=0;
    ll j=sz(arr)-1;
    while(i<j)
    {
        ll mid=(i+j)/2;
        if(arr[mid]<=x)
        {
            i=mid+1;
        }
        else
        {
            j=mid;
        }
    }
    if(arr[i]>x)
    {
        return arr[i];
    }
    return -1;
}
int main()
{
    //fastio
    ll b, d;
    cin>>b>>d;
    string a, c;
    cin>>a>>c;
    ve <ll> temp1(26, 0), temp2(26, 0);
    for(auto j:a)
    {
        temp1[j-'a']++;
    }
    for(auto j:c)
    {
        temp2[j-'a']++;
    }
    fr(i,0, 25)
    {
        if((temp2[i]>0)&&(temp1[i]==0))
        {
            cout<<0<<endl;
            return 0;
        }
    }
    ve <ve <ll>> stora(26, ve <ll> ());
    fr(i, 0, sz(a)-1)
    {
        stora[a[i]-'a'].pb(i);
    }
    ll acou=0;
    ll ccou=0;
    ll cptr=0;
    ll aptr=-1;
    ve <ll> start(sz(a), -1);
    ve <ll> startx(sz(a), -1);
    ll cyclec=-1, initialc=-1;
    ll cyclea=-1, initiala=-1;
    while(acou<b)
    {
        aptr=bin1(stora[c[cptr]-'a'], aptr);
        if(aptr==-1)
        {
            acou++;
            aptr=bin1(stora[c[cptr]-'a'], aptr);
        }
        if(acou==b)
            break;
        if(cptr==0)
        {
            if(start[aptr]==-1)
            {
                start[aptr]=ccou;
                startx[aptr]=acou;
            }
            else
            {
                cyclec=ccou-start[aptr];
                initialc=start[aptr];
                cyclea=acou-startx[aptr];
                initiala=startx[aptr];
                break;
            }            
        }
        cptr++;
        if(cptr==sz(c))
        {
            ccou++;
            cptr=0;
        }
    }
    if(ccou==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(acou==b)
    {
        cout<<ccou/d<<endl;
        return 0;
    }
    //cout<<sz(c)<<" "<<sz(a)<<endl;
    //cout<<initialc<<" "<<cyclec<<endl;
    //cout<<initiala<<" "<<cyclea<<endl;
    ll ans=initialc;
    b-=initiala;
    ans+=(b/cyclea-1)*cyclec;
    b%=cyclea;
    b+=cyclea;
    //cout<<b<<endl;
    acou=0;
    //cout<<ans<<endl;
    while(acou<b)
    {
        if(aptr==-1)
        {
            acou++;
            aptr=bin1(stora[c[cptr]-'a'], aptr);
        }
        if(acou==b)
            break;
        cptr++;
        if(cptr==sz(c))
        {
            ans++;
            cptr=0;
        }
        aptr=bin1(stora[c[cptr]-'a'], aptr);
    }
    cout<<ans/d;
}