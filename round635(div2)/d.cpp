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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ll bin1(ll x,vector <ll>&a){
    ll i=0;//starting range
    ll j=sz(a)-1;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j)/2;
        if(a[mid]>=x)
            j=mid;
        else
        {
            i=mid+1;   
        }
    }
    if(a[j]<x)
        return -1;//element does not exist
    return a[j];
}
ll bin2(ll x,vector <ll>&a){
    ll i=0;//starting range
    ll j=sz(a)-1;//ending range
    while(i<j)//not i==j , i==j pe break because range me single element
    {
        ll mid=(i+j+1)/2;
        if(a[mid]>x)
            j=mid-1;
        else
        {
            i=mid;   
        }
    }
    if(a[j]>x)
        return -1;//element does not exist
    return a[j];
}
ll fun(ll a,ll b, ll c)
{
    if(a==-1)
        return inf;
    if(b==-1)
        return inf;
    if(c==-1)
        return inf;
    return (a-b)*(a-b)+(c-b)*(c-b)+(a-c)*(a-c);
}
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n1, n2, n3;
        cin>>n1>>n2>>n3;
        ve<ll> in1(n1),in2(n2),in3(n3);
        inarr(i,in1,n1);
        inarr(i,in2,n2);
        inarr(i,in3,n3);
        sort(in1.begin(),in1.end());
        sort(in2.begin(),in2.end());
        sort(in3.begin(),in3.end());
        ll ans=inf;
        fr(i,0,n1)
        {
            ll arr2[2];
            ll arr3[2];
            arr2[0]=bin1(in1[i],in2);
            arr2[1]=bin2(in1[i],in2);
            arr3[0]=bin1(in1[i],in3);
            arr3[1]=bin2(in1[i],in3);
            fr(j,0,2)
                fr(k,0,2)
                {
                    ans=min(ans,fun(in1[i],arr2[j],arr3[k]));
                    //cout<<fun(in1[i],arr2[j],arr3[k])<<" "<<in1[i]<<" "<<arr2[j]<<" "<<arr3[k]<<endl;
                }
        }
        fr(i,0,n2)
        {
            ll arr2[2];
            ll arr3[2];
            arr2[0]=bin1(in2[i],in1);
            arr2[1]=bin2(in2[i],in1);
            arr3[0]=bin1(in2[i],in3);
            arr3[1]=bin2(in2[i],in3);
            fr(j,0,2)
                fr(k,0,2)
                {
                    ans=min(ans,fun(in2[i],arr2[j],arr3[k]));
                    //cout<<fun(in1[i],arr2[j],arr3[k])<<" "<<in1[i]<<" "<<arr2[j]<<" "<<arr3[k]<<endl;
                }
        }
        fr(i,0,n3)
        {
            ll arr2[2];
            ll arr3[2];
            arr2[0]=bin1(in3[i],in2);
            arr2[1]=bin2(in3[i],in2);
            arr3[0]=bin1(in3[i],in1);
            arr3[1]=bin2(in3[i],in1);
            fr(j,0,2)
                fr(k,0,2)
                {
                    ans=min(ans,fun(in3[i],arr2[j],arr3[k]));
                    //cout<<fun(in1[i],arr2[j],arr3[k])<<" "<<in1[i]<<" "<<arr2[j]<<" "<<arr3[k]<<endl;
                }
        }
        cout<<ans<<endl;

    }
}